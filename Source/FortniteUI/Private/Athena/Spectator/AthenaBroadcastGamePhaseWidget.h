// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/AthenaGamePhaseWidgetBase.h"
#include "AthenaBroadcastGamePhaseWidget.generated.h"

class AFortMinigame;

UCLASS(BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UAthenaBroadcastGamePhaseWidget : public UAthenaGamePhaseWidgetBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void SetMinigameOverride(AFortMinigame* Minigame);

private:
	UPROPERTY()
	TObjectPtr<AFortMinigame> MinigameOverride;

};

