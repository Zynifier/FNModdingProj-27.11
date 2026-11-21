// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortWorldMarkerTypeEnum.generated.h"

UENUM(BlueprintType)
enum class EFortWorldMarkerType : uint8
{
	/** Not a real marker type, I just use it to detect uninitialized markers, and errors in setup. */
	None = 0,
	Location = 1,
	Enemy = 2,
	Item = 3,
	Elimination = 4,
	/** Special items are created by gameplay code, and live as long as gameplay says they live. */
	SpecialLocal = 5,
	SpecialServer = 6,
	Teammate = 7,
	/** Used for ping commands. */
	PingGROUPSTART = 8 UMETA(Hidden),
	/* Dummy Value. Place any new values AFTER this*/
	PingGoTo = 9,
	PingHoldPosition = 10,
	PingNoIcon = 11,
	PingAttack = 12,
	PingGROUPEND = 13 UMETA(Hidden),
	/** Used for squad coms. */
	SquadComsGROUPSTART = 14 UMETA(Hidden),
	/* Dummy Value. Place any new values AFTER this*/
	SquadComsWatchArea = 15,
	SquadComsDefend = 16,
	SquadComsSomeonesHere = 17,
	SquadComsLootArea = 18,
	SquadComsAttack = 19,
	SquadComsGROUPEND = 20 UMETA(Hidden),
	/* Dummy Value. Place any new values BEFORE this*/
	MAX = 21 UMETA(Hidden),
};

