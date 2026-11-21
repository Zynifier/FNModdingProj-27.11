// Copyright Epic Games, Inc. All Rights Reserved.

#include "ActivityBrowser/FortActivityListView.h"

UFortActivityListView::UFortActivityListView(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UFortActivityListView::AddTileType(EActivityBrowserTileStyle Style, TSubclassOf<UFortActivityBrowserTileBase> WidgetClass)
{
}

int32 UFortActivityListView::GetInViewCount() const
{
	return int32();
}
