// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonButtonBase.h"
#include "Items/FortQuickBars.h"
#include "AthenaQuickBarSlotButtonBase.generated.h"

class UAthenaItemIcon;
class UFortItem;
enum class EFortQuickBars : uint8;

UCLASS(Abstract, MinimalAPI, NotBlueprintable, meta=(DisableNativeTick))
class UAthenaQuickBarSlotButtonBase : public UCommonButtonBase
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	FORTNITEUI_API void OnOwnerActivated();

	UFUNCTION(BlueprintImplementableEvent)
	FORTNITEUI_API void OnOwnerDeactivated();

	UFUNCTION(BlueprintImplementableEvent)
	FORTNITEUI_API void OnSlottedItemChanged(const UFortItem* SlottedItem);

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AthenaQuickBarSlotButtonBase", meta=(AllowPrivateAccess))
	EFortQuickBars QuickBarIndex;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AthenaQuickBarSlotButtonBase", meta=(AllowPrivateAccess))
	int32 SlotIndex;

private:
	UFUNCTION()
	FORTNITEUI_API void HandleInventoryItemSelected(UFortItem* SelectedItem);

	UFUNCTION()
	FORTNITEUI_API void HandleQuickbarContentsChanged(EFortQuickBars InQuickBarIndex, const TArray<int32>& ChangedSlots);

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaQuickBarSlotButtonBase", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UAthenaItemIcon> ItemIcon;

};

