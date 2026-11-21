// Copyright Epic Games, Inc. All Rights Reserved.

#include "Athena/HUD/EndGame/FortPostGameMenuListView.h"

UFortPostGameMenuEntryOverlay::UFortPostGameMenuEntryOverlay(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

UFortPostGameMenuListView::UFortPostGameMenuListView(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

UFortPostGameMenuEntry* UFortPostGameMenuListView::GetFirstEntry() const
{
	return nullptr;
}
