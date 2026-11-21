// Copyright Epic Games, Inc. All Rights Reserved.

#include "SeasonPass/BattlePassScreenBase.h"

bool UBattlePassScreenBase::CanEquipCurrentReward() const
{
	return false;
}

void UBattlePassScreenBase::EquipCurrentReward()
{
}

int32 UBattlePassScreenBase::GetNumberOfRewardsToPurchase() const
{
	return int32();
}

bool UBattlePassScreenBase::IsCurrentRewardEquipped() const
{
	return false;
}

bool UBattlePassScreenBase::IsCurrentRewardOwned() const
{
	return false;
}

bool UBattlePassScreenBase::ShouldPlayBPVideo(bool bAllowUpdate)
{
	return false;
}
