// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "Athena/SlottedWidgets/FortPrioritizedWidgetInterface.h"
#include "HardcoreModifierFlyover.generated.h"

UCLASS(Abstract, MinimalAPI, meta=(DisableNativeTick))
class UHardcoreModifierFlyover : public UCommonUserWidget, public IFortPrioritizedWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void HandleUpdateActiveModifiers(const FText& ActiveModifierText);

};

