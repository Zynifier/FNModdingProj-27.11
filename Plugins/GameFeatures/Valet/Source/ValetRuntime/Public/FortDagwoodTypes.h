// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortDagwoodTypes.generated.h"

UENUM(BlueprintType)
enum class EControlsPrototypes : uint8
{
	CameraSteering = 0,
	NonCameraSteering = 1,
	HybridCameraSteering = 2,
	MaxCount = 3,
};

UENUM(BlueprintType)
enum class EPoppedTireReactionStates : uint8
{
	None = 0,
	VeerLeft = 1,
	// steering angle goes left for a duration

	VeerRight = 2,
	// steering angle goes right for a duration

	Wiggle = 3,
	// oscillate between left/right steering for a duration

	Yaw90 = 4,
	// yaw 90 degrees

	FlipPitch = 5,
	// pitch style flip, tail over head

	FlipRoll = 6,
};

UENUM(BlueprintType)
enum class ETireLocations : uint8
{
	FrontRight = 0,
	FrontLeft = 1,
	BackRight = 2,
	BackLeft = 3,
};

UENUM(BlueprintType)
enum class EVehicleClass : uint8
{
	Sedan = 0,
	Sport = 1,
	PickupTruck = 2,
	SemiTruck = 3,
};

