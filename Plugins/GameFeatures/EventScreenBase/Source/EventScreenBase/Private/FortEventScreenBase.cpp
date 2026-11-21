// Copyright Epic Games, Inc. All Rights Reserved.

#include "FortEventScreenBase.h"

UFortEventModalBase* UFortEventScreenBase::GetActiveModal() const
{
	return nullptr;
}

UMaterialInstanceDynamic* UFortEventScreenBase::GetVaultWorldBackgroundMID() const
{
	return nullptr;
}

UMaterialInstanceDynamic* UFortEventScreenBase::GetVaultWorldFloorMID() const
{
	return nullptr;
}

void UFortEventScreenBase::HandleActiveSeasonDataChanged(const TArray<FString>& ActiveEventFlags)
{
}

void UFortEventScreenBase::HandleGiftBoxClosed()
{
}

void UFortEventScreenBase::HandleItemShown(const UFortAccountItemDefinition* AccountItemDef)
{
}

UWidget* UFortEventScreenBase::HandleRewardListNavigateRightEvent(EUINavigation InNavigation)
{
	return nullptr;
}

UWidget* UFortEventScreenBase::HandleRewardListNavigateUpEvent(EUINavigation InNavigation)
{
	return nullptr;
}

void UFortEventScreenBase::HandleToggleFullscreenMap(bool bVisible)
{
}

UWidget* UFortEventScreenBase::HandleUpsellPromptNavigateUpEvent(EUINavigation InNavigation)
{
	return nullptr;
}

bool UFortEventScreenBase::HasAllRewardsCollected() const
{
	return false;
}

bool UFortEventScreenBase::HasPurchasedPremiumTrack() const
{
	return false;
}

bool UFortEventScreenBase::IsCalendarEventActive(const FString& EventName) const
{
	return false;
}
