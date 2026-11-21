// Copyright Epic Games, Inc. All Rights Reserved.

#include "Quests/AthenaQuestCategoryManager.h"

void UAthenaQuestCategoryManager::HandleParticipantQuestAdded(const TScriptInterface<IQuestInstanceInterface>& QuestInstance)
{
}

void UAthenaQuestCategoryManager::HandleParticipantQuestRemoved(const TScriptInterface<IQuestInstanceInterface>& QuestInstance)
{
}

void UAthenaQuestCategoryManager::HandlePlayerProfileInit()
{
}

void UAthenaQuestCategoryManager::HandleQuestManagerCreated(const ESubGame SubGame, UFortMcpProfileSubgame* McpProfile)
{
}

void UAthenaQuestCategoryManager::HandleQuestsCompleted(const TArray<UFortQuestItem*>& Quests)
{
}

void UAthenaQuestCategoryManager::HandleRebuildEvent()
{
}

void UAthenaQuestCategoryManager::HandleTeamMemberLeavingGame(const FUniqueNetIdRepl& LeavingPlayerId)
{
}

void UAthenaQuestCategoryManager::HandleTransientQuestAdded(const UFortQuestItem* QuestItem)
{
}

void UAthenaQuestCategoryManager::HandleTransientQuestRemoved(const UFortQuestItem* QuestItem)
{
}

void UAthenaQuestCategoryManager::HandleTransientQuestStarted(const UFortQuestItem* QuestItem, const UFortQuestItemDefinition_Athena* PreceedingQuestDefAthena)
{
}
