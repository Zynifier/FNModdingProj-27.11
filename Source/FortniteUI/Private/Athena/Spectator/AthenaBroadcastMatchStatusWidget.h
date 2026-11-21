// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortHUDElementWidget.h"
#include "AthenaBroadcastMatchStatusWidget.generated.h"

class AFortGameState;

UCLASS(Abstract, BlueprintType, Blueprintable)
class UAthenaBroadcastMatchStatusWidget : public UFortHUDElementWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnStormPhaseChanged(int32 StormPhase);

	UFUNCTION(BlueprintImplementableEvent)
	void OnStormPhaseCountChanged(int32 StormPhaseCount);

private:
	UFUNCTION()
	void OnGameStateSet(AFortGameState* InGameState);

	UFUNCTION()
	void OnMapInfoSet();

};

