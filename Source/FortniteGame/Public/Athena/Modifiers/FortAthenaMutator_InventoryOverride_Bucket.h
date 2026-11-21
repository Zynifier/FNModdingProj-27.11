// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ScalableFloat.h"
#include "Athena/Modifiers/FortAthenaMutator_InventoryOverride.h"
#include "FortAthenaMutator_InventoryOverride_Bucket.generated.h"

USTRUCT(BlueprintType)
struct FItemLoadoutBucket
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="ItemLoadoutBucket")
	FScalableFloat bEnabled;

	UPROPERTY(EditDefaultsOnly, Category="ItemLoadoutBucket")
	TArray<FItemLoadoutContainer> Loadouts;

};

USTRUCT(BlueprintType)
struct FPlayerBucketSelection
{
	GENERATED_BODY()

};

UCLASS(MinimalAPI, BlueprintType, HideCategories=("Tick", "Replication", "Actor", "LOD", "Cooking", "Mutator", "Inventory", "FortAthenaMutator", "Activation", "Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AFortAthenaMutator_InventoryOverride_Bucket : public AFortAthenaMutator_InventoryOverride
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly, Category="Loadouts")
	TArray<FItemLoadoutBucket> LoadoutBuckets;

};

