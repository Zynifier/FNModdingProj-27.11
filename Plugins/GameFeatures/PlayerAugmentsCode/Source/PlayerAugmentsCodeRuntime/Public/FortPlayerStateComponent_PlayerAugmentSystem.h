// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ActiveGameplayEffectHandle.h"
#include "GameplayTagContainer.h"
#include "ScalableFloat.h"
#include "UObject/PrimaryAssetId.h"
#include "Abilities/FortAbilitySetHandle.h"
#include "Components/FortPlayerStateComponent.h"
#include "FortPlayerStateComponent_PlayerAugmentSystem.generated.h"

class AActor;
class AFortAthenaAIBotController;
class AFortPlayerPawnAthena;
class UFortPlayerAugmentItemDefinition;
class UFortPlayerStateComponent_PlayerAugmentSystem;
class UGameplayEffect;
enum class EAugmentExecResult : uint8;

UENUM(BlueprintType)
enum class EAugmentExecResult : uint8
{
	Success = 0,
	Failure = 1,
};

USTRUCT()
struct FPlayerAugmentAbilitySetHandlesStackEntry
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	TArray<FFortAbilitySetHandle> AbilitySetHandles;

};

USTRUCT()
struct FPlayerAugmentGameplayEffectHandlesStackEntry
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	TArray<FActiveGameplayEffectHandle> GEHandles;

};

USTRUCT()
struct FPlayerAugmentTrackedData
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	TArray<FPlayerAugmentAbilitySetHandlesStackEntry> AbilitySetHandlesStack;

	UPROPERTY(Transient)
	TArray<FPlayerAugmentGameplayEffectHandlesStackEntry> GEHandlesStack;

};

UCLASS(MinimalAPI, BlueprintType, Blueprintable, HideCategories=("Trigger", "PhysicsVolume"))
class UFortPlayerStateComponent_PlayerAugmentSystem : public UFortPlayerStateComponent
{
	GENERATED_BODY()

public:
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnAugmentListUpdatedEventDispatcher, UFortPlayerStateComponent_PlayerAugmentSystem*, AugmentComponent);

public:
	UFUNCTION(Client, Reliable)
	void ClientClearMatchAugmentDataCache();

	UFUNCTION(BlueprintCallable)
	static TArray<UFortPlayerAugmentItemDefinition*> GetActiveAugments(AActor* Actor);

	UFUNCTION(BlueprintPure)
	static UFortPlayerStateComponent_PlayerAugmentSystem* GetAugmentComponent(const AActor* PlayerContextActor);

	UFUNCTION(BlueprintCallable, meta=(ExpandEnumAsExecs="OutExec"))
	static UFortPlayerStateComponent_PlayerAugmentSystem* GetAugmentComponentValidated(EAugmentExecResult& OutExec, const AActor* PlayerContextActor);

	UFUNCTION(BlueprintCallable, meta=(ExpandEnumAsExecs="OutExec"))
	double GetAugmentMatchDataCacheFloat(EAugmentExecResult& OutExec, FGameplayTag TargetAugmentCacheTag);

	UFUNCTION(BlueprintCallable)
	void SetAugmentMatchDataCacheFloat(FGameplayTag TargetAugmentCacheTag, double InData);

	UPROPERTY(BlueprintAssignable)
	FOnAugmentListUpdatedEventDispatcher OnAugmentListUpdated;

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortPlayerStateComponent_PlayerAugmentSystem")
	FScalableFloat EnableAugmentsFeature;

private:
	UFUNCTION()
	void HandleBotPlayerPawnSpawned(AFortAthenaAIBotController* BotController, AFortPlayerPawnAthena* BotPawn);

	UFUNCTION()
	void HandlePlayerPawnSpawned();

	UFUNCTION()
	void OnRep_ActiveAugments();

	UPROPERTY(EditDefaultsOnly, Category="FortPlayerStateComponent_PlayerAugmentSystem")
	TSubclassOf<UGameplayEffect> DynamicTagGEClass;

	UPROPERTY(Transient)
	TMap<FPrimaryAssetId, FPlayerAugmentTrackedData> AugmentToRuntimeDataMap;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_ActiveAugments)
	TArray<TObjectPtr<UFortPlayerAugmentItemDefinition>> ActiveAugments;

	UPROPERTY(Transient)
	TMap<FGameplayTag, double> RuntimeAugmentMatchDataCacheFloat;

};

