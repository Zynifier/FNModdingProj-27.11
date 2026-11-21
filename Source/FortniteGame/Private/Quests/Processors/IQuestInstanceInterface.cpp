// Copyright Epic Games, Inc. All Rights Reserved.

#include "Quests/Processors/IQuestInstanceInterface.h"

FString IQuestInstanceInterface::GetQuestID() const
{
	return FString();
}

bool IQuestInstanceInterface::HasCompletedObjectiveInstance(FName BackendName) const
{
	return false;
}
