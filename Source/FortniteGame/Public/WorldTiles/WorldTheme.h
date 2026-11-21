// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "WorldTheme.generated.h"

class UWorld;
class UWorldTileGroup;

USTRUCT()
struct FTileGroupInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="TileGroupInfo")
	TObjectPtr<UWorldTileGroup> TileGroup;

	UPROPERTY(EditAnywhere, Category="TileGroupInfo")
	int32 Weight;

	UPROPERTY(EditAnywhere, Category="TileGroupInfo")
	int32 MinTiles;

	UPROPERTY(EditAnywhere, Category="TileGroupInfo")
	int32 MaxTiles;

	UPROPERTY(EditAnywhere, Category="TileGroupInfo")
	uint8 bPlaceAdjacent : 1;

};

USTRUCT()
struct FTileGroupSelection
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="TileGroupInfo")
	TArray<FTileGroupInfo> TileGroupOptions;

};

UCLASS()
class UWorldTheme : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Theme")
	TArray<FTileGroupSelection> TileGroups;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Theme")
	TObjectPtr<UWorldTileGroup> FillerTileGroup;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Theme")
	int32 MaxCircuitSize;

protected:
	UPROPERTY(EditAnywhere, Category="Borders")
	TSoftObjectPtr<UWorld> BorderWorld_I;

	UPROPERTY(EditAnywhere, Category="Borders")
	TSoftObjectPtr<UWorld> BorderWorld_IO;

	UPROPERTY(EditAnywhere, Category="Borders")
	TSoftObjectPtr<UWorld> BorderWorld_O;

	UPROPERTY(EditAnywhere, Category="Borders")
	TSoftObjectPtr<UWorld> BorderWorld_OO;

	UPROPERTY(EditAnywhere, Category="Borders")
	TSoftObjectPtr<UWorld> BorderWorld_OOO;

	UPROPERTY(EditAnywhere, Category="Borders")
	TSoftObjectPtr<UWorld> BorderWorld_OOOO;

	UPROPERTY(EditAnywhere, Category="Borders")
	TSoftObjectPtr<UWorld> BorderWorld_S;

	UPROPERTY(EditAnywhere, Category="Borders")
	TSoftObjectPtr<UWorld> BorderWorld_SS;

	UPROPERTY(EditAnywhere, Category="Borders")
	TSoftObjectPtr<UWorld> BorderWorld_OS;

	UPROPERTY(EditAnywhere, Category="Borders")
	TSoftObjectPtr<UWorld> BorderWorld_SO;

	UPROPERTY(EditAnywhere, Category="Borders")
	TSoftObjectPtr<UWorld> BorderWorld_SOO;

	UPROPERTY(EditAnywhere, Category="Borders")
	TSoftObjectPtr<UWorld> BorderWorld_U;

	UPROPERTY(EditAnywhere, Category="Borders")
	TSoftObjectPtr<UWorld> BorderWorld_R;

};

