// Copyright Epic Games, Inc. All Rights Reserved.

#include "Athena/AI/FortAthenaAISpawnerDataComponent_GameplayAbilityBase.h"

void UFortAthenaAISpawnerDataComponent_GameplayAbilityBase::GetInitialGameplayAbilities_Implementation(TArray<UFortAbilitySet*>& OutGASets) const
{
}

void UFortAthenaAISpawnerDataComponent_GameplayAbilityBase::GetInitialGameplayEffects_Implementation(TArray<FInitialGameplayEffectInfo>& OutGEs) const
{
}

FGameplayTagContainer UFortAthenaAISpawnerDataComponent_GameplayAbilityBase::GetLooseTagsToApplyToPawn() const
{
	return FGameplayTagContainer();
}

void UFortAthenaAISpawnerDataComponent_GameplayAbilityBase::SetLooseTagsToApplyToPawn(const FGameplayTagContainer& InGameplayTagContainer)
{
}
