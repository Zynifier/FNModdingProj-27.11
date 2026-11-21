// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "AthenaQuickBarSlotExtensionWidgetBase.generated.h"

class UFortItem;

UCLASS(Abstract, MinimalAPI, BlueprintType, NotBlueprintable, meta=(DisableNativeTick))
class UAthenaQuickBarSlotExtensionWidgetBase : public UCommonUserWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	FORTNITEUI_API void OnItemChanged(const UFortItem* Item);

	UFUNCTION(BlueprintImplementableEvent)
	FORTNITEUI_API void OnOwnerActivated();

	UFUNCTION(BlueprintImplementableEvent)
	FORTNITEUI_API void OnOwnerDeactivated();

	UFUNCTION(BlueprintImplementableEvent)
	FORTNITEUI_API void OnOwnerDeselected();

	UFUNCTION(BlueprintImplementableEvent)
	FORTNITEUI_API void OnOwnerHovered();

	UFUNCTION(BlueprintImplementableEvent)
	FORTNITEUI_API void OnOwnerSelected();

	UFUNCTION(BlueprintImplementableEvent)
	FORTNITEUI_API void OnOwnerUnhovered();

};

