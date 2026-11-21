// Copyright Epic Games, Inc. All Rights Reserved.

#include "Abilities/FortTargetSelectionInterface.h"

FTransform IFortTargetSelectionInterface::GetTargetingTransform(EFortAbilityTargetingSource Source, UFortGameplayAbility* SourceAbility) const
{
	return FTransform();
}
