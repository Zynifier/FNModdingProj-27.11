// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UIManager/FortActivatablePanel.h"
#include "FortCollectionBookSlotConfirmationModal.generated.h"

class UCommonButtonLegacy;
class UCommonTextBlock;
class UFortAccountItem;
class UFortCollectionBookRecycleSlotResultsWidget;
class UFortMultiSizeItemCard;

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortCollectionBookSlotConfirmationModal : public UFortActivatablePanel
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnSlotItemRequested();

	UFUNCTION(BlueprintImplementableEvent)
	void OnSlotItemRequestedComplete();

private:
	UFUNCTION()
	void HandleSlotItemComplete(const UFortAccountItem* SlottedItem, FName SlotId);

	UPROPERTY(Transient)
	TObjectPtr<UFortAccountItem> CurrentlySlottedItem;

	UPROPERTY(Transient)
	TObjectPtr<UFortAccountItem> NewItemToSlot;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_SlottingDescription;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortMultiSizeItemCard> ItemCard_NewlySlottedItem;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortCollectionBookRecycleSlotResultsWidget> RecycleSlotResultsWidget;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_SlotItem;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_Back;

};

