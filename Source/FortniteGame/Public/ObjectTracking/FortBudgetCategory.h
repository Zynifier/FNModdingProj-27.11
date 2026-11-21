// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortBudgetCategory.generated.h"

UENUM(BlueprintType)
enum class EFortBudgetCategory : uint8
{
	/** Memory cost */
	Memory = 0,
	/** World tick CPU cost */
	Simulation = 1,
	/** Client render cost (draw call ) */
	Rendering = 2,
	/** Server network cost */
	Network = 3,
	/** Client audio cost */
	Audio = 4,
	Max = 5,
};

