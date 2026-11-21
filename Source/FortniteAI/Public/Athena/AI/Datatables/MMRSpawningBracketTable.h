// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "MMRSpawningBracketTable.generated.h"

class UFortAthenaAISpawnerData;

USTRUCT()
struct FMMRSpawningDataTableInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Tables Info")
	TSubclassOf<UFortAthenaAISpawnerData> AISpawnerData;

	UPROPERTY(EditAnywhere, Category="Tables Info")
	float Skill;

	UPROPERTY(EditAnywhere, Category="Tables Info")
	float Weight;

	UPROPERTY(EditAnywhere, Category="Tables Info")
	int32 SpawingItemIndex;

};

USTRUCT()
struct FMMRPhaseSpawningDataTableInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Tables Info")
	int32 GamePhaseIndexToSpawn;

	UPROPERTY(EditAnywhere, Category="Tables Info")
	TArray<FMMRSpawningDataTableInfo> SpawningItems;

};

USTRUCT()
struct FMMRSpawningBaseRuntimeInfo
{
	GENERATED_BODY()

};

USTRUCT()
struct FMMRSpawningBracketBaseDataTableRow : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Tables Info")
	int32 MMRBracketLow;

	UPROPERTY(EditAnywhere, Category="Tables Info")
	int32 MMRBracketHigh;

};

USTRUCT()
struct FMMRSpawningBracketBotDataTableRow : public FMMRSpawningBracketBaseDataTableRow
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Tables Info")
	TArray<FMMRPhaseSpawningDataTableInfo> PhaseSpawningItems;

};

