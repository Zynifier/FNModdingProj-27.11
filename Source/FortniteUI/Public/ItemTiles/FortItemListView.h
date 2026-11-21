// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonListView.h"
#include "FortTypes.h"
#include "ItemTiles/FortItemListViewInterface.h"
#include "FortItemListView.generated.h"

class IFortItemViewContextInterface;
class UFortItem;

UCLASS(BlueprintType)
class UFortItemListView : public UCommonListView, public IFortItemListViewInterface
{
	GENERATED_BODY()

public:
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnInventoryUpdated);
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnLoadItemsBegin);
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnLoadItemsEnd);

public:
	UFortItemListView(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Fort Item List View")
	bool bShouldShowNullItemListEntry;

	UPROPERTY(EditInstanceOnly, Category="Fort Item List View")
	bool bAutomaticallyLoadItemDetails;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Fort Item List View")
	EItemListViewDisplayType DisplayType;

	UPROPERTY(BlueprintAssignable, Category="Fort Item List View")
	FOnInventoryUpdated OnInventoryUpdatedEvent;

	UPROPERTY(BlueprintAssignable, Category="Fort Item List View")
	FOnInventoryUpdated OnLoadItemsBegin;

	UPROPERTY(BlueprintAssignable, Category="Fort Item List View")
	FOnInventoryUpdated OnLoadItemsEnd;

private:
	UPROPERTY()
	TArray<TWeakObjectPtr<UFortItem>> CustomItemList;

	UPROPERTY()
	TArray<TWeakObjectPtr<UFortItem>> ItemsForListView;

	UPROPERTY()
	TScriptInterface<IFortItemViewContextInterface> ItemViewContext;

};

