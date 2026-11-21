// Copyright Epic Games, Inc. All Rights Reserved.

#include "Rewards/FortRewardNotificationWidget.h"

void UFortRewardNotificationWidget::AddCollectionBookData(const FFortCollectionBookRewards& CollectionBookRewards)
{
}

void UFortRewardNotificationWidget::AddDifficultyIncreaseRewardData()
{
}

void UFortRewardNotificationWidget::AddEpicQuestData(UFortQuestItem* Quest)
{
}

void UFortRewardNotificationWidget::AddExpeditionData(UFortExpeditionItem* ExpeditionItem)
{
}

void UFortRewardNotificationWidget::AddGiftBoxData()
{
}

void UFortRewardNotificationWidget::AddItemCacheRewardData(UFortItem* ItemCache)
{
}

void UFortRewardNotificationWidget::AddMissionAlertData()
{
}

void UFortRewardNotificationWidget::AddMissionData()
{
}

void UFortRewardNotificationWidget::AddPhoenixLevelUpRewardData()
{
}

void UFortRewardNotificationWidget::AddQuestData(UFortQuestItem* Quest)
{
}

void UFortRewardNotificationWidget::BeginCloseRewardsScreen()
{
}

void UFortRewardNotificationWidget::HandleOnCollectionBookRewardClaimed(FFortCollectionBookRewards RewardClaimed, bool bSuccess, const TArray<FFortItemInstanceQuantityPair>& ActualRewards)
{
}

void UFortRewardNotificationWidget::HandleOnDifficultyIncreaseRewardsClaimed(const TArray<FFortItemInstanceQuantityPair>& DifficultyRewards)
{
}

void UFortRewardNotificationWidget::HandleOnDifficultyIncreaseRewardsClaimFailed()
{
}

void UFortRewardNotificationWidget::HandleOnItemCacheRewardsClaimed(const TArray<FFortItemInstanceQuantityPair>& ClaimedRewards)
{
}

void UFortRewardNotificationWidget::HandleOnItemCacheRewardsClaimFailed()
{
}

void UFortRewardNotificationWidget::HandleOnMissionAlertRewardsOpened(const TArray<FFortItemInstanceQuantityPair>& AlertRewards)
{
}

void UFortRewardNotificationWidget::HandleOnMissionRewardsOpened(const TArray<FFortItemInstanceQuantityPair>& MissionRewards)
{
}

void UFortRewardNotificationWidget::HandleOnMissionRewardsOpenFailed()
{
}

void UFortRewardNotificationWidget::HandleOnNoQuestRewardsToClaim()
{
}

void UFortRewardNotificationWidget::HandleOnQuestRewardClaimed(const UFortQuestItem* Quest, const TArray<FFortItemInstanceQuantityPair>& Rewards)
{
}

void UFortRewardNotificationWidget::HideMulchConfirmationModal()
{
}

void UFortRewardNotificationWidget::IsPrimaryActionEnabled(bool& bEnabled)
{
}

void UFortRewardNotificationWidget::IsPrimaryActionHidden(bool& bHidden)
{
}

void UFortRewardNotificationWidget::MarkDefaultItemsForMulch(const TArray<FFortItemInstanceQuantityPair> ItemList)
{
}

void UFortRewardNotificationWidget::NotifyPanelActivated()
{
}

void UFortRewardNotificationWidget::NotifyPanelDeactivated()
{
}

void UFortRewardNotificationWidget::PopulateReward(const UFortRewardNotificationData* Reward)
{
}

void UFortRewardNotificationWidget::ResetAllRewardData()
{
}

void UFortRewardNotificationWidget::SetPrimaryActionEnabled(bool bEnabled)
{
}

void UFortRewardNotificationWidget::SetPrimaryActionHidden()
{
}

void UFortRewardNotificationWidget::SetPrimaryActionText(FText Text)
{
}

void UFortRewardNotificationWidget::ShowMulchConfirmationModal()
{
}
