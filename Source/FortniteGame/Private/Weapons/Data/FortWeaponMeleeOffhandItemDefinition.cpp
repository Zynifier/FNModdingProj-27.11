// Copyright Epic Games, Inc. All Rights Reserved.

#include "Weapons/Data/FortWeaponMeleeOffhandItemDefinition.h"

TSubclassOf<UFortGameplayAbility> UFortWeaponMeleeOffhandItemDefinition::GetPrimaryOffhandFireAbility() const
{
	return TSubclassOf<UFortGameplayAbility>();
}

TSubclassOf<UFortGameplayAbility> UFortWeaponMeleeOffhandItemDefinition::GetSecondaryOffhandFireAbility() const
{
	return TSubclassOf<UFortGameplayAbility>();
}
