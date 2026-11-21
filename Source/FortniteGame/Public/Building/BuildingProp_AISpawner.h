// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "Building/BuildingProp.h"
#include "BuildingProp_AISpawner.generated.h"

class AAthenaCreativeRift;
class ABuildingRift;
class AController;
class AFortAIPawn;
class UFortCreativeCreatureManagerComponent;
class UFortMinigameProgressComponent;
class UPrimitiveComponent;
class USceneComponent;

UCLASS(HideCategories=("Game|Damage"), PrioritizeCategories=("Instance"), SparseClassDataType=BuildingPropActorClassData)
class ABuildingProp_AISpawner : public ABuildingProp
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void AdjustCollision(bool bIgnore, UPrimitiveComponent* Collision);

	UFUNCTION(BlueprintImplementableEvent)
	void BP_NotifyAIPawnKilled(const AFortAIPawn* KilledAI, AController* KillingInstigator);

	UFUNCTION(BlueprintImplementableEvent)
	void BP_NotifyAIPawnSpawned(AFortAIPawn* SpawnedAI, const FVector& SpawnSlotLocation);

	UFUNCTION(BlueprintCallable)
	virtual void DestroyRift();

	UFUNCTION(BlueprintNativeEvent)
	void MinigameEnded();

	UFUNCTION(BlueprintImplementableEvent)
	void OnSpawnedRift(ABuildingRift* SpawnedRift);

	UFUNCTION(BlueprintCallable)
	void SetSpawnLocation(USceneComponent* SpawnLocation);

	UFUNCTION(BlueprintCallable)
	void SpawnRift();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="BuildingProp_AISpawner")
	TSubclassOf<AAthenaCreativeRift> CreativeRiftClass;

protected:
	UPROPERTY(BlueprintReadWrite, Export, Category="BuildingProp_AISpawner", meta=(EditInline="true"))
	TObjectPtr<UFortCreativeCreatureManagerComponent> CreatureManagerComponent;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Export, Category="BuildingProp_AISpawner", meta=(EditInline="true"))
	TObjectPtr<UFortMinigameProgressComponent> MinigameProgress;

	UPROPERTY(Transient)
	TObjectPtr<AAthenaCreativeRift> CreativeRift;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<USceneComponent> SpawnLocation;

	UPROPERTY(BlueprintReadWrite, Category="BuildingProp_AISpawner")
	float ActivationRangeLevel;

	UPROPERTY(BlueprintReadWrite, Category="BuildingProp_AISpawner")
	bool bCanAIDespawnWhenTooFar;

	UPROPERTY(BlueprintReadWrite, Category="BuildingProp_AISpawner")
	bool bUseDistanceToAI;

	UPROPERTY(BlueprintReadWrite, Category="BuildingProp_AISpawner")
	float DespawnRangeOverride;

};

