// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "Components/SlateWrapperTypes.h"
#include "Math/MathFwd.h"
#include "FortUITypes.h"
#include "Items/FortQuickBars.h"
#include "FortQuickBarSlotBase.generated.h"

class UAthenaQuickBarNativeCell;
class UCommonTextBlock;
class UCommonWidgetSwitcherLegacy;
class UFortInputData;
class UFortItem;
class UFortItemCooldownWidget;
class UFortKeybindWidget;
class UFortMultiSizeItemCard;
class UImage;
class UTutorialHighlight;
enum class EFortItemCardSize : uint8;
enum class EFortQuickBars : uint8;

UCLASS(BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortQuickBarSlotBase : public UCommonUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	FName GetKeyBindingAction();

	UFUNCTION(BlueprintCallable)
	FName GetKeyBindingActionGamepad();

	UFUNCTION(BlueprintCallable)
	FName GetKeyBindingActionKeyboard();

	UFUNCTION(BlueprintPure)
	const FVector2D GetSlotSizeForItem(const UFortItem* InItem) const;

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void MaximizeSlot(bool bShouldSkipAnimation);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void MinimizeSlot(bool bShouldSkipAnimation);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void OnRefreshItem();

	UFUNCTION(BlueprintCallable)
	void RefreshInventoryCapacity();

	UFUNCTION(BlueprintCallable)
	void RefreshItem();

	UFUNCTION(BlueprintCallable)
	void RefreshItemIfSlotChanged(EFortQuickBars InQuickBar, const TArray<int32>& InSlot);

	UFUNCTION(BlueprintCallable)
	void Resize(EFortItemCardSize CardSize);

	UFUNCTION(BlueprintCallable)
	void SetBottomComboSwitcherVisibility(ESlateVisibility InVisibility);

	UFUNCTION(BlueprintImplementableEvent)
	void SetBottomComboSwitcherVisibility_BP(ESlateVisibility InVisibility);

	UFUNCTION(BlueprintCallable)
	void SetQuickbarIndexRuntime(int32 Index, bool bRefresh = true);

	UFUNCTION(BlueprintCallable)
	void SetQuickbarTypeRuntime(EFortQuickBars NewQuickBarType, bool bRefresh = true);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void SetSlotSelected(bool bSelected);

	UFUNCTION(BlueprintCallable)
	void SetTopComboSwitcherVisibility(ESlateVisibility InVisibility);

	UFUNCTION(BlueprintCallable)
	void UpdateItemCardsVisibility();

	UFUNCTION(BlueprintCallable)
	void UpdateKeyBindingText();

	UFUNCTION(BlueprintCallable)
	void UpdateKeyBindingVisibility();

protected:
	UFUNCTION()
	void OnMinigameEnded();

	UFUNCTION()
	void OnMinigameStarted();

	UPROPERTY(BlueprintReadOnly, Export, Category="QuickBar", meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UCommonWidgetSwitcherLegacy> SwitcherTopComboSwitcher;

	UPROPERTY(BlueprintReadOnly, Export, Category="QuickBar", meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UCommonWidgetSwitcherLegacy> SwitcherBottomComboSwitcher;

	UPROPERTY(BlueprintReadOnly, Export, Category="QuickBar", meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UFortKeybindWidget> KeybindTop;

	UPROPERTY(BlueprintReadOnly, Export, Category="QuickBar", meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UFortKeybindWidget> KeybindBottom;

	UPROPERTY(BlueprintReadOnly, Export, Category="QuickBar", meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UFortKeybindWidget> KeybindBottomCombo1;

	UPROPERTY(BlueprintReadOnly, Export, Category="QuickBar", meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UFortKeybindWidget> KeybindBottomCombo2;

	UPROPERTY(BlueprintReadOnly, Export, Category="QuickBar", meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UFortKeybindWidget> KeybindTopComboArrow1;

	UPROPERTY(BlueprintReadOnly, Export, Category="QuickBar", meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UFortKeybindWidget> KeybindTopComboArrow2;

	UPROPERTY(BlueprintReadOnly, Export, Category="QuickBar", meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UFortKeybindWidget> KeybindBottomComboArrow1;

	UPROPERTY(BlueprintReadOnly, Export, Category="QuickBar", meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UFortKeybindWidget> KeybindBottomComboArrow2;

	UPROPERTY(BlueprintReadOnly, Export, Category="QuickBar", meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UCommonTextBlock> BottomHoldText;

	UPROPERTY(BlueprintReadOnly, Export, Category="QuickBar", meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UImage> TopLeftArrowImage;

	UPROPERTY(BlueprintReadOnly, Export, Category="QuickBar", meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UImage> TopLeftArrowImage2;

	UPROPERTY(BlueprintReadOnly, Export, Category="QuickBar", meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UImage> TopRightArrowImage;

	UPROPERTY(BlueprintReadOnly, Export, Category="QuickBar", meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UImage> TopRightArrowImage2;

	UPROPERTY(BlueprintReadOnly, Export, Category="QuickBar", meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UImage> BottomLeftArrowImage;

	UPROPERTY(BlueprintReadOnly, Export, Category="QuickBar", meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UImage> BottomLeftArrowImage2;

	UPROPERTY(BlueprintReadOnly, Export, Category="QuickBar", meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UImage> BottomRightArrowImage;

	UPROPERTY(BlueprintReadOnly, Export, Category="QuickBar", meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UImage> BottomRightArrowImage2;

	UPROPERTY(BlueprintReadOnly, Export, Category="QuickBar", meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UImage> EmptyImage;

	UPROPERTY(BlueprintReadOnly, Export, Category="QuickBar", meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UFortMultiSizeItemCard> ItemCardMaximized;

	UPROPERTY(BlueprintReadOnly, Export, Category="QuickBar", meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UFortMultiSizeItemCard> ItemCardMinimized;

	UPROPERTY(BlueprintReadOnly, Export, Category="QuickBar", meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UFortItemCooldownWidget> QuickbarSlotCooldown;

	UPROPERTY(BlueprintReadOnly, Export, Category="QuickBar", meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UImage> SlotInteraction;

	UPROPERTY(BlueprintReadOnly, Export, Category="QuickBar", meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UAthenaQuickBarNativeCell> NativeCell;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortQuickBarSlotBase")
	int32 SlotIndex;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortQuickBarSlotBase")
	EFortQuickBars QuickBarType;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortQuickBarSlotBase")
	uint8 bShowBottomArrows : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortQuickBarSlotBase")
	uint8 bShowTopArrows : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortQuickBarSlotBase")
	uint8 bHideKeybindsWhenAbilityUnavailable : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortQuickBarSlotBase")
	uint8 bShouldCollapseItemWidgetBorder : 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortQuickBarSlotBase")
	uint8 DoNotPlaySelectionAnimation : 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortQuickBarSlotBase")
	uint8 bIsAthenaQuickBar : 1;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="FortQuickBarSlotBase")
	uint8 bKeybindsHidden : 1;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="FortQuickBarSlotBase")
	EFortItemCardSize ItemCardSize;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="FortQuickBarSlotBase")
	TObjectPtr<UFortItem> Item;

	UPROPERTY(Transient)
	TObjectPtr<UFortInputData> InputData;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortQuickBarSlotBase")
	bool bCheckVisibilityBasedOffInventoryCapacity;

	UPROPERTY(Export, meta=(BindWidgetOptional))
	TWeakObjectPtr<UTutorialHighlight> TutorialHighlight;

	UPROPERTY(BlueprintReadOnly, Category="FortQuickBarSlotBase")
	bool bDragAndDropEnabled;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortQuickBarSlotBase")
	uint8 bUseSlotSizeBySlotUsage : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortQuickBarSlotBase")
	TArray<FVector2D> SlotSizeBySlotUsage;

};

