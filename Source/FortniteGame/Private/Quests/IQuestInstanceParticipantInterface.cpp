// Copyright Epic Games, Inc. All Rights Reserved.

#include "Quests/IQuestInstanceParticipantInterface.h"

TScriptInterface<IQuestInstanceInterface> IQuestInstanceParticipantInterface::FindQuestInstance(const FString& QuestID) const
{
	return TScriptInterface<IQuestInstanceInterface>();
}

bool IQuestInstanceParticipantInterface::IsQuestInstanceCompleted(const FString& QuestID) const
{
	return false;
}

bool IQuestInstanceParticipantInterface::IsQuestInstanceObjectiveActive(const FString& QuestID, const FName& ObjectiveName) const
{
	return false;
}

bool IQuestInstanceParticipantInterface::IsQuestInstanceObjectiveCompleted(const FString& QuestID, const FName& ObjectiveName) const
{
	return false;
}
