// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortGameStateAthenaEnums.generated.h"

UENUM(BlueprintType)
enum class EAthenaAerialPhase : uint8
{
	None = 0,
	// The player is not in an aerial phase of the game.

	BusCantExit = 1,
	// The player is on the bus - can't jump.

	BusCanExit = 2,
	// The player is on the bus - can jump.

	BusCanExitEndZebulonDrone = 3,
	// The player is on the bus - can jump, but not the jump leader.

	Skydiving = 4,
	// The player is skydiving.

	Parachuting = 5,
	// The player is Parachuting.

	Falling = 6,
};

UENUM(BlueprintType)
enum class EAthenaGamePhaseStep : uint8
{
	None = 0,
	Setup = 1,
	Warmup = 2,
	GetReady = 3,
	BusLocked = 4,
	BusFlying = 5,
	StormForming = 6,
	StormHolding = 7,
	StormShrinking = 8,
	Countdown = 9,
	FinalCountdown = 10,
	EndGame = 11,
	Count = 12,
};

UENUM(BlueprintType)
enum class EAthenaStormCapState : uint8
{
	None = 0,
	Clear = 1,
	Warning = 2,
	Damaging = 3,
};

