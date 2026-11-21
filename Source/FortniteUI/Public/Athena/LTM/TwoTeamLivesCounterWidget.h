// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/LTM/LTMWidgetBase.h"
#include "Athena/LTM/TwoTeamScoreWidgetBase.h"
#include "TwoTeamLivesCounterWidget.generated.h"

class AFortPlayerStateAthena;

UCLASS(MinimalAPI, BlueprintType, Blueprintable)
class UTwoTeamLivesCounterWidget : public ULTMWidgetBase
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnEnemyTeamScoreUpdated(FTDMTeamScoreData ScoreData);

	UFUNCTION(BlueprintImplementableEvent)
	void OnFriendlyTeamScoreUpdated(FTDMTeamScoreData ScoreData);

	UFUNCTION(BlueprintImplementableEvent)
	void OnLivesCountUpdated(int32 LocalLivesCount, int32 EnemyLivesCount);

	UFUNCTION()
	void OnPlayerDied(AFortPlayerStateAthena* DeadPlayer);

	UPROPERTY(BlueprintReadOnly, Category="TwoTeamLivesCounterWidget")
	TObjectPtr<AFortPlayerStateAthena> CurrentPlayerState;

};

