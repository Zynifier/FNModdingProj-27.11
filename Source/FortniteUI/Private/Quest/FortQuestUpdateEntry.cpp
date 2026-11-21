// Copyright Epic Games, Inc. All Rights Reserved.

#include "Quest/FortQuestUpdateEntry.h"

bool UFortQuestUpdateEntry::CanAddObjective(UFortQuestItem* QuestItemToCheck)
{
	return false;
}

void UFortQuestUpdateEntry::CurrentlyDisplayedObjectiveFinished(UFortQuestObjectiveEntry* QuestObjective)
{
}

void UFortQuestUpdateEntry::FinishQuestIntro()
{
}

void UFortQuestUpdateEntry::FinishQuestOutro()
{
}

int32 UFortQuestUpdateEntry::GetNumDisplayedObjectives()
{
	return int32();
}

void UFortQuestUpdateEntry::SetQuestItem(const UFortQuestObjectiveInfo* ObjectiveInfo, bool bIsAnnouncement)
{
}
