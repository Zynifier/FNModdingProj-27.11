// Copyright Epic Games, Inc. All Rights Reserved.

#include "Abilities/FortAbilityTestObserver.h"

void AFortAbilityTestObserver::StartObserving(APawn* Pawn)
{
}

void AFortAbilityTestObserver::StopObserving()
{
}

bool AFortAbilityTestObserver::WasAbilityActivated(UGameplayAbility* Ability) const
{
	return false;
}

bool AFortAbilityTestObserver::WasAbilityTagActivated(const FGameplayTag& AbilityTag) const
{
	return false;
}
