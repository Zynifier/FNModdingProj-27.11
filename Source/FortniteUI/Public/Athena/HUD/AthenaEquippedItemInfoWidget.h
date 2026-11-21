// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/AthenaEquippedItemBase.h"
#include "AthenaEquippedItemInfoWidget.generated.h"

class UUserWidget;
enum class EUIExtensionSlot : uint8;

UCLASS(Abstract, meta=(DisableNativeTick))
class UAthenaEquippedItemInfoWidget : public UAthenaEquippedItemBase
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnExtensionWidgetAdded(const EUIExtensionSlot ExtensionSlot, UUserWidget* ExtensionWidget);

};

