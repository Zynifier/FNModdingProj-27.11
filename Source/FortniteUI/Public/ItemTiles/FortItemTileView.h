// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonTileView.h"
#include "FortTypes.h"
#include "FortUITypes.h"
#include "ItemTiles/FortItemListViewInterface.h"
#include "FortItemTileView.generated.h"

class IFortItemViewContextInterface;
class UFortItem;

UCLASS(MinimalAPI, BlueprintType, meta=(DisableNativeTick))
class UFortItemTileView : public UCommonTileView, public IFortItemListViewInterface
{
	GENERATED_BODY()

public:
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnInventoryUpdated);

public:
	UFortItemTileView(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Fort Item Tile View")
	bool bShouldShowNullItemListEntry;

	UPROPERTY(EditInstanceOnly, Category="Fort Item Tile View")
	bool bAutomaticallyLoadItemDetails;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Fort Item Tile View")
	EItemListViewDisplayType DisplayType;

	UPROPERTY()
	bool bShouldOverrideChildItemWidgetCardSize;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Fort Item Tile View")
	EFortItemCardSize ChildItemWidgetCardSizeOverride;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Fort Item Tile View")
	float ChildCosmeticItemCardWidthOverride;

	UPROPERTY(BlueprintAssignable, Category="Fort Item Tile View")
	FOnInventoryUpdated OnInventoryUpdatedEvent;

private:
	UPROPERTY()
	TArray<TWeakObjectPtr<UFortItem>> CustomItemList;

	UPROPERTY()
	TArray<TWeakObjectPtr<UFortItem>> ItemsForListView;

	UPROPERTY()
	TScriptInterface<IFortItemViewContextInterface> ItemViewContext;

};

