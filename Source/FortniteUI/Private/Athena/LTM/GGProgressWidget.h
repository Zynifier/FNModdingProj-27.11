// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/LTM/LTMWidgetBase.h"
#include "FortTypes.h"
#include "GGProgressWidget.generated.h"

UCLASS(BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UGGProgressWidget : public ULTMWidgetBase
{
	GENERATED_BODY()

protected:
	UFUNCTION()
	void OnLeaderboardUpdate(const TArray<FFortInGameLeaderboardPlacementData>& Data);

	UFUNCTION(BlueprintImplementableEvent)
	void OnPlayerNearGoal(const FFortInGameLeaderboardPlacementData& PlayerNearGoal);

	UFUNCTION(BlueprintImplementableEvent)
	void UpdateLocalPlayer(const FFortInGameLeaderboardPlacementData& LocalPlayer);

	UFUNCTION(BlueprintImplementableEvent)
	void UpdateTopThreeEnemies(const TArray<FFortInGameLeaderboardPlacementData>& TopThreeEnemies);

	UPROPERTY(EditAnywhere, Category="GGProgressWidget")
	int32 PointsToGoalThreshold;

	UPROPERTY()
	TArray<FFortInGameLeaderboardPlacementData> TopPlacedEnemies;

};

