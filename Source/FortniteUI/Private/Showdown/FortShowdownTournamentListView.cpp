// Copyright Epic Games, Inc. All Rights Reserved.

#include "Showdown/FortShowdownTournamentListView.h"

UFortShowdownTournamentListView::UFortShowdownTournamentListView(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

UFortShowdownTournamentTile* UFortShowdownTournamentListView::FindTournament(const FString& TournamentId) const
{
	return nullptr;
}

float UFortShowdownTournamentListView::GetDesiredScrollOffset(int32 Index) const
{
	return float();
}

UUserWidget* UFortShowdownTournamentListView::GetEntryAtIndex(int32 SelectedIndex) const
{
	return nullptr;
}

bool UFortShowdownTournamentListView::IsSelectedItemFirstRow() const
{
	return false;
}

bool UFortShowdownTournamentListView::IsSelectedItemLastRow() const
{
	return false;
}

UFortShowdownTournamentTile* UFortShowdownTournamentListView::NavigateTournamentLeft()
{
	return nullptr;
}

UFortShowdownTournamentTile* UFortShowdownTournamentListView::NavigateTournamentRight()
{
	return nullptr;
}

void UFortShowdownTournamentListView::ScrollItemToDesiredOffset(UObject* InObject)
{
}

UFortShowdownTournamentTile* UFortShowdownTournamentListView::SelectFirstTournament()
{
	return nullptr;
}

UFortShowdownTournamentTile* UFortShowdownTournamentListView::SelectLastTournament()
{
	return nullptr;
}

UFortShowdownTournamentTile* UFortShowdownTournamentListView::SelectTournamentAtIndex(const int32 SelectedIndex)
{
	return nullptr;
}

void UFortShowdownTournamentListView::SetScrollOffsetAnimation(const bool bEnable)
{
}
