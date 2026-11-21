// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Types/SlateEnums.h"
#include "Athena/SlottedWidgets/FortPrioritizedWidgetSwitcher.h"
#include "FortUIExtensionSlot.h"
#include "FortPlaylistUIExtensionPrioritizedWidgetSwitcher.generated.h"

class UFortPlaylistUIExtensionLoader;

UCLASS()
class UFortPlaylistUIExtensionPrioritizedWidgetSwitcher : public UFortPrioritizedWidgetSwitcher
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="FortPlaylistUIExtensionPrioritizedWidgetSwitcher")
	TEnumAsByte<EHorizontalAlignment> ContentHorizontalAlignment;

	UPROPERTY(EditAnywhere, Category="FortPlaylistUIExtensionPrioritizedWidgetSwitcher")
	TEnumAsByte<EVerticalAlignment> ContentVerticalAlignment;

	UPROPERTY(EditAnywhere, Category="FortPlaylistUIExtensionPrioritizedWidgetSwitcher")
	TArray<EUIExtensionSlot> ExtensionSlots;

	UPROPERTY(Transient)
	TObjectPtr<UFortPlaylistUIExtensionLoader> PlaylistUIExtensionLoader;

};

