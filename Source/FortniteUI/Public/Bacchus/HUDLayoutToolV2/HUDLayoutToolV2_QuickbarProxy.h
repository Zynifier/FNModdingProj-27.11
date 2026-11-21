// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Athena/Mobile/BacchusQuickbarBase.h"
#include "Bacchus/HUDLayoutToolV2/FortMobileHUDElementProxy.h"
#include "HUDLayoutToolV2_QuickbarProxy.generated.h"

class UFortDynamicEntryBox;
class UPaperSprite;

USTRUCT()
struct FQuickbarProxySlotIconContainer
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="QuickbarProxySlotIconContainer")
	TArray<TObjectPtr<UPaperSprite>> SlotIcons;

};

UCLASS(Abstract)
class UHUDLayoutToolV2_QuickbarProxy : public UFortMobileHUDElementProxy
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="HUDLayoutToolV2_QuickbarProxy")
	TMap<EComboSlotType, FQuickbarProxySlotIconContainer> QuickbarProxySlotIcons;

	UPROPERTY(EditAnywhere, Category="Slot Amount")
	TMap<FGameplayTag, int32> SlotAmountOverridePerContext;

	UPROPERTY(EditAnywhere, Category="Slot Amount")
	int32 DefaultSlotAmount;

	UPROPERTY(EditAnywhere, Category="Custom Properties", meta=(Categories="HUDLayout.Property"))
	FGameplayTag SlotLocksPropertyTag;

	UPROPERTY(EditAnywhere, Category="Custom Properties", meta=(Categories="HUDLayout.Property"))
	FGameplayTag ReversePropertyTag;

	UPROPERTY(EditAnywhere, Category="Custom Properties", meta=(Categories="HUDLayout.Property"))
	FGameplayTag SlotTypePropertyTag;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortDynamicEntryBox> EntryBox_QuickbarProxySlots;

};

