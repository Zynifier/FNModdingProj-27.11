// Copyright Epic Games, Inc. All Rights Reserved.

#include "ContentBrowser/ContentBrowserFiltersPanel.h"

int32 UContentBrowserFiltersPanel::GetFilterCount() const
{
	return int32();
}

void UContentBrowserFiltersPanel::HandleFilterEnabled(bool bIsFilterEnabled, UObject* ListItemObject)
{
}

void UContentBrowserFiltersPanel::HandleFilterSelected(bool bIsFilterEnabled, UContentBrowserFilterEntry* Entry)
{
}

void UContentBrowserFiltersPanel::HandleSearchTextChanged(const FText& Text)
{
}

void UContentBrowserFiltersPanel::HandleShowAll(bool bShowAllItems, UObject* ListItemObject)
{
}
