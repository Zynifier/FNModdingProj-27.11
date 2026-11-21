// Copyright Epic Games, Inc. All Rights Reserved.

#include "Quests/FortQuestItem.h"

void UFortQuestItem::AdvanceSoundSequence()
{
}

bool UFortQuestItem::CanPinQuest() const
{
	return false;
}

bool UFortQuestItem::DoesQuestExpire() const
{
	return false;
}

void UFortQuestItem::GetAchievedCount(int32& OutTotalAchievedCount, int32& OutTotalRequiredCount, int32& OutLastKnownAchievedCount, bool UseLastKnownMcp) const
{
}

void UFortQuestItem::GetAchievedCountForCurrentStage(int32& OutTotalAchievedCount, int32& OutTotalRequiredCount) const
{
}

int32 UFortQuestItem::GetBarsRewardValue() const
{
	return int32();
}

FString UFortQuestItem::GetChallengeBundleId() const
{
	return FString();
}

FFortRewardInfo UFortQuestItem::GetChallengeChainRewardInfo(bool bGetCurrentChainQuestOnly) const
{
	return FFortRewardInfo();
}

UFortMissionConfigData* UFortQuestItem::GetMissionConfigData(const FGameplayTagContainer& InContainer)
{
	return nullptr;
}

int32 UFortQuestItem::GetNumObjectivesComplete() const
{
	return int32();
}

UFortQuestObjectiveInfo* UFortQuestItem::GetObjectiveInfo(FDataTableRowHandle ObjectiveStatHandle) const
{
	return nullptr;
}

float UFortQuestItem::GetPercentageComplete(const UFortQuestItemDefinition* KnownQuestDef) const
{
	return float();
}

TArray<FFortItemInstanceQuantityPair> UFortQuestItem::GetPreviewAllSelectableRewards() const
{
	return TArray<FFortItemInstanceQuantityPair>();
}

TArray<FFortItemInstanceQuantityPair> UFortQuestItem::GetPreviewRewards() const
{
	return TArray<FFortItemInstanceQuantityPair>();
}

TArray<FFortItemInstanceQuantityPair> UFortQuestItem::GetPreviewSelectableRewards(int32 RewardIndex) const
{
	return TArray<FFortItemInstanceQuantityPair>();
}

UFortQuestItemDefinition* UFortQuestItem::GetQuestDefinitionBP() const
{
	return nullptr;
}

FString UFortQuestItem::GetQuestPool() const
{
	return FString();
}

EFortQuestState UFortQuestItem::GetQuestState() const
{
	return EFortQuestState();
}

FTimespan UFortQuestItem::GetRemainingExpirationDuration(FDateTime UtcNow) const
{
	return FTimespan();
}

FFortRewardInfo UFortQuestItem::GetRewardInfo() const
{
	return FFortRewardInfo();
}

float UFortQuestItem::GetXpRewardScalar() const
{
	return float();
}

int32 UFortQuestItem::GetXpRewardValue(const UAthenaSeasonItemDefinition* SeasonDef, const AFortPlayerController* PlayerController) const
{
	return int32();
}

bool UFortQuestItem::HasCompletedAllObjectives(const bool bCheckForTurnInObjective) const
{
	return false;
}

bool UFortQuestItem::HasCompletedObjective(FDataTableRowHandle ObjectiveStatHandle) const
{
	return false;
}

bool UFortQuestItem::HasCompletedObjectiveWithName(FName BackendName) const
{
	return false;
}

bool UFortQuestItem::HasCompletedQuest() const
{
	return false;
}

bool UFortQuestItem::HasQuestExpired(FDateTime UtcNow) const
{
	return false;
}

bool UFortQuestItem::HasVisibleRewards() const
{
	return false;
}

bool UFortQuestItem::IsIncludedInCategories() const
{
	return false;
}

bool UFortQuestItem::IsObjectiveInProgress(FDataTableRowHandle ObjectiveStatHandle) const
{
	return false;
}

bool UFortQuestItem::IsObjectiveWithNameInProgress(FName BackendName) const
{
	return false;
}

bool UFortQuestItem::IsQuestInProgress() const
{
	return false;
}

bool UFortQuestItem::IsQuestPinned() const
{
	return false;
}

bool UFortQuestItem::IsVisibleToUser(const bool bAllowClaimedQuestsToBeVisible, const bool bAllowCompletedQuestsToBeVisible, const bool bAllowExpiredQuestsToBeVisible) const
{
	return false;
}

void UFortQuestItem::PlayCurrentSoundSequenceData()
{
}

void UFortQuestItem::PlayIntroConversation(TSubclassOf<AFortClientAnnouncement_Conversation> QuestConversationClass)
{
}

bool UFortQuestItem::ShouldDisplayOverallQuestInformation() const
{
	return false;
}

void UFortQuestItem::StartSoundSequenceDelay()
{
}
