// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "CheckDismissableActivatableWidget.h"
#include "FortGameplayCinematicWidget.generated.h"

UCLASS(Config=Game)
class SPECIALEVENTGAMEPLAYUI_API UFortGameplayCinematicWidget : public UCommonActivatableWidget, public ICheckDismissableActivatableWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintCallable)
	void OnCinematicFinished();

	UFUNCTION(BlueprintImplementableEvent)
	void OnStartCinematic();

	UPROPERTY(Config)
	bool bSkipCinematics;

};

