// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "Engine/TimerHandle.h"
#include "Athena/ItemShop/AthenaItemShopSectionInterface.h"
#include "AthenaItemShopCarousel.generated.h"

class UAthenaItemShopCarouselTile;
class UCommonButtonGroupLegacy;
class UCommonTextBlock;
class UDynamicEntryBox;
class UFortClickThroughButton;
class UFortSwipePanel;
class UImage;
class UOverlay;
class UPanelWidget;

UCLASS(Abstract, BlueprintType, Blueprintable)
class UAthenaItemShopCarousel : public UCommonUserWidget, public IAthenaItemShopSectionInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	int32 GetSelectedIndex() const;

	UFUNCTION(BlueprintImplementableEvent)
	void OnIntroAnim();

	UFUNCTION(BlueprintCallable)
	void SelectItemAtIndex(int32 ItemIndex);

	UFUNCTION(BlueprintCallable)
	void SelectNextItem();

	UFUNCTION(BlueprintCallable)
	void SelectPrevItem();

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnSelectionChanged(bool bInIsSelected);

	UFUNCTION(BlueprintCallable)
	void OnTransitionCompleted();

	UFUNCTION(BlueprintImplementableEvent)
	void OnTransitionToNextTile();

	UFUNCTION(BlueprintImplementableEvent)
	void OnTransitionToPreviousTile();

private:
	UPROPERTY(EditDefaultsOnly, Category="AthenaItemShopCarousel")
	TSoftClassPtr<UAthenaItemShopCarouselTile> CarouselTileClass;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UOverlay> Container_CurrentTile;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UOverlay> Container_NextTileToShow;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortClickThroughButton> MobileClickThroughButton;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UPanelWidget> HBox_NavigationButtons;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_NextItem;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_PreviousItem;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UImage> Image_AutoScrollProgress;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaItemShopCarousel", meta=(AllowPrivateAccess="TRUE", BindWidget, EditInline="true"))
	TObjectPtr<UDynamicEntryBox> EntryBox_Pips;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaItemShopCarousel", meta=(AllowPrivateAccess="TRUE", BindWidget, EditInline="true"))
	TObjectPtr<UFortSwipePanel> SwipePanel_ItemsNavigation;

	UPROPERTY()
	TObjectPtr<UCommonButtonGroupLegacy> ButtonGroup_Pips;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TArray<TObjectPtr<UAthenaItemShopCarouselTile>> Tiles;

	UPROPERTY(Transient)
	FTimerHandle TileSeenTimerHandle;

	UPROPERTY(Transient)
	int32 SelectedItemIndex;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UAthenaItemShopCarouselTile> NextTileToShow;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UAthenaItemShopCarouselTile> CurrentTile;

};

