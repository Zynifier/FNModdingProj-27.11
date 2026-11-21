// Copyright Epic Games, Inc. All Rights Reserved.

#include "BattlePassScreenS27.h"

FTimespan UBattlePassScreenS27::GetQuestPageDelay() const
{
	return FTimespan();
}

void UBattlePassScreenS27::GoBackOneScreen()
{
}

void UBattlePassScreenS27::HandleClaimRewardComplete(const bool bSuccess, const TArray<FString>& OfferTemplateIdList)
{
}

void UBattlePassScreenS27::HandleFullscreenMapToggled(bool bMapVisible)
{
}

void UBattlePassScreenS27::HandleSwitcherVisibilityShown()
{
}

bool UBattlePassScreenS27::IsSeasonalCustomizationItemOwned() const
{
	return false;
}

void UBattlePassScreenS27::OverviewShowAnimationFinished()
{
}
