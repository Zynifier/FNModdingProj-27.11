// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Athena/Modifiers/FortAthenaMutator.h"
#include "FortAthenaMutator_WeaponTraceIgnoreActors.generated.h"

class AActor;
class AFortPawn;
class AFortWeapon;

UCLASS(BlueprintType, HideCategories=("Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AFortAthenaMutator_WeaponTraceIgnoreActors : public AFortAthenaMutator
{
	GENERATED_BODY()

};

UCLASS(BlueprintType, Blueprintable, HideCategories=("Activation", "AssetUserData", "Collision", "ComponentReplication", "ComponentTick", "Cooking", "Replication"), meta=(BlueprintSpawnableComponent))
class UFortWeaponTraceIgnoreActorsComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void AddIgnoreActorClasses(const TArray<TSubclassOf<AActor>>& InActorClasses);

	UFUNCTION(BlueprintCallable)
	void AddIgnoreActors(const TArray<AActor*>& InActors);

	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="GetAdditionalIgnoreActors"))
	void BP_GetAdditionalIgnoreActors(TArray<AActor*>& OutAdditionalActors, TArray<TSubclassOf<AActor>>& OutAdditionalActorClasses, const AFortPawn* OwningPawn, const AFortWeapon* Weapon) const;

	UFUNCTION(BlueprintCallable)
	void RemoveIgnoreActorClasses(const TArray<TSubclassOf<AActor>>& InActorClasses);

	UFUNCTION(BlueprintCallable)
	void RemoveIgnoreActors(const TArray<AActor*>& InActors);

	UFUNCTION(BlueprintCallable)
	void ResetAdditionalIgnoreActorClasses(const bool bUseDefaults = true);

	UFUNCTION(BlueprintCallable)
	void ResetAdditionalIgnoreActors();

protected:
	UPROPERTY(BlueprintReadOnly, Category="FortWeaponTraceIgnoreActorsComponent")
	TArray<TObjectPtr<AActor>> AdditionalIgnoreActors;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortWeaponTraceIgnoreActorsComponent")
	TArray<TSubclassOf<AActor>> DefaultAdditionalIgnoreActorClasses;

	UPROPERTY(BlueprintReadOnly, Category="FortWeaponTraceIgnoreActorsComponent")
	TArray<TSubclassOf<AActor>> AdditionalIgnoreActorClasses;

};

