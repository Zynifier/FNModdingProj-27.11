// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortDeathCauseEnum.generated.h"

UENUM(BlueprintType, meta=(IsBlueprintBase="true"))
enum class EDeathCause : uint8
{
	OutsideSafeZone = 0,
	FallDamage = 1,
	Pistol = 2,
	Shotgun = 3,
	Rifle = 4,
	SMG = 5,
	Sniper = 6,
	SniperNoScope = 7,
	Melee = 8,
	InfinityBlade = 9,
	Grenade = 10,
	C4 = 11,
	GrenadeLauncher = 12,
	RocketLauncher = 13,
	Minigun = 14,
	Bow = 15,
	Trap = 16,
	DBNOTimeout = 17,
	Banhammer = 18,
	RemovedFromGame = 19,
	MassiveMelee = 20,
	MassiveDiveBomb = 21,
	MassiveRanged = 22,
	Vehicle = 23,
	ShoppingCart = 24,
	ATK = 25,
	QuadCrasher = 26,
	Biplane = 27,
	BiplaneGun = 28,
	LMG = 29,
	GasGrenade = 30,
	InstantEnvironmental = 31,
	InstantEnvironmentalFellOutOfWorld = 32,
	InstantEnvironmentalUnderLandscape = 33,
	Turret = 34,
	ShipCannon = 35,
	/** Special Deaths */
	Cube = 36,
	Balloon = 37,
	StormSurge = 38,
	Lava = 39,
	/** AI Deaths */
	BasicFiend = 40,
	EliteFiend = 41,
	RangedFiend = 42,
	BasicBrute = 43,
	EliteBrute = 44,
	MegaBrute = 45,
	/** Switching to spectator from a living player. */
	SilentSwitchingToSpectate = 46,
	/** no need to update ToDeathCause and GetWeaponTypeFromDeathCause for logout situation */
	LoggedOut = 47,
	TeamSwitchSuicide = 48,
	WonMatch = 49,
	Unspecified = 50,
};

