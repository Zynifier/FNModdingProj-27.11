// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "FortStatsPageManager.generated.h"

USTRUCT(BlueprintType)
struct FCarrerRankData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="CarrerRankData")
	int32 HighestRank;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="CarrerRankData")
	FString LastSeasonAcquired;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="CarrerRankData")
	FString RankType;

};

USTRUCT(BlueprintType)
struct FStatPageData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="StatPageData")
	FString SeasonName;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="StatPageData")
	bool bIsRanked;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="StatPageData")
	FString GameMode;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="StatPageData")
	FString SubMode;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="StatPageData")
	FString RankType;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="StatPageData")
	int32 CurrentRank;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="StatPageData")
	int32 HighestRank;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="StatPageData")
	int32 CurrentPlayerPosition;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="StatPageData")
	FCarrerRankData CarrerRankData;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="StatPageData")
	int32 MatchesPlayed;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="StatPageData")
	int32 TopMatchPositionFirstStat;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="StatPageData")
	int32 TopMatchPositionSecondStat;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="StatPageData")
	int32 TopMatchPositionThirdStat;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="StatPageData")
	int32 Eliminations;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="StatPageData")
	FText FirstStatPercentage;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="StatPageData")
	FText SecondStatPercentage;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="StatPageData")
	FText ThirdStatPercentage;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="StatPageData")
	int32 AvgEliminations;

};

UCLASS()
class UFortStatsPageManager : public UWorldSubsystem
{
	GENERATED_BODY()

};

