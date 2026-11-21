// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/Inventory/AthenaQuickBarSlotButtonBase.h"
#include "AthenaInventoryQuickBarSlotButton.generated.h"

class UUserWidget;
enum class EUIExtensionSlot : uint8;

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UAthenaInventoryQuickBarSlotButton : public UAthenaQuickBarSlotButtonBase
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnExtensionWidgetAdded(const EUIExtensionSlot ExtensionSlot, UUserWidget* ExtensionWidget);

	UFUNCTION(BlueprintImplementableEvent)
	void OnSwapComplete();

	UFUNCTION(BlueprintImplementableEvent)
	void OnSwapStarted();

private:
	UFUNCTION()
	void HandleInventorySwapComplete();

	UFUNCTION()
	void HandleInventorySwapStarted(int32 SwapSlotIndex);

};

