// Copyright Epic Games, Inc. All Rights Reserved.

#include "Context/AthenaAccountContext.h"

void UAthenaAccountContext::GetBattleBookPurchaseLimit(int32& MaxNumLevelsPossibleToPurchase, int32& BonusLevelsGranted)
{
}

FText UAthenaAccountContext::GetCurrentChapterAndSeasonText() const
{
	return FText();
}

FText UAthenaAccountContext::GetCurrentChapterNumberAsText(bool bFullText) const
{
	return FText();
}

UAthenaSeasonItemDefinition* UAthenaAccountContext::GetCurrentSeasonDefinition()
{
	return nullptr;
}

int32 UAthenaAccountContext::GetCurrentSeasonNumber() const
{
	return int32();
}

FText UAthenaAccountContext::GetCurrentSeasonNumberAsText(bool bFullText) const
{
	return FText();
}

bool UAthenaAccountContext::IsAtMaxBattlePassTier() const
{
	return false;
}

bool UAthenaAccountContext::ShouldReplaceBattleStarsWithAlternateReward() const
{
	return false;
}

void UAthenaAccountContext::SimulateBattleBookPurchase(int32 NumLevelsToPurchase, int32& BonusLevelsGranted, bool& bOverLimit)
{
}
