// Copyright Epic Games, Inc. All Rights Reserved.

#include "ItemTiles/FortItemListViewInterface.h"

void IFortItemListViewInterface::CenterSelectedItemListEntryWidget()
{
}

void IFortItemListViewInterface::ClearCustomItemList()
{
}

bool IFortItemListViewInterface::ContainsItem(const UFortItem* Item) const
{
	return false;
}

const FFortItemListViewConfig IFortItemListViewInterface::GetConfig() const
{
	return FFortItemListViewConfig();
}

const FFortItemFilterDefinition& IFortItemListViewInterface::GetFilter() const
{
	static FFortItemFilterDefinition Dummy;
	return Dummy;
}

const FFortItemSorterDefinition& IFortItemListViewInterface::GetSorter() const
{
	static FFortItemSorterDefinition Dummy;
	return Dummy;
}

void IFortItemListViewInterface::HandleItemEvolutionBegun(const FString& OriginalItemInstanceId)
{
}

void IFortItemListViewInterface::HandleItemEvolutionCompleted(const bool bWasSuccessful, const FString& OriginalItemInstanceId, const TArray<FFortItemInstanceQuantityPair>& ItemQuantities)
{
}

void IFortItemListViewInterface::HandleItemRarityUpgradeBegun(const FString& OriginalItemInstanceId)
{
}

void IFortItemListViewInterface::HandleItemRarityUpgradeCompleted(const bool bWasSuccessful, const FString& OriginalItemInstanceId, const TArray<FFortItemInstanceQuantityPair>& ItemQuantities)
{
}

void IFortItemListViewInterface::HandleItemRefundBegun(const FString& OriginalItemInstanceId)
{
}

void IFortItemListViewInterface::HandleItemRefundCompleted(const bool bWasSuccessful, const FString& OriginalItemInstanceId, const TArray<FFortItemInstanceQuantityPair>& ItemQuantities)
{
}

void IFortItemListViewInterface::HideNullItemListEntry()
{
}

void IFortItemListViewInterface::RefreshFilterAndSort()
{
}

void IFortItemListViewInterface::RefreshSort()
{
}

void IFortItemListViewInterface::SetConfig(const FFortItemListViewConfig& Config)
{
}

void IFortItemListViewInterface::SetCustomItemList(const TArray<UFortItem*>& ItemList)
{
}

void IFortItemListViewInterface::SetFilter(const FFortItemFilterDefinition& Filter)
{
}

void IFortItemListViewInterface::SetFilterAndSorter(const FFortItemFilterDefinition& Filter, const FFortItemSorterDefinition& Sorter)
{
}

void IFortItemListViewInterface::SetItemViewContext(TScriptInterface<IFortItemViewContextInterface> ItemViewContext)
{
}

void IFortItemListViewInterface::SetSorter(const FFortItemSorterDefinition& Sorter)
{
}

void IFortItemListViewInterface::ShowNullItemListEntry()
{
}
