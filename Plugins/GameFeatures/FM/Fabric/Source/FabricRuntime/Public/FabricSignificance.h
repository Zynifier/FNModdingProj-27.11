// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "FabricSignificance.generated.h"

class UObject;

USTRUCT(BlueprintType)
struct FFabricSignificanceBasedUpdateBucket
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="FabricSignificanceBasedUpdateBucket")
	float MinDistanceFromPlayer;

	UPROPERTY(EditDefaultsOnly, Category="FabricSignificanceBasedUpdateBucket")
	float MaxDistanceFromPlayer;

	UPROPERTY(EditDefaultsOnly, Category="FabricSignificanceBasedUpdateBucket")
	float FramesPerUpdate;

	UPROPERTY(EditDefaultsOnly, Category="FabricSignificanceBasedUpdateBucket")
	int32 MaxObjectsInBucket;

};

USTRUCT()
struct FFabricSignificanceBasedUpdateBucketRuntimeGroup
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TArray<TWeakObjectPtr<UObject>> ObjectsInGroup;

};

USTRUCT()
struct FFabricSignificanceBasedUpdateBucketRuntime
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	float ActualMinSignificance;

	UPROPERTY(Transient)
	float ActualMaxSignificance;

	UPROPERTY(Transient)
	int32 ActualMaxObjectsInBucket;

	UPROPERTY(Transient)
	int32 ActualFramesPerUpdate;

	UPROPERTY(Transient)
	int32 TotalObjectsInBucketCount;

	UPROPERTY(Transient)
	TArray<FFabricSignificanceBasedUpdateBucketRuntimeGroup> UpdateGroups;

};

UCLASS(BlueprintType, Blueprintable)
class UFabricSignificanceAsset : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="FabricSignificanceAsset")
	TArray<FFabricSignificanceBasedUpdateBucket> UpdateBuckets;

};

