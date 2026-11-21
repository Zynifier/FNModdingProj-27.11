// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "InputCoreTypes.h"
#include "FortSubGameTypes.h"
#include "FortActionKeyMapping.generated.h"

UENUM(BlueprintType)
enum class EFortInputActionGroup : uint8
{
	///////////////////////////
// AllModes SHOULD mean that the action will span across all modes, with exceptions below.

	AllModes = 0,
	///////////////////////////

	Combat = 1,
	///////////////////////////

	Building = 2,
	///////////////////////////

	Movement = 3,
	///////////////////////////

	Edit = 4,
	///////////////////////////

	Death = 5,
	///////////////////////////

	Cinematic = 6,
	///////////////////////////

	Picker = 7,
	///////////////////////////

	Other = 8,
	///////////////////////////

	Interaction = 9,
	///////////////////////////

	AthenaLTMAbilities = 10,
	///////////////////////////
///////////////////////////
// These shouldn't be changed by AllModes binding changes.
//	See UFortPlayerInput::AreInputActionGroupsOverlapping for more info on how they're used.

	ShoppingCart = 11,
	ShoppingCartDriver = 12,
	ShoppingCartPassenger = 13,
	Cannon = 14,
	CannonDriver = 15,
	CannonPassenger = 16,
	GolfCart = 17,
	GolfCartDriver = 18,
	GolfCartPassenger = 19,
	QuadCrasher = 20,
	QuadCrasherDriver = 21,
	QuadCrasherPassenger = 22,
	Biplane = 23,
	BiplaneDriver = 24,
	BiplaneGroundDriver = 25,
	BiplanePassenger = 26,
	Hamsterball = 27,
	Jackal = 28,
	Ostrich = 29,
	OstrichDriver = 30,
	OstrichPassenger = 31,
	Meatball = 32,
	MeatballDriver = 33,
	MeatballPassenger = 34,
	HoagieDriver = 35,
	Dagwood = 36,
	DagwoodDriver = 37,
	DagwoodPassenger = 38,
	Nevada = 39,
	NevadaDriver = 40,
	MountedTurret = 41,
	Spectating = 42,
	FullscreenMap = 43,
	CreativeAll = 44,
	CreativeModeratorMode = 45,
	CreativeMoveToolEquipped = 46,
	CreativeMoveObjectsFreely = 47,
	CreativeMoveBuildingsOnGrid = 48,
	CreativeFlying = 49,
	CreativeIslandPanel = 50,
	CreativeChair = 51,
	PropSelectorEquipped = 52,
	DBNOCarryStart = 53,
	DBNOCarryStop = 54,
	DBNOCarry = 55,
	InteractionStart = 56,
	InteractionStop = 57,
	BattleLab = 58,
	RemoteControl = 59,
	SuperDuper = 60,
	Tether = 61,
	Riding = 62,
	Tank = 63,
	TankDriver = 64,
	TankPassenger = 65,
	RockVehicle = 66,
	RockVehicleB = 67,
	Dirtbike = 68,
	DirtbikeDriver = 69,
	DirtbikePassenger = 70,
	Sportbike = 71,
	SportbikeDriver = 72,
	SportbikePassenger = 73,
	PlayerAugments = 74,
	Targeting = 75,
	///////////////////////////
// This is specifically for inputs that span across Combat and Building modes.

	CombatAndBuilding = 76,
	///////////////////////////
// This is specifically for inputs that span across Combat and Athena LTM Ability modes.

	CombatAndAthenaLTMAbilities = 77,
	///////////////////////////
// This is specifically for inputs that span across Combat, Building, and Athena LTM Ability modes.

	CombatBuildingAndAthenaLTMAbilities = 78,
	///////////////////////////

	MAX = 79,
};

USTRUCT()
struct FFortActionKeyMapping
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FName ActionName;

	UPROPERTY()
	EFortInputActionGroup ActionGroup;

	UPROPERTY()
	ESubGame SubGameUsedIn;

	UPROPERTY(Transient)
	FText LocalizedCategory;

	UPROPERTY(Transient)
	FText LocalizedName;

	UPROPERTY(Transient)
	FGameplayTag CategoryTag;

	UPROPERTY()
	FKey KeyBind1;

	UPROPERTY()
	FKey KeyBind2;

	UPROPERTY()
	float InputScale;

	UPROPERTY()
	bool bIsAxisMapping;

};

