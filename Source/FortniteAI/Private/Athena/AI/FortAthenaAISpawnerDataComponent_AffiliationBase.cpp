// Copyright Epic Games, Inc. All Rights Reserved.

#include "Athena/AI/FortAthenaAISpawnerDataComponent_AffiliationBase.h"

bool UFortAthenaAISpawnerDataComponent_AffiliationBase::GetAwarenessPropagationIsBasedOnAlertLevel() const
{
	return false;
}

FGameplayTagContainer UFortAthenaAISpawnerDataComponent_AffiliationBase::GetFactionTag()
{
	return FGameplayTagContainer();
}

float UFortAthenaAISpawnerDataComponent_AffiliationBase::GetFullTeamAwarenessMaxDistance() const
{
	return float();
}

bool UFortAthenaAISpawnerDataComponent_AffiliationBase::GetFullTeamAwarenessPropagation() const
{
	return false;
}

bool UFortAthenaAISpawnerDataComponent_AffiliationBase::GetTeamID_Implementation(int32& OutTeamId) const
{
	return false;
}

void UFortAthenaAISpawnerDataComponent_AffiliationBase::SetAwarenessPropagationIsBasedOnAlertLevel(const bool bInAwarenessPropagationIsBasedOnAlertLevel)
{
}

void UFortAthenaAISpawnerDataComponent_AffiliationBase::SetFactionTags(const FGameplayTagContainer& NewTags)
{
}

void UFortAthenaAISpawnerDataComponent_AffiliationBase::SetFullTeamAwarenessPropagation(const bool bInFullTeamAwarenessPropagation)
{
}

void UFortAthenaAISpawnerDataComponent_AffiliationBase::SetFullTeamAwarenessPropagationDistance(const float InFullTeamAwarenessMaxDistance)
{
}

void UFortAthenaAISpawnerDataComponent_AffiliationBase::SetOverrideTeamIndex(const int32 InOverrideTeamIdx)
{
}
