// Copyright Epic Games, Inc. All Rights Reserved.

#include "Items/FortGadgetItemDefinition.h"

TSubclassOf<UFortGameplayAbility> UFortGadgetItemDefinition::GetGameplayAbility() const
{
	return TSubclassOf<UFortGameplayAbility>();
}

FGameplayAttribute UFortGadgetItemDefinition::GetLevelAttribute() const
{
	return FGameplayAttribute();
}

UFortWeaponItemDefinition* UFortGadgetItemDefinition::GetWeaponItemDefinition() const
{
	return nullptr;
}

bool UFortGadgetItemDefinition::HasChargeUp() const
{
	return false;
}

bool UFortGadgetItemDefinition::HasTrackedAttributes() const
{
	return false;
}
