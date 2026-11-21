// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Commandlets/Commandlet.h"
#include "FortAssetOrderCommandlet.generated.h"

class UAthenaMapPreloadData;

UENUM()
enum class EFoundationOrdering : uint8
{
	MST = 0,
	// Minimum spanning tree by distance between foundation centers

	MSTOverlap = 1,
	// Minimum spanning tree where edge weight is the negation of the area of the overlap of foundation streaming areas

	Radial = 2,
	// Radial from start point (e.g. lobby island)

	RadialByDepth = 3,
	// Radial from start poing (e.g. lobby island) in multiple passes by depth (parent-child relationsip)

	GridWalk = 4,
	// Walk the grid by rows and columns

	GridWalkSnake = 5,
	// Walk the grid by rows and columns, alternating direction

	GridWalkSpiral = 6,
	// Walk the grid spiralling towards the center (prioritizes placing foundations on the edge of the island together first)

	ZOrderCurve = 7,
	// Walk the grid in a Z-order/Morton curve

	SkydivePaths = 8,
};

USTRUCT()
struct FAssetBundleFilter
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FName PrimaryAssetTypeName;

	UPROPERTY()
	FName AssetBundleName;

};

USTRUCT()
struct FFoundationOrderOptions
{
	GENERATED_BODY()

public:
	UPROPERTY(Config)
	bool bInterleaveOverlays;

	UPROPERTY(Config)
	TMap<FString, bool> PlatformInterleaveOverlays;

	UPROPERTY(Config)
	bool bInterleaveGameplayCues;

	UPROPERTY(Config)
	TMap<FString, bool> PlatformInterleaveGameplayCues;

	UPROPERTY(Config)
	bool bInterleaveDeathParticles;

	UPROPERTY(Config)
	TMap<FString, bool> PlatformInterleaveDeathParticles;

};

UCLASS(Config=Editor)
class UFortAssetOrderCommandlet : public UCommandlet
{
	GENERATED_BODY()

public:
	UPROPERTY(Config)
	FString DefaultMapName;

	UPROPERTY(Config)
	FString DefaultFoundationStartNode;

	UPROPERTY(Config)
	FString DefaultFoundationOrdering;

	UPROPERTY(Config)
	int32 GridWalkSteps;

	UPROPERTY(Config)
	TSoftObjectPtr<UAthenaMapPreloadData> PreloadDataAsset;

	UPROPERTY(Config)
	FString DefaultPlatforms;

	UPROPERTY(Config)
	TArray<FAssetBundleFilter> IgnoreAssetBundles;

	UPROPERTY(Config)
	TArray<FName> PriorityPrimaryAssetTypes;

	UPROPERTY(Config)
	TArray<FAssetBundleFilter> PriorityAssetBundles;

	UPROPERTY(Config)
	FFoundationOrderOptions FoundationOptions;

};

