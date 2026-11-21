// Copyright Epic Games, Inc. All Rights Reserved.

#include "Creative/FortCreativeIslandLinkScreen.h"

void UFortCreativeIslandLinkScreen::AddIslandToFavorites(UFortCreativeIslandLink* LinkEntry)
{
}

FOnlineLinkId UFortCreativeIslandLinkScreen::GetLinkIdFromInput() const
{
	return FOnlineLinkId();
}

FText UFortCreativeIslandLinkScreen::GetMatchmakingTypeDescription(const UFortCreativeIslandLink* IslandLink) const
{
	return FText();
}

FText UFortCreativeIslandLinkScreen::GetTextFromLinkId(const FOnlineLinkId& LinkId) const
{
	return FText();
}

void UFortCreativeIslandLinkScreen::HandleIslandLinkChanged(const FText& Text)
{
}

void UFortCreativeIslandLinkScreen::HandleIslandLinkCommitted(const FText& InText, ETextCommit::Type CommitInfo)
{
}

void UFortCreativeIslandLinkScreen::HandleIslandSelectionChanged(UObject* Item)
{
}

bool UFortCreativeIslandLinkScreen::IsPartyEligible(const UFortCreativeIslandLink* IslandLink) const
{
	return false;
}

void UFortCreativeIslandLinkScreen::RemoveIslandFromFavorites(UFortCreativeIslandLink* LinkEntry)
{
}

void UFortCreativeIslandLinkScreen::RemoveIslandFromHistory(const FOnlineLinkId& LinkCode)
{
}

void UFortCreativeIslandLinkScreen::SetFavoritesOnlyMode(bool bFavoritesOnly)
{
}

void UFortCreativeIslandLinkScreen::SetTargetPortal(AFortAthenaCreativePortal* Portal)
{
}
