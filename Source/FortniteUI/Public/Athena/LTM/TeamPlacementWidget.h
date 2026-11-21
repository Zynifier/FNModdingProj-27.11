// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/LTM/LTMWidgetBase.h"
#include "TeamPlacementWidget.generated.h"

class AFortAthenaMutator_TeamPlacement;
class AFortPlayerStateAthena;

UCLASS(meta=(DisableNativeTick))
class UTeamPlacementWidget : public ULTMWidgetBase
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnPlayerScoringUpdate(const int32 CurrentPlayerTeamScore, const int32 PreviousPlayerTeamScore, const int32 CurrentPlayerTeamPlacement, const int32 PreviousPlayerTeamPlacement, const int32 GoalScore, const TArray<int32>& SortedTeamScores);

	UPROPERTY()
	TWeakObjectPtr<AFortAthenaMutator_TeamPlacement> TeamPlacementMutator;

	UPROPERTY()
	TWeakObjectPtr<AFortPlayerStateAthena> CurrentPlayerState;

};

