// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortAthenaSKPushVehicleCoastState.generated.h"

UENUM()
enum class ECoastState : uint8
{
	Idle = 0,
	//feet on ground regular drive mode

	Mount = 1,
	//jump on cart and get ready to pedal

	Coasting = 2,
	//feet on cart, coasting

	Pedaling = 3,
	//applying push force on way to coasting

	PreDismount = 4,
	//time to give a chance to pedal again before dismounting (For example going from long coast to a single pedal)

	Dismount = 5,
	//play dismount animation, but don't apply any slowdown yet

	EndCoast = 6,
};

