// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/IUserObjectListEntry.h"
#include "CommonButtonLegacy.h"
#include "FortUITypes.h"
#include "ItemTiles/FortItemListViewInterface.h"
#include "FortItemListEntryButton.generated.h"

class IFortItemViewContextInterface;
class UFortItem;
class UFortMultiSizeItemCard;

UCLASS(Abstract, BlueprintType, Blueprintable)
class UFortItemListEntryButton : public UCommonButtonLegacy, public IUserObjectListEntry, public IFortItemListEntryWidgetInterface
{
	GENERATED_BODY()

protected:
	UPROPERTY(BlueprintReadOnly, Export, Category="FortItemListEntryButton", meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UFortMultiSizeItemCard> ItemWidget;

	UPROPERTY(BlueprintReadOnly, Category="Item List Entry")
	TWeakObjectPtr<UFortItem> Item;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Item List Entry")
	EFortItemCardSize ItemCardSize;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Item List Entry")
	bool IsRewardCard;

	UPROPERTY()
	TScriptInterface<IFortItemViewContextInterface> ItemViewContext;

};

