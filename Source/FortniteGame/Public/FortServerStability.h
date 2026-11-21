// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortServerStability.generated.h"

UENUM()
enum class EServerStability : uint8
{
	// Server is performing at the target FPS

	Stable = 0,
	// Server average FPS is below the target and has performance issues

	LowUnstability = 1,
	// Server FPS is very low and is having significant performance issues

	HighUnstability = 2,
	// Keep last

	Count = 3,
};

