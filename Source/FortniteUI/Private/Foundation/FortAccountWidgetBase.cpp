// Copyright Epic Games, Inc. All Rights Reserved.

#include "Foundation/FortAccountWidgetBase.h"

FText UFortAccountWidgetBase::GetCurrentChapterAsText() const
{
	return FText();
}

FText UFortAccountWidgetBase::GetCurrentSeasonNumberAsText() const
{
	return FText();
}

bool UFortAccountWidgetBase::GetNextSeasonChaseReward(FFortItemQuantityPair& Reward, int32& RewardLevel, int32 StartingLevel) const
{
	return false;
}

bool UFortAccountWidgetBase::GetNextSeasonReward(FFortItemQuantityPair& Reward, int32& RewardLevel) const
{
	return false;
}

FAthenaSeasonBannerLevel UFortAccountWidgetBase::GetSeasonBannerInfo(int32 Level) const
{
	return FAthenaSeasonBannerLevel();
}

void UFortAccountWidgetBase::HandleCurrentlyViewedAccountInfoChanged(FFortPublicAccountInfo NewInfo)
{
}
