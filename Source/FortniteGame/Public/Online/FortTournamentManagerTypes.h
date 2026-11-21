// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "FortTournamentManagerTypes.generated.h"

UENUM()
enum class EPayoutRewardType : uint8
{
	Invalid = 0,
	Commerce = 1,
	//Real cash

	GameRelated = 2,
	Token = 3,
	Score = 4,
};

UENUM()
enum class EPayoutScoringType : uint8
{
	Invalid = 0,
	Points = 1,
	Ranking = 2,
	Percentile = 3,
	Persistent = 4,
};

UENUM()
enum class EScoreMatchOperator : uint8
{
	Invalid = 0,
	LessThan = 1,
	LessThanOrEqual = 2,
	Equal = 3,
	GreaterThan = 4,
	GreaterThanOrEqual = 5,
};

UENUM(BlueprintType)
enum class ETournamentDisplayType : uint8
{
	Default = 0,
	Creative = 1,
};

USTRUCT(BlueprintType)
struct FFortShowdownScoringRuleInfo : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="FortShowdownScoringRuleInfo")
	FName DisplayInfoId;

	UPROPERTY(BlueprintReadOnly, Category="FortShowdownScoringRuleInfo")
	int32 PointValue;

	UPROPERTY(BlueprintReadOnly, Category="FortShowdownScoringRuleInfo")
	int32 AccumulatedPointValue;

	UPROPERTY(BlueprintReadOnly, Category="FortShowdownScoringRuleInfo")
	int32 ScoreRequirement;

	UPROPERTY(BlueprintReadOnly, Category="FortShowdownScoringRuleInfo")
	int32 UpperBoundRequirement;

	UPROPERTY(BlueprintReadOnly, Category="FortShowdownScoringRuleInfo")
	int32 LowerBoundRequirement;

};

USTRUCT()
struct FTournamentPayoutItemData
{
	GENERATED_BODY()

};

USTRUCT()
struct FTournamentPayoutThresholdData
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TArray<FTournamentPayoutItemData> PayoutItemsData;

};

USTRUCT()
struct FTournamentLeaderboardPayoutTableData
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TArray<FTournamentPayoutThresholdData> PayoutThresholdsData;

};

