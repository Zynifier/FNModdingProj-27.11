// Copyright Epic Games, Inc. All Rights Reserved.

#include "FortBattlePassContext.h"

bool UFortBattlePassContext::CanPurchaseBattlePassLevel() const
{
	return false;
}

FText UFortBattlePassContext::GetCurrentChapterAsText(const bool bFullText) const
{
	return FText();
}

FText UFortBattlePassContext::GetCurrentSeasonNumberAsText(const bool bFullText) const
{
	return FText();
}

FText UFortBattlePassContext::GetDefaultDisclaimerText() const
{
	return FText();
}

FText UFortBattlePassContext::GetLevelPurchaseDisclaimerText() const
{
	return FText();
}

TArray<FSeasonCurrencyMcpData> UFortBattlePassContext::GetSeasonalCurrencies() const
{
	return TArray<FSeasonCurrencyMcpData>();
}
