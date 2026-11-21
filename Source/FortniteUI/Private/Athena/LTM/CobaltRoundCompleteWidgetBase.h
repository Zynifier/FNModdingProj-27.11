// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/LTM/CobaltWidgetBase.h"
#include "CobaltRoundCompleteWidgetBase.generated.h"

UCLASS()
class UCobaltRoundCompleteWidgetBase : public UCobaltWidgetBase
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void HideDisplay();

	UFUNCTION()
	void HideWidget();

	UFUNCTION()
	void OnRoundComplete(const TArray<uint8>& winningTeams);

	UFUNCTION(BlueprintImplementableEvent)
	void ShowDisplay(bool bIsWin, bool bWasTie, bool bViewingWidgetOwner, int32 RoundNum, const FText& RoundName, const FText& POIName, int32 PrimaryTeamScore, int32 OpposingTeamScore);

};

