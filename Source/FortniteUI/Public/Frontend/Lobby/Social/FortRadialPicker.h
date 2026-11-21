// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "FortRadialPicker.generated.h"

enum class EFortPickerMode : uint8;

UCLASS(Abstract, MinimalAPI, meta=(DisableNativeTick))
class UFortRadialPicker : public UCommonActivatableWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void InitializePicker(EFortPickerMode PickerMode, int32 InitalOption);

protected:
	UFUNCTION(BlueprintCallable, meta=(BlueprintProtected="TRUE"))
	void BroadcastPanelClosed();

	UFUNCTION(BlueprintCallable, meta=(BlueprintProtected="TRUE"))
	void NotifyInitializePicker();

};

