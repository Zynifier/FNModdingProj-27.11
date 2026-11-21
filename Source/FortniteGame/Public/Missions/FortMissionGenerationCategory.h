// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortMissionGenerationCategory.generated.h"

UENUM(BlueprintType)
namespace EMissionGenerationCategory
{
	enum Type
	{
		// Only one Primary mission can be running at a time

		Primary = 0,
		// Secondary missions can be started at any time

		Secondary = 1,
		// Needed to complete the zone

		Tertiary = 2,
		// Used for any survivor missions

		Survivor = 3,
		// Not defined yet or used for array length counts

		Max_None = 4 UMETA(DisplayName="None"),
	};
}

