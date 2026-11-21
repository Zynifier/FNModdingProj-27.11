// Copyright Epic Games, Inc. All Rights Reserved.

#include "Quests/FortQuestObjectiveInfo.h"

void UFortQuestObjectiveInfo::DisplayDynamicQuestUpdate()
{
}

FText UFortQuestObjectiveInfo::GetObjectiveDescription() const
{
	return FText();
}

UFortQuestItem* UFortQuestObjectiveInfo::GetOwningQuest() const
{
	return nullptr;
}

bool UFortQuestObjectiveInfo::HasCompleted() const
{
	return false;
}

bool UFortQuestObjectiveInfo::IsActive() const
{
	return false;
}

bool UFortQuestObjectiveInfo::IsInProgress() const
{
	return false;
}

bool UFortQuestObjectiveInfo::IsVisibleToUser() const
{
	return false;
}
