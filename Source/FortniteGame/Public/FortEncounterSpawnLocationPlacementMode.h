// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortEncounterSpawnLocationPlacementMode.generated.h"

UENUM(BlueprintType)
namespace EFortEncounterSpawnLocationPlacementMode
{
	enum Type
	{
		Directional = 0,
		Ring = 1,
		// TODO

		Volume = 2,
		// TODO

		Custom = 3,
		// TODO

		Max_None = 4 UMETA(Hidden),
	};
}

