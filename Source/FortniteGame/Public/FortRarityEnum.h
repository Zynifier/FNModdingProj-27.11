// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortRarityEnum.generated.h"

UENUM(BlueprintType)
enum class EFortRarity : uint8
{
	Common = 0 UMETA(DisplayName="Common (Grey)"),
	Uncommon = 1 UMETA(DisplayName="Uncommon (Green)"),
	Rare = 2 UMETA(DisplayName="Rare (Blue)"),
	Epic = 3 UMETA(DisplayName="Epic (Purple)"),
	Legendary = 4 UMETA(DisplayName="Legendary (Orange)"),
	Mythic = 5 UMETA(DisplayName="Mythic (Yellow)"),
	Transcendent = 6 UMETA(DisplayName="Transcendent (Pinkish)"),
	Unattainable = 7 UMETA(DisplayName="Unattainable T7"),
	// ALWAYS GOES AT THE END

	NumRarityValues = 8 UMETA(Hidden),
};

