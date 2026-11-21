// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/AthenaPlayerInfoBaseWidgetInterface.h"
#include "FortHUDElementWidget.h"
#include "EnergyDrinkStaminaBarOverlayWidget.generated.h"

class AFortPlayerStateAthena;

UCLASS(BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UEnergyDrinkStaminaBarOverlayWidget : public UFortHUDElementWidget, public IAthenaPlayerInfoBaseWidgetInterface
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnPlayerDeadStateChanged(AFortPlayerStateAthena* PlayerState, bool bIsDead);

	UFUNCTION(BlueprintImplementableEvent)
	void OnPlayerStateSet(AFortPlayerStateAthena* InPlayerState);

};

