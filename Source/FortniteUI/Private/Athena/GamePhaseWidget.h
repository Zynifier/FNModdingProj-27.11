// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortHUDElementWidget.h"
#include "GamePhaseWidget.generated.h"

class AFortMinigame;
enum class EFortMinigameState : uint8;

UCLASS(meta=(DisableNativeTick))
class UGamePhaseWidget : public UFortHUDElementWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void MinigameStateChangedEvent(const AFortMinigame* Minigame, const EFortMinigameState NewMinigameState);

	UFUNCTION(BlueprintImplementableEvent)
	void OnMinigameReady(AFortMinigame* Minigame);

	UFUNCTION()
	virtual void OnMinigameStateChanged(AFortMinigame* Minigame, EFortMinigameState NewMinigameState);

};

