// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AthenaGamePhaseEnum.generated.h"

UENUM(BlueprintType)
enum class EAthenaGamePhase : uint8
{
	// Skip all game phases and just spawn players in.

	None = 0,
	// Game is setting up and no player spawning is allowed.

	Setup = 1,
	// Players can spawn but they take no damage.

	Warmup = 2,
	// Aircraft has started and players are spawned from aircraft.

	Aircraft = 3,
	// Safe zones have started and no player spawning is allowed.

	SafeZones = 4,
	// Only one player left.  Match is over.

	EndGame = 5,
	Count = 6,
};

