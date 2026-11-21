// Copyright Epic Games, Inc. All Rights Reserved.

#include "Quests/FortCheatManager_Quests.h"

void UFortCheatManager_Quests::CheckObjectiveStatUsage()
{
}

void UFortCheatManager_Quests::CheckQuestProcessorLoads() const
{
}

void UFortCheatManager_Quests::CompleteAccoladesByDisplayName(const FString DisplayNameSearchString)
{
}

void UFortCheatManager_Quests::CompleteAllQuestsByName(FString& QuestPartialName)
{
}

void UFortCheatManager_Quests::CompleteAllSquadMemberQuestsByName(FString& QuestPartialName)
{
}

void UFortCheatManager_Quests::CompleteQuestAndForceVictory(FString& QuestName)
{
}

void UFortCheatManager_Quests::CompleteQuestObjective(const FString ObjectiveName)
{
}

void UFortCheatManager_Quests::DebugDistanceTraveled(const EGameplayDebugState DebugState, const float InDelay, const bool bShowAll) const
{
}

void UFortCheatManager_Quests::DebugGameplayEvents(const EGameplayDebugState DebugState) const
{
}

void UFortCheatManager_Quests::DisableQuestStateLogging()
{
}

void UFortCheatManager_Quests::EnableQuestStateLogging()
{
}

void UFortCheatManager_Quests::ForceCompleteAccolades(float TimerDelay, bool bSkipAcknowledgements)
{
}

void UFortCheatManager_Quests::GiveAthenaXp(const float XpAmount)
{
}

void UFortCheatManager_Quests::GiveAthenaXpAtLocation(const float XpAmount, const FString DesiredPriority)
{
}

void UFortCheatManager_Quests::GrantAccolade(const FString& AccoladeName, const int32 AccoladeIndex)
{
}

void UFortCheatManager_Quests::GrantAndPinQuest(const FString QuestName, const EQuestParticipationScope QuestParticipationScope) const
{
}

void UFortCheatManager_Quests::GrantQuest(const FString QuestName, const EQuestParticipationScope QuestParticipationScope) const
{
}

void UFortCheatManager_Quests::ListActiveQuestContextTags()
{
}

void UFortCheatManager_Quests::ListChallenges(const FString& Filter) const
{
}

void UFortCheatManager_Quests::LogActiveTransientQuests()
{
}

void UFortCheatManager_Quests::LogCurrentQuests()
{
}

void UFortCheatManager_Quests::LogPinnedQuest()
{
}

void UFortCheatManager_Quests::LogQuestInfo(const FString& QuestName)
{
}

void UFortCheatManager_Quests::LogQuestManagerState(const EQuestParticipationScope ManagerScope)
{
}

void UFortCheatManager_Quests::LogRebootData()
{
}

void UFortCheatManager_Quests::LogSquadSharedQuestData() const
{
}

void UFortCheatManager_Quests::LogWorldReactions()
{
}

void UFortCheatManager_Quests::LogWorldStats()
{
}

void UFortCheatManager_Quests::OnXpEvent(const FXPEventInfo& XpEvent)
{
}

void UFortCheatManager_Quests::PinQuest(const FString& QuestName)
{
}

void UFortCheatManager_Quests::ProgressAllQuestsByName(FString& QuestPartialName, int32 Count)
{
}

void UFortCheatManager_Quests::ProgressQuestObjective(const FString ObjectiveName, const int32 Count)
{
}

void UFortCheatManager_Quests::QueryRebootData()
{
}

void UFortCheatManager_Quests::SendQuestEvent(FName Type, FString& TargetTag, FString& SourceTag, FString& ContextTag, int32 Count)
{
}

void UFortCheatManager_Quests::SetWorldStatCount(const FString& WorldStatName, const uint32 NewCount)
{
}

void UFortCheatManager_Quests::TeleportToBountyTarget()
{
}

void UFortCheatManager_Quests::TriggerWorldReactions(const FString& RowName)
{
}

void UFortCheatManager_Quests::UnpinQuest()
{
}
