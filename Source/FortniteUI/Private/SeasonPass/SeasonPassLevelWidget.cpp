// Copyright Epic Games, Inc. All Rights Reserved.

#include "SeasonPass/SeasonPassLevelWidget.h"

bool UFortSeasonPassLevelInfo::ContainsChaseReward(EAthenaSeasonRewardTrack Track) const
{
	return false;
}

int32 UFortSeasonPassLevelInfo::GetLevel() const
{
	return int32();
}

float UFortSeasonPassLevelInfo::GetLevelProgress() const
{
	return float();
}

int32 UFortSeasonPassLevelInfo::GetNumRewardItems(EAthenaSeasonRewardTrack Track) const
{
	return int32();
}

TArray<UFortItem*> UFortSeasonPassLevelInfo::GetRewardItems(EAthenaSeasonRewardTrack Track)
{
	return TArray<UFortItem*>();
}

int32 UFortSeasonPassLevelInfo::GetSeasonPassMaxLevel() const
{
	return int32();
}

bool UFortSeasonPassLevelInfo::IsFreeClaimed() const
{
	return false;
}

bool UFortSeasonPassLevelInfo::IsFreeUnlocked() const
{
	return false;
}

bool UFortSeasonPassLevelInfo::IsPaidClaimed() const
{
	return false;
}

bool UFortSeasonPassLevelInfo::IsPaidUnlocked() const
{
	return false;
}

UFortSeasonPassLevelInfo* USeasonPassLevelPanel::GetLevelInfo() const
{
	return nullptr;
}

void USeasonPassLevelPanel::Setup(UFortSeasonPassLevelInfo* Info)
{
}

void USeasonPassLevelWidget::AttemptClaim()
{
}

UFortSeasonPassLevelInfo* USeasonPassLevelWidget::GetLevelInfo() const
{
	return nullptr;
}
