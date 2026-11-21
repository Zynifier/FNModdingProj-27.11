// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Replay/FortReplayViewSettingsTabBase.h"
#include "FortSpectatorAmbientSettingsTab.generated.h"

class UWidget;

UCLASS(Abstract, MinimalAPI, meta=(DisableNativeTick))
class UFortSpectatorAmbientSettingsTab : public UFortReplayViewSettingsTabBase
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnTimeOfDayPauseChanged(bool bPaused);

private:
	UFUNCTION(BlueprintPure)
	float GetCurrentTimeOfDay() const;

	UFUNCTION(BlueprintPure)
	bool IsGeneralTimeOfDayManagerActive() const;

	UFUNCTION(BlueprintCallable)
	void SetTimeOfDay(float TimeOfDay);

	UFUNCTION(BlueprintCallable)
	void SetTimeOfDayPaused(bool bPaused);

	UPROPERTY(BlueprintReadOnly, Export, Category="FortSpectatorAmbientSettingsTab", meta=(AllowPrivateAccess="TRUE", BindWidget, EditInline="true"))
	TObjectPtr<UWidget> TimeOfDaySlider;

};

