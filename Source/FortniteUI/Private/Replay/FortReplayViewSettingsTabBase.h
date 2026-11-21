// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatablePanelLegacy.h"
#include "FortReplayViewSettingsTabBase.generated.h"

class AFortPlayerControllerSpectating;
enum class ESpectatorCameraType : uint8;

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortReplayViewSettingsTabBase : public UCommonActivatablePanelLegacy
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void CenterOnTab();

	UFUNCTION(BlueprintCallable)
	virtual void ResetToDefault();

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnCameraTypeChanged(AFortPlayerControllerSpectating* FortPlayerControllerSpectating, ESpectatorCameraType CameraType);

	UFUNCTION(BlueprintImplementableEvent)
	void SetWidgetValues();

};

