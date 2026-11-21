// Copyright Epic Games, Inc. All Rights Reserved.

#include "Rewards/FortRewardInfoWidget.h"

UFortItem* UFortRewardInfoButton::GetItemInstance() const
{
	return nullptr;
}

int32 UFortRewardInfoButton::GetQuantity() const
{
	return int32();
}

void UFortRewardInfoButton::SetItemInstanceQuantityPair(const FFortItemInstanceQuantityPair& ItemQuantityPair)
{
}

void UFortRewardInfoButton::SetShowDescription(bool bInShowDescription)
{
}

bool UFortRewardInfoWidget::ContainsReward(const FString& TemplateIdToCheck)
{
	return false;
}

void UFortRewardInfoWidget::SetButtonGroup(UCommonButtonGroupBase* InButtonGroup)
{
}

void UFortRewardInfoWidget::SetReward(const FFortItemQuantityPair& RewardIn)
{
}

void UFortRewardInfoWidget::SetRewards(const FFortRewardInfo& RewardsIn)
{
}
