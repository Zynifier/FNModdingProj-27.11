// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortHUDElementWidget.h"
#include "AthenaTeamScoreWidgetBase.generated.h"

class AFortPlayerStateAthena;
class AFortPlayerStateZone;

UCLASS(BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UAthenaTeamScoreWidgetBase : public UFortHUDElementWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION()
	void HandleScoreChanged(int32 Score);

	UFUNCTION()
	void HandleSpectatingChanged(AFortPlayerStateZone* SpectatingTarget);

	UFUNCTION()
	void HandleUpdate();

	UFUNCTION(BlueprintImplementableEvent)
	void OnLeaderboardChanged(int32 ScoreDelta, bool bIsWinner, bool bHasScore);

	UFUNCTION(BlueprintImplementableEvent)
	void OnPlacementChanged(int32 Placement);

	UFUNCTION(BlueprintImplementableEvent)
	void OnScoreChanged(int32 Score);

	UPROPERTY(BlueprintReadOnly, Transient, Category="AthenaTeamScoreWidgetBase")
	TObjectPtr<AFortPlayerStateAthena> CurrPlayerState;

	UPROPERTY(BlueprintReadOnly, Transient, Category="AthenaTeamScoreWidgetBase")
	int32 GoalScore;

	UPROPERTY(BlueprintReadOnly, Transient, Category="AthenaTeamScoreWidgetBase")
	int32 PreviousScore;

	UPROPERTY(BlueprintReadOnly, Transient, Category="AthenaTeamScoreWidgetBase")
	int32 PreviousScorePlacement;

	UPROPERTY(BlueprintReadOnly, Transient, Category="AthenaTeamScoreWidgetBase")
	int32 PreviousDeltaScore;

	UPROPERTY(BlueprintReadOnly, Transient, Category="AthenaTeamScoreWidgetBase")
	bool bPreviousIsWinner;

	UPROPERTY(BlueprintReadOnly, Transient, Category="AthenaTeamScoreWidgetBase")
	bool bPreviousHasScore;

};

