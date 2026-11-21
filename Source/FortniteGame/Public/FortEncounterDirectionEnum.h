// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortEncounterDirectionEnum.generated.h"

UENUM(BlueprintType)
namespace EFortEncounterDirection
{
	enum Type
	{
		North = 0,
		NorthEast = 1,
		East = 2,
		SouthEast = 3,
		South = 4,
		SouthWest = 5,
		West = 6,
		NorthWest = 7,
		Max_None = 8,
	};
}

