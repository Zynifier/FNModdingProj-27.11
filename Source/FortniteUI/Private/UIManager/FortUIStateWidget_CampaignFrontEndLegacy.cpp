// Copyright Epic Games, Inc. All Rights Reserved.

#include "UIManager/FortUIStateWidget_CampaignFrontEndLegacy.h"

bool UFortUIStateWidget_CampaignFrontendLegacy::AttemptToOpenBattlePassTabForNewSeason()
{
	return false;
}

bool UFortUIStateWidget_CampaignFrontendLegacy::CheckForGifts()
{
	return false;
}

void UFortUIStateWidget_CampaignFrontendLegacy::HandleGiftBoxRemoved(bool bSuccess)
{
}

void UFortUIStateWidget_CampaignFrontendLegacy::HandleGiftingComplete()
{
}

void UFortUIStateWidget_CampaignFrontendLegacy::HandleStoreStateChanged(EFortStoreState NewStoreState)
{
}

bool UFortUIStateWidget_CampaignFrontendLegacy::IsOkToCheckForGifts(bool& bTemporary)
{
	return false;
}

void UFortUIStateWidget_CampaignFrontendLegacy::QueueSurvivorSquadsAutoSlottedNotification()
{
}

bool UFortUIStateWidget_CampaignFrontendLegacy::ShowInitialCrossplayDialog()
{
	return false;
}

void UFortUIStateWidget_CampaignFrontendLegacy::SocialBanModalCheck()
{
}

void UFortUIStateWidget_CampaignFrontendLegacy::TryMFAModal(TSubclassOf<UEnableMultiFactorModal> BPClass)
{
}
