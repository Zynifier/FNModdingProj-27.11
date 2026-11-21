// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/FortAbilitySetHandle.h"
#include "FortEquippedWeaponModSlot.generated.h"

class UFortWeaponModItemDefinition;

USTRUCT()
struct FFortEquippedWeaponModSlot
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	FFortAbilitySetHandle EquippedAbilitySetHandle;

	UPROPERTY(Transient)
	TObjectPtr<UFortWeaponModItemDefinition> EquippedWeaponMod;

};

