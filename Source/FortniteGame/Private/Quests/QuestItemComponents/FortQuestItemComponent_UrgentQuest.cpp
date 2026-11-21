// Copyright Epic Games, Inc. All Rights Reserved.

#include "Quests/QuestItemComponents/FortQuestItemComponent_UrgentQuest.h"

void UFortQuestItemComponent_UrgentQuest::AuthorityHandleNewParticipantsRegistered(const TScriptInterface<IQuestInstanceInterface>& QuestInstance, const TArray<TScriptInterface<IQuestInstanceParticipantInterface>>& Participants)
{
}

void UFortQuestItemComponent_UrgentQuest::AuthorityHandleNewParticipantsUnregistered(const TScriptInterface<IQuestInstanceInterface>& QuestInstance, const TArray<TScriptInterface<IQuestInstanceParticipantInterface>>& Participants)
{
}

float UFortQuestItemComponent_UrgentQuest::GetTimeRemaining() const
{
	return float();
}

bool UFortQuestItemComponent_UrgentQuest::HasQuestFailureBeenTriggered() const
{
	return false;
}
