// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortTargetSelectionEnums.generated.h"

UENUM(BlueprintType)
namespace EFortTargetSelectionFilter
{
	enum Type
	{
		Damageable = 0,
		Everything = 1,
		Pawns = 2,
		Buildings = 3,
		Walls = 4,
		Traps = 5,
		Players = 6,
		AIPawns = 7,
		Instigator = 8,
		WeakSpots = 9,
		World = 10,
		Max = 11,
	};
}

UENUM()
namespace EFortTargetSelectionShape
{
	enum Type
	{
		Sphere = 0,
		Cone = 1,
		Box = 2,
		Capsule = 3,
		Line = 4,
		Cylinder = 5,
		Custom = 6,
		CustomOnSource = 7,
	};
}

UENUM()
enum class EFortTargetSelectionTestType : uint8
{
	Overlap = 0,
	Swept = 1,
	Ballistic = 2,
};

