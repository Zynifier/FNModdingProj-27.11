// Copyright Epic Games, Inc. All Rights Reserved.

#include "FortEmporiumItemDetailsPanel.h"

void UFortEmporiumItemDetailsPanel::HandleItemTagSelected(FName TagID, bool bSelected)
{
}

bool UFortEmporiumItemDetailsPanel::HasLegacyItemDetailsPanel_Implementation() const
{
	return false;
}

bool UFortEmporiumItemDetailsPanel::IsShowingAdditionalButtons_Implementation()
{
	return false;
}

bool UFortEmporiumItemDetailsPanel::IsShowingExtendedDataPanel_Implementation() const
{
	return false;
}

void UFortEmporiumItemDetailsPanel::SetItemToDetail(const UFortItem* InItemToDetail, const bool bUseLargeThumbnail, const bool bAllowInteractiveTags)
{
}
