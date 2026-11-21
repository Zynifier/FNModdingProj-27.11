// Copyright Epic Games, Inc. All Rights Reserved.

#include "Abilities/FortPlayerBountyGameplayAbility.h"

void UFortPlayerBountyGameplayAbility::BountyPoached()
{
}

void UFortPlayerBountyGameplayAbility::CleanupBountyHunter() const
{
}

void UFortPlayerBountyGameplayAbility::CleanupBountyProtector() const
{
}

void UFortPlayerBountyGameplayAbility::CleanupBountyTarget() const
{
}

bool UFortPlayerBountyGameplayAbility::GetIsPrimaryHunter() const
{
	return false;
}

const TArray<AFortPlayerStateAthena*> UFortPlayerBountyGameplayAbility::GetTrackedBountyHunters() const
{
	return TArray<AFortPlayerStateAthena*>();
}

AFortPlayerStateAthena* UFortPlayerBountyGameplayAbility::GetTrackedHunterBountyTarget() const
{
	return nullptr;
}

AFortPlayerStateAthena* UFortPlayerBountyGameplayAbility::GetTrackedPrimaryHunter() const
{
	return nullptr;
}

AFortPlayerStateAthena* UFortPlayerBountyGameplayAbility::GetTrackedProtectorBountyTarget() const
{
	return nullptr;
}

void UFortPlayerBountyGameplayAbility::SpectatorCompleteUrgentQuest(const FUrgentQuestData& UrgentQuestData, const FGameplayTag& CompletedEventTag)
{
}

void UFortPlayerBountyGameplayAbility::SpectatorFailUrgentQuest(const FUrgentQuestData& UrgentQuestData, const FGameplayTag& FailedEventTag)
{
}

void UFortPlayerBountyGameplayAbility::SpectatorShowUrgentQuestMessage(const FUrgentQuestData& UrgentQuestData)
{
}

void UFortPlayerBountyGameplayAbility::StartPlayerDuel() const
{
}
