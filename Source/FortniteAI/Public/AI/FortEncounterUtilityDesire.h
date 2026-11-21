// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortEncounterUtilityDesire.generated.h"

UENUM()
namespace EFortEncounterUtilityDesire
{
	enum Type
	{
		Low = 0,
		Medium = 1,
		High = 2,
		VeryHigh = 3,
		Max_None = 4 UMETA(Hidden),
	};
}

