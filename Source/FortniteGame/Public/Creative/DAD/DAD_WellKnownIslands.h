// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "DataAssetDirectoryPatchableAsset.h"
#include "DAD_WellKnownIslands.generated.h"

USTRUCT(BlueprintType)
struct FDAD_Island
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="DAD_Island")
	FString IslandName;

	UPROPERTY(EditDefaultsOnly, Category="DAD_Island")
	FString IslandCode;

	UPROPERTY(EditDefaultsOnly, Category="DAD_Island")
	FString MetricName;

	UPROPERTY(EditDefaultsOnly, Category="DAD_Island")
	FString MetricInterval;

	UPROPERTY(EditDefaultsOnly, Category="DAD_Island")
	bool bLowestToHighest;

	UPROPERTY(EditDefaultsOnly, Category="DAD_Island")
	int32 Nth;

};

UCLASS()
class UDAD_FeaturedIslands : public UPrimaryDataAsset, public IDataAssetDirectoryPatchableAsset
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly, Category="DAD_FeaturedIslands", meta=(Patchable))
	TArray<FDAD_Island> FeaturedIslandsList;

};

UCLASS()
class UDAD_PlaylistCuratedHub : public UPrimaryDataAsset, public IDataAssetDirectoryPatchableAsset
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly, Category="DAD_PlaylistCuratedHub", meta=(Patchable))
	TMap<FString, FString> PlaylistCuratedHub;

};

UCLASS()
class UDAD_WellKnownIslands : public UPrimaryDataAsset, public IDataAssetDirectoryPatchableAsset
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly, Category="DAD_WellKnownIslands", meta=(Patchable))
	TArray<FDAD_Island> WellKnownIslandsList;

};

