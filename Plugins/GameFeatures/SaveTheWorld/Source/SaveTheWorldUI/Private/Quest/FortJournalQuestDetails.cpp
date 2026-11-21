// Copyright Epic Games, Inc. All Rights Reserved.

#include "Quest/FortJournalQuestDetails.h"

bool UFortJournalQuestDetails::CanGotoQuest()
{
	return false;
}

bool UFortJournalQuestDetails::CanPartyLeaderPlayQuest()
{
	return false;
}

bool UFortJournalQuestDetails::CanPlayQuest()
{
	return false;
}

EFortTheaterMapTileType UFortJournalQuestDetails::GetActiveMissionTileType()
{
	return EFortTheaterMapTileType();
}

void UFortJournalQuestDetails::GetFutureObjectives(TArray<UFortQuestObjectiveInfo*>& FutureObjectives)
{
}

void UFortJournalQuestDetails::GetRewards(TArray<FFortItemInstanceQuantityPair>& OutRewards, TArray<FFortItemInstanceQuantityPair>& OutSelectableRewards)
{
}

void UFortJournalQuestDetails::GetVisibleObjectives(TArray<UFortQuestObjectiveInfo*>& VisibleObjectives)
{
}

void UFortJournalQuestDetails::RegisterEndSpokenDialogEvent()
{
}

void UFortJournalQuestDetails::SetCurrentQuest(UFortQuestItem* InCurrentQuest)
{
}
