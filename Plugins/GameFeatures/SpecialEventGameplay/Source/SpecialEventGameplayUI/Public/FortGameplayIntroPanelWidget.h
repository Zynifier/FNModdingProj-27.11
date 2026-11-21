// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "FortGameplayIntroPanelWidget.generated.h"

UCLASS(meta=(DisableNativeTick))
class SPECIALEVENTGAMEPLAYUI_API UFortGameplayIntroPanelWidget : public UCommonActivatableWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintCallable)
	void OnIntroFinished();

	UFUNCTION(BlueprintImplementableEvent)
	void OnStartIntro();

	UFUNCTION(BlueprintImplementableEvent)
	void OnWaitingForMinTime();

	UFUNCTION(BlueprintImplementableEvent)
	void OnWaitingForPawn();

	UFUNCTION(BlueprintImplementableEvent)
	void OnWaitingForReadyForGameplay();

};

