// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/LTM/MinigameWidgetBase.h"
#include "Minigame/FortMinigame.h"
#include "FortCoreGamerScoreTracker.generated.h"

class AFortPlayerState;
class APlayerState;
class UFortCoreGamerScoreTrackerRow;

USTRUCT(BlueprintType)
struct FCoreGamerRankingInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="CoreGamerRankingInfo")
	int32 Score;

	UPROPERTY(BlueprintReadOnly, Category="CoreGamerRankingInfo")
	FText Name;

};

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortCoreGamerScoreTracker : public UMinigameWidgetBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	int32 GetGoalScore() const;

	UFUNCTION(BlueprintPure)
	int32 GetHighestOpposingTeamIndex() const;

	UFUNCTION(BlueprintPure)
	int32 GetLocalTeamIndex() const;

	UFUNCTION(BlueprintPure)
	TArray<FCoreGamerRankingInfo> GetRankings(int32& OutLocalRankingArrayIndex) const;

	UFUNCTION(BlueprintPure)
	int32 GetScoreForPlayer(const APlayerState* InPlayerState) const;

	UFUNCTION(BlueprintPure)
	int32 GetScoreForTeam(const int32 InTeamIndex) const;

	UFUNCTION(BlueprintPure)
	void GetTeamData(int32 DesiredTeamIndex, FMinigameTeam& OutTeam, bool& bFoundTeam) const;

	UFUNCTION(BlueprintPure)
	FText GetTeamName(const int32 InTeamIndex) const;

	UFUNCTION(BlueprintPure)
	FText GetTeamNameForPlayerState(const AFortPlayerState* PlayerState) const;

	UFUNCTION(BlueprintPure)
	FText GetTimeRemainingText(bool& bHasTimeLimit) const;

	UFUNCTION(BlueprintImplementableEvent)
	void OnSeparatorVisibilitySet(const bool bVisible);

	UFUNCTION(BlueprintImplementableEvent)
	void OnUpdate();

	UFUNCTION(BlueprintCallable)
	void PopulateTeamRows(TArray<UFortCoreGamerScoreTrackerRow*> ScoreTrackerRows);

};

