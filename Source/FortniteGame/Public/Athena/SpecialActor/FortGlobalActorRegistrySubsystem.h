// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GameplayTagContainer.h"
#include "Subsystems/WorldSubsystem.h"
#include "UObject/NoExportTypes.h"
#include "FortGlobalActorRegistrySubsystem.generated.h"

class AActor;
class UActorRegisterData_ActorBased;
class UActorRegisterData_GameplayTagBased;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FActorRegisterActorRegistered, const FGameplayTag&, GameplayTag, AActor*, RegisteredActor);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FActorRegisterActorUnregistered, const FGameplayTag&, GameplayTag, AActor*, UnregisteredActor);

UCLASS(BlueprintType)
class UActorRegisterData_ActorBased : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	TObjectPtr<AActor> RegisteredActor;

};

UCLASS(BlueprintType)
class UActorRegisterData_GameplayTagBased : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, BlueprintAuthorityOnly)
	FGameplayTag GetGameplayTag() const;

	UFUNCTION(BlueprintPure, BlueprintAuthorityOnly)
	const TArray<AActor*>& GetRegisteredActors() const;

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	void HandleListenerRemoved();

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	void RemoveIfNotUsed();

	UPROPERTY(BlueprintAssignable)
	FActorRegisterActorRegistered OnActorRegistered;

	UPROPERTY(BlueprintAssignable)
	FActorRegisterActorUnregistered OnActorUnregistered;

private:
	UFUNCTION()
	void RegisteredActorDestroyed(AActor* DestroyedActor);

	UPROPERTY(Transient)
	TArray<TObjectPtr<AActor>> RegisteredActors;

};

UCLASS(MinimalAPI, meta=(BlueprintSpawnableComponent))
class UFortAutoRegisterActorComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortAutoRegisterActorComponent")
	FGameplayTagContainer ActorRegistrationTags;

};

UCLASS(MinimalAPI, BlueprintType)
class UFortGlobalActorRegistrySubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	UActorRegisterData_GameplayTagBased* GetActorRegistryDataForGameplayTag(const FGameplayTag& GameplayTag);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	void GetRegisteredActors(TArray<AActor*>& OutActors, const FGameplayTag& GameplayTag);

	UFUNCTION(BlueprintPure, BlueprintAuthorityOnly)
	const TArray<FGameplayTag> GetRegistrationTagsForActor(const AActor* InActor) const;

	UFUNCTION(BlueprintCallable, BlueprintPure=false, BlueprintAuthorityOnly, meta=(DevelopmentOnly))
	void LogActorRegistration() const;

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	void RegisterActor(const FGameplayTag& GameplayTag, AActor* InActor);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	void RegisterActors(const FGameplayTag& GameplayTag, const TArray<AActor*>& InActors);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	void RegisterActorsWithMultipleGameplayTags(const TArray<FGameplayTag>& GameplayTags, const TArray<AActor*>& InActors);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	void UnregisterActor(const FGameplayTag& GameplayTag, AActor* InActor);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	void UnregisterActors(const FGameplayTag& GameplayTag, const TArray<AActor*>& InActors);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	void UnregisterActorsFromAllGameplayTags(const TArray<AActor*>& InActors);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	void UnregisterActorsWithMultipleGameplayTags(const TArray<FGameplayTag>& GameplayTags, const TArray<AActor*>& InActors);

private:
	UPROPERTY(Transient)
	TMap<FGameplayTag, UActorRegisterData_GameplayTagBased*> ActorRegistrationDataByGameplayTagMap;

	UPROPERTY(Transient)
	TMap<TObjectPtr<AActor>, TObjectPtr<UActorRegisterData_ActorBased>> ActorRegistrationDataByActorMap;

};

