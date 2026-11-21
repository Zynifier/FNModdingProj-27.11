// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "AthenaHUDContextualControls.generated.h"

class UUserWidget;

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UAthenaHUDContextualControls : public UCommonUserWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnControllerBindingCalloutExtensionAdded(UUserWidget* ExtensionWidget);

	UFUNCTION(BlueprintImplementableEvent)
	void OnExpEventFinished();

	UFUNCTION(BlueprintImplementableEvent)
	void OnExpEventStarted();

	UFUNCTION(BlueprintImplementableEvent)
	void OnVehicleActionsSpacerExtensionAdded(UUserWidget* ExtensionWidget);

};

