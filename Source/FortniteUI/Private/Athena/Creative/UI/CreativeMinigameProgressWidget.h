// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "ScalableFloat.h"
#include "Components/FortControllerComponent_MinigameActivity.h"
#include "CreativeMinigameProgressWidget.generated.h"

class AFortPlayerStateAthena;

UCLASS(Abstract, meta=(DisableNativeTick))
class UCreativeMinigameProgressWidget : public UCommonUserWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="On Handle Minigame Ended"))
	void BP_OnHandleMinigameEnded(const FMinigameActivityEndedData& EndData);

	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="On Handle Minigame Started"))
	void BP_OnHandleMinigameStarted(const FMinigameActivityStartedData& StartData);

	UFUNCTION(BlueprintImplementableEvent)
	void OnPlayerScoringUpdate(const int32 CurrentPlayerTeamScore, const int32 PreviousPlayerTeamScore, const int32 CurrentPlayerTeamPlacement, const int32 PreviousPlayerTeamPlacement, const int32 GoalScore, const TArray<int32>& SortedTeamScores);

	UFUNCTION(BlueprintImplementableEvent)
	void OnPlayerStatUpdate(const int32 CurrentPlayerTeamScore, const int32 CurrentPlayerTeamPlacement, const int32 GoalScore, const TArray<int32>& SortedTeamStats);

	UPROPERTY()
	TWeakObjectPtr<AFortPlayerStateAthena> CurrentPlayerState;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="EnableDisable")
	FScalableFloat bEnabled;

private:
	UPROPERTY(BlueprintReadOnly, Category="CreativeMinigameProgressWidget", meta=(AllowPrivateAccess))
	bool bMinigameActive;

};

