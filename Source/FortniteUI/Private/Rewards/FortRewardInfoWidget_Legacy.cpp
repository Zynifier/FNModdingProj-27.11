// Copyright Epic Games, Inc. All Rights Reserved.

#include "Rewards/FortRewardInfoWidget_Legacy.h"

UFortItem* UFortRewardInfoButton_Legacy::GetItemInstance() const
{
	return nullptr;
}

int32 UFortRewardInfoButton_Legacy::GetQuantity() const
{
	return int32();
}

void UFortRewardInfoButton_Legacy::SetItemInstanceQuantityPair(const FFortItemInstanceQuantityPair& ItemQuantityPair)
{
}

void UFortRewardInfoButton_Legacy::SetShowDescription(bool bInShowDescription)
{
}

bool UFortRewardInfoWidget_Legacy::ContainsReward(const FString& TemplateIdToCheck)
{
	return false;
}

void UFortRewardInfoWidget_Legacy::SetButtonGroup(UCommonButtonGroupLegacy* InButtonGroup)
{
}

void UFortRewardInfoWidget_Legacy::SetReward(const FFortItemQuantityPair& RewardIn)
{
}

void UFortRewardInfoWidget_Legacy::SetRewards(const FFortRewardInfo& RewardsIn)
{
}
