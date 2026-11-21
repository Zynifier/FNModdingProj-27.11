// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortWeaponEnums.generated.h"

UENUM(BlueprintType)
enum class EFortWeaponReloadType : uint8
{
	ReloadWholeClip = 0,
	ReloadIndividualBullets = 1,
	ReloadBasedOnAmmoCostPerFire = 2,
	ReloadBasedOnCartridgePerFire = 3,
};

UENUM(BlueprintType)
namespace EFortWeaponTriggerType
{
	enum Type
	{
		OnPress = 0,
		Automatic = 1,
		OnRelease = 2,
		OnPressAndRelease = 3,
		Custom = 4,
	};
}

UENUM()
enum class EFortWeaponType : uint8
{
	None = 0,
	RangedAny = 1,
	Pistol = 2,
	Shotgun = 3,
	Rifle = 4,
	SMG = 5,
	Sniper = 6,
	GrenadeLauncher = 7,
	RocketLauncher = 8,
	Bow = 9,
	Minigun = 10,
	LMG = 11,
	BiplaneGun = 12,
	// add ranged types here

	MeleeAny = 13,
	Harvesting = 14,
	// add melee types here

	MAX = 15,
};

