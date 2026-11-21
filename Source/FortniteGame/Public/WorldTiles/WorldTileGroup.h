// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "WorldTileGroup.generated.h"

class UWorld;

USTRUCT(BlueprintType)
struct FTileGroupMapInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="TileGroupMaps")
	float Weight;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="TileGroupMaps")
	FName QuotaCategory;

private:
	UPROPERTY(EditAnywhere, Category="TileGroupMaps")
	TSoftObjectPtr<UWorld> GroupWorld;

};

UCLASS(MinimalAPI)
class UWorldTileGroup : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Base")
	FString TileID;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Base")
	uint8 bOnlyPlaceDiagonalWithAdjacent : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="TileGroupMaps")
	TArray<FTileGroupMapInfo> FlatMapInfos;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="TileGroupMaps")
	TArray<FTileGroupMapInfo> InnerMapInfos;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="TileGroupMaps")
	TArray<FTileGroupMapInfo> OuterMapInfos;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="TileGroupMaps")
	TArray<FTileGroupMapInfo> StraightMapInfos;

protected:
	UPROPERTY(EditAnywhere, Category="SimulateMaps")
	TSoftObjectPtr<UWorld> Sim_FlatWorld;

	UPROPERTY(EditAnywhere, Category="SimulateMaps")
	TSoftObjectPtr<UWorld> Sim_InnerWorld;

	UPROPERTY(EditAnywhere, Category="SimulateMaps")
	TSoftObjectPtr<UWorld> Sim_OuterWorld;

	UPROPERTY(EditAnywhere, Category="SimulateMaps")
	TSoftObjectPtr<UWorld> Sim_StraightWorld;

};

