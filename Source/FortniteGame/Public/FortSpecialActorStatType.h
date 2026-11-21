// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortSpecialActorStatType.generated.h"

UENUM(BlueprintType)
enum class ESpecialActorStatType : uint8
{
	// stats for any generic actor

	NumEliminationsNearby = 0,
	TimeInWorld = 1,
	// stats for when the special actor is a FortPickup

	PickupNumSpawns = 2,
	PickupNumDespawns = 3,
	PickupNumDropped = 4,
	PickupNumTaken = 5,
	// stats for when the special actor is a player

	PlayerWon = 6,
	PlayerNumEliminations = 7,
	PlayerNum = 8,
	// used for array maintenance

	TotalStats = 9,
};

