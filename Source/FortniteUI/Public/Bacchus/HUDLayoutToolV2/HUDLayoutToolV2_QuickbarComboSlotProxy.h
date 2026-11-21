// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Bacchus/HUDLayoutToolV2/FortMobileHUDElementProxy.h"
#include "HUDLayoutToolV2_QuickbarComboSlotProxy.generated.h"

class UCommonTextBlock;
class UCommonVisibilitySwitcher;
class UImage;
class UPaperSprite;

UCLASS(Abstract)
class UHUDLayoutToolV2_QuickbarComboSlotProxy : public UFortMobileHUDElementProxy
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="HUDLayoutToolV2_QuickbarComboSlotProxy")
	TArray<TObjectPtr<UPaperSprite>> CombatIcons;

	UPROPERTY(EditAnywhere, Category="HUDLayoutToolV2_QuickbarComboSlotProxy")
	TArray<TObjectPtr<UPaperSprite>> BuildingIcons;

	UPROPERTY(EditAnywhere, Category="HUDLayoutToolV2_QuickbarComboSlotProxy")
	TArray<TObjectPtr<UPaperSprite>> ComboIcons;

	UPROPERTY(EditAnywhere, Category="Custom Properties", meta=(Categories="HUDLayout.Property"))
	FGameplayTag SlotTypePropertyTag;

	UPROPERTY(EditAnywhere, Category="Custom Properties", meta=(Categories="HUDLayout.Property"))
	FGameplayTag SlotLockPropertyTag;

	UPROPERTY(EditAnywhere, Category="Custom Properties", meta=(Categories="HUDLayout.Property"))
	FGameplayTag SlotNumberPropertyTag;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonVisibilitySwitcher> Switcher_SlotType;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UImage> Image_CombatIcon;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UImage> Image_BuildingIcon;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UImage> Image_ComboIcon;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UImage> Image_LockIcon;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_SlotNumber;

};

