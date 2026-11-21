// Copyright Epic Games, Inc. All Rights Reserved.

#include "QuestTools/FortQuestToolListView.h"

UFortQuestToolListView::UFortQuestToolListView(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

int32 UFortQuestToolListView::GetNumListEntries() const
{
	return int32();
}

int32 UFortQuestToolListView::GetQuestToolListItemIndex(UUserWidget* ListItemWidget) const
{
	return int32();
}

bool UFortQuestToolListView::RemoveQuestToolListEntry(UUserWidget* ListItemWidget)
{
	return false;
}
