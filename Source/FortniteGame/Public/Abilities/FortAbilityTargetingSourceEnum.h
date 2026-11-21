// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortAbilityTargetingSourceEnum.generated.h"

UENUM(BlueprintType)
enum class EFortAbilityTargetingSource : uint8
{
	// From the player's camera towards camera focus

	Camera = 0,
	// From the pawn's center, in the pawn's orientation

	PawnForward = 1,
	// From the pawn's center, oriented towards camera focus

	PawnTowardsFocus = 2,
	// From the weapon's muzzle or location, in the pawn's orientation

	WeaponForward = 3,
	// From the weapon's muzzle or location, towards camera focus

	WeaponTowardsFocus = 4,
	// Custom blueprint-specified source location

	Custom = 5,
	Max_None = 6 UMETA(DisplayName="None"),
};

