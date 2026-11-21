// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "ScalableFloat.h"
#include "Athena/Modifiers/FortAthenaMutator.h"
#include "Athena/Modifiers/FortAthenaMutator_EQSProviderInterface.h"
#include "FortAthenaMutator_SupplyDrop.generated.h"

class UEnvQuery;

USTRUCT()
struct FFortItemDeliverySupplyDropMutatorData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="FortItemDeliverySupplyDropMutatorData")
	bool bShouldApplyMutator;

	UPROPERTY(EditDefaultsOnly, Category="FortItemDeliverySupplyDropMutatorData")
	FScalableFloat NumDeliveryItemsToSpawn;

	UPROPERTY(EditDefaultsOnly, Category="FortItemDeliverySupplyDropMutatorData")
	TObjectPtr<UEnvQuery> SupplyDropPlacementQuery;

};

USTRUCT()
struct FFortSupplyDropMutatorData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="FortSupplyDropMutatorData")
	FName SupplyDropID;

	UPROPERTY(EditDefaultsOnly, Category="FortSupplyDropMutatorData")
	bool bShouldCenterGroundCheckAtFoundLocation;

	UPROPERTY(EditDefaultsOnly, Category="FortSupplyDropMutatorData")
	TArray<FFortItemDeliverySupplyDropMutatorData> ItemDeliveryMutatorPerSafeZonePhase;

};

UCLASS(BlueprintType, HideCategories=("Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AFortAthenaMutator_SupplyDrop : public AFortAthenaMutator, public IFortAthenaMutator_EQSProviderInterface
{
	GENERATED_BODY()

public:
	UFUNCTION()
	void RemoveOutOfStormSupplyDrop();

protected:
	UPROPERTY(EditDefaultsOnly, Category="FortAthenaMutator_SupplyDrop")
	FScalableFloat SpawnFailureLockoutTime;

	UPROPERTY(EditDefaultsOnly, Category="FortAthenaMutator_SupplyDrop")
	TObjectPtr<UEnvQuery> BasePlacementQuery;

	UPROPERTY(EditDefaultsOnly, Category="FortAthenaMutator_SupplyDrop")
	float BaseQueryingAttemptIntervalTimeSeconds;

	UPROPERTY(EditDefaultsOnly, Category="FortAthenaMutator_SupplyDrop")
	TArray<FFortSupplyDropMutatorData> SafeZoneMutatorData;

	UPROPERTY(Transient)
	TArray<FVector> BaseQueryResults;

	UPROPERTY(EditDefaultsOnly, Category="FortAthenaMutator_SupplyDrop")
	TSoftObjectPtr<UEnvQuery> SupplyDropRemovalQuery;

	UPROPERTY(EditDefaultsOnly, Category="FortAthenaMutator_SupplyDrop", meta=(ClampMin="0.000000", UIMin="0.000000"))
	float SupplyDropRemovalQueryInterval;

};

