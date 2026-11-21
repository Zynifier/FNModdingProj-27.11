// Copyright Epic Games, Inc. All Rights Reserved.

#include "Quests/QuestManagerComponents/FortQuestManagerComponent_Campaign.h"

int32 UFortQuestCategory::GetUnseenQuestCount()
{
	return int32();
}

bool UFortQuestCategory::HasUnseenQuests()
{
	return false;
}

void UFortQuestManagerComponent_Campaign::ClaimQuestReward(const UFortQuestItem* Quest) const
{
}

void UFortQuestManagerComponent_Campaign::ClaimSelectedQuestReward(const UFortQuestItem* Quest, int32 RewardIndex) const
{
}

void UFortQuestManagerComponent_Campaign::GetCurrentQuestsCategories(TArray<UFortQuestCategory*>& Categories)
{
}

UFortQuestItem* UFortQuestManagerComponent_Campaign::GetMainQuest() const
{
	return nullptr;
}

UFortQuestItem* UFortQuestManagerComponent_Campaign::GetNextUnseenQuest(EFortQuestType QuestType)
{
	return nullptr;
}

void UFortQuestManagerComponent_Campaign::GetPinnedQuests(TArray<UFortQuestItem*>& OutPinnedQuestItems)
{
}

const UFortQuestCategory* UFortQuestManagerComponent_Campaign::GetQuestCategory(UFortQuestItem* QuestItem)
{
	return nullptr;
}

EQuestMapScreenMode UFortQuestManagerComponent_Campaign::GetQuestMapMode() const
{
	return EQuestMapScreenMode();
}

void UFortQuestManagerComponent_Campaign::GetQuestsFromCategory(UFortQuestCategory* Category, TArray<UFortQuestItem*>& QuestList)
{
}

int32 UFortQuestManagerComponent_Campaign::GetRemainingDailyQuestRerolls() const
{
	return int32();
}

int32 UFortQuestManagerComponent_Campaign::GetRemainingQuestPoolRerolls(const FString& PoolName) const
{
	return int32();
}

int32 UFortQuestManagerComponent_Campaign::GetUnseenQuestCount()
{
	return int32();
}

void UFortQuestManagerComponent_Campaign::GrantFirstDailyQuest()
{
}

void UFortQuestManagerComponent_Campaign::HandleQuestObjectiveUpdated(AFortPlayerController* QuestOwner, const UFortQuestItemDefinition* QuestDef, FName BackendName, int32 CompletionCount, int32 DeltaChange, const AFortPlayerState* AssistingPlayer, const EFortQuestObjectiveStatEvent StatEvent)
{
}

bool UFortQuestManagerComponent_Campaign::HasQuestBeenSeenLocally(const UFortQuestItem* Quest) const
{
	return false;
}

bool UFortQuestManagerComponent_Campaign::HasUnsavedPrimaryMissionProgress() const
{
	return false;
}

bool UFortQuestManagerComponent_Campaign::HasUnseenQuests()
{
	return false;
}

bool UFortQuestManagerComponent_Campaign::IsMainQuest(UFortQuestItem* Quest) const
{
	return false;
}

bool UFortQuestManagerComponent_Campaign::IsPendingFeatureUnlockNotification() const
{
	return false;
}

bool UFortQuestManagerComponent_Campaign::IsThisAnEventQuest(const UFortQuestItemDefinition* QuestDefinition, const FString& MatchQuestEventFlag, UDataTable* QuestTable) const
{
	return false;
}

void UFortQuestManagerComponent_Campaign::MarkQuestSeen(UFortQuestItem* Quest)
{
}

void UFortQuestManagerComponent_Campaign::MarkQuestsSeen(bool bOnlyMarkPendingSeenQuests) const
{
}

FString UFortQuestManagerComponent_Campaign::PopNextPendingFeatureUnlock()
{
	return FString();
}

void UFortQuestManagerComponent_Campaign::RerollDailyQuest(const UFortQuestItem* QuestToDiscard) const
{
}

void UFortQuestManagerComponent_Campaign::SetQuestMapMode(EQuestMapScreenMode NewQuestMapMode)
{
}

bool UFortQuestManagerComponent_Campaign::SetQuestPinned(UFortQuestItem* Quest, bool bEnabled)
{
	return false;
}
