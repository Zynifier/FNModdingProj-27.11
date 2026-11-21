// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortHUDElementWidget.h"
#include "AthenaPostMatchQuestTier.generated.h"

class UUserWidget;
enum class EUIExtensionSlot : uint8;

UCLASS(Abstract, meta=(DisableNativeTick))
class FORTNITEUI_API UAthenaPostMatchQuestTier : public UFortHUDElementWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnExtensionWidgetAdded(const EUIExtensionSlot ExtensionSlot, UUserWidget* ExtensionWidget);

};

