// Copyright Epic Games, Inc. All Rights Reserved.

#include "STW/Expeditions/FortExpeditionItem.h"

void UFortExpeditionItem::GetBonusCriteriaBP(TArray<FFortCriteriaRequirementData>& OutBonusCriteria) const
{
}

void UFortExpeditionItem::GetBonusCriteriaTags(TArray<FGameplayTag>& OutBonusCriteria) const
{
}

FName UFortExpeditionItem::GetExpeditionSquadId() const
{
	return FName();
}

float UFortExpeditionItem::GetExpeditionSuccessChance() const
{
	return float();
}

float UFortExpeditionItem::GetMinTargetPowerLevelToBegin() const
{
	return float();
}

FTimespan UFortExpeditionItem::GetRemainingExpeditionDuration(FDateTime UtcNow) const
{
	return FTimespan();
}

FTimespan UFortExpeditionItem::GetRemainingExpeditionExpirationDuration(FDateTime UtcNow) const
{
	return FTimespan();
}

float UFortExpeditionItem::GetTargetPowerLevel() const
{
	return float();
}

bool UFortExpeditionItem::HasExpeditionExpired(FDateTime UtcNow) const
{
	return false;
}

bool UFortExpeditionItem::IsExpeditionCompleted(FDateTime UtcNow) const
{
	return false;
}

bool UFortExpeditionItem::IsExpeditionInProgress() const
{
	return false;
}
