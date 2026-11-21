// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortItemQuantityPair.h"
#include "ItemTiles/FortItemFiltering.h"
#include "ItemTiles/FortItemSorting.h"
#include "FortItemListViewInterface.generated.h"

class IFortItemViewContextInterface;
class UFortItem;

USTRUCT(BlueprintType)
struct FFortItemListViewConfig
{
	GENERATED_BODY()

};

UINTERFACE(MinimalAPI, NotBlueprintable, meta=(CannotImplementInterfaceInBlueprint))
class UFortItemListEntryWidgetInterface : public UInterface
{
	GENERATED_BODY()
};

class FORTNITEUI_API IFortItemListEntryWidgetInterface
{
	GENERATED_BODY()

};

UINTERFACE(NotBlueprintable, meta=(CannotImplementInterfaceInBlueprint))
class UFortItemListViewInterface : public UInterface
{
	GENERATED_BODY()
};

class IFortItemListViewInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Fort Item List View")
	virtual void CenterSelectedItemListEntryWidget();

	UFUNCTION(BlueprintCallable, Category="Fort Item List View")
	virtual void ClearCustomItemList();

	UFUNCTION(BlueprintCallable, Category="Fort Item List View")
	virtual bool ContainsItem(const UFortItem* Item) const;

	UFUNCTION(BlueprintCallable, Category="Fort Item List View")
	virtual const FFortItemListViewConfig GetConfig() const;

	UFUNCTION(BlueprintCallable, Category="Fort Item List View")
	virtual const FFortItemFilterDefinition& GetFilter() const;

	UFUNCTION(BlueprintCallable, Category="Fort Item List View")
	virtual const FFortItemSorterDefinition& GetSorter() const;

	UFUNCTION()
	virtual void HandleItemEvolutionBegun(const FString& OriginalItemInstanceId);

	UFUNCTION()
	virtual void HandleItemEvolutionCompleted(const bool bWasSuccessful, const FString& OriginalItemInstanceId, const TArray<FFortItemInstanceQuantityPair>& ItemQuantities);

	UFUNCTION()
	virtual void HandleItemRarityUpgradeBegun(const FString& OriginalItemInstanceId);

	UFUNCTION()
	virtual void HandleItemRarityUpgradeCompleted(const bool bWasSuccessful, const FString& OriginalItemInstanceId, const TArray<FFortItemInstanceQuantityPair>& ItemQuantities);

	UFUNCTION()
	virtual void HandleItemRefundBegun(const FString& OriginalItemInstanceId);

	UFUNCTION()
	virtual void HandleItemRefundCompleted(const bool bWasSuccessful, const FString& OriginalItemInstanceId, const TArray<FFortItemInstanceQuantityPair>& ItemQuantities);

	UFUNCTION(BlueprintCallable, Category="Fort Item List View")
	virtual void HideNullItemListEntry();

	UFUNCTION(BlueprintCallable, Category="Fort Item List View")
	virtual void RefreshFilterAndSort();

	UFUNCTION(BlueprintCallable, Category="Fort Item List View")
	virtual void RefreshSort();

	UFUNCTION(BlueprintCallable, Category="Fort Item List View")
	virtual void SetConfig(const FFortItemListViewConfig& Config);

	UFUNCTION(BlueprintCallable, Category="Fort Item List View")
	virtual void SetCustomItemList(const TArray<UFortItem*>& ItemList);

	UFUNCTION(BlueprintCallable, Category="Fort Item List View")
	virtual void SetFilter(const FFortItemFilterDefinition& Filter);

	UFUNCTION(BlueprintCallable, Category="Fort Item List View")
	virtual void SetFilterAndSorter(const FFortItemFilterDefinition& Filter, const FFortItemSorterDefinition& Sorter);

	UFUNCTION(BlueprintCallable, Category="Fort Item List View")
	virtual void SetItemViewContext(TScriptInterface<IFortItemViewContextInterface> ItemViewContext);

	UFUNCTION(BlueprintCallable, Category="Fort Item List View")
	virtual void SetSorter(const FFortItemSorterDefinition& Sorter);

	UFUNCTION(BlueprintCallable, Category="Fort Item List View")
	virtual void ShowNullItemListEntry();

};

