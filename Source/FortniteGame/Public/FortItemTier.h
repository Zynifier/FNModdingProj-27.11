// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortItemTier.generated.h"

UENUM(BlueprintType)
enum class EFortItemTier : uint8
{
	No_Tier = 0,
	I = 1,
	II = 2,
	III = 3,
	IV = 4,
	V = 5,
	VI = 6,
	VII = 7,
	VIII = 8,
	IX = 9,
	X = 10,
	// ALWAYS GOES AT THE END

	NumItemTierValues = 11 UMETA(Hidden),
};

