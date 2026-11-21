// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortAIUtility.generated.h"

UENUM(BlueprintType)
namespace EFortAIUtility
{
	enum Type
	{
		KillPlayersMelee = 0 UMETA(DisplayName="Kill Players Melee"),
		KillPlayersRanged = 1 UMETA(DisplayName="Kill Players Ranged"),
		KillPlayersArtillery = 2 UMETA(DisplayName="Kill Players Artillery"),
		DestroyBuildingsMelee = 3 UMETA(DisplayName="Destroy Buildings Melee"),
		DestroyBuildingsRanged = 4 UMETA(DisplayName="Destroy Buildings Ranged"),
		DestroyBuildingsArtillery = 5 UMETA(DisplayName="Destroy Buildings Artillery"),
		DestroyTraps = 6 UMETA(DisplayName="Destroy Traps"),
		Tank = 7 UMETA(DisplayName="Distract: Tank"),
		Infiltrate = 8 UMETA(DisplayName="Distract: Infiltrate"),
		Mob = 9 UMETA(DisplayName="Distract: Mob"),
		Support = 10 UMETA(DisplayName="Distract: Support"),
		Kiting = 11 UMETA(DisplayName="Distract: Kiting"),
		AreaOfDenial = 12 UMETA(DisplayName="Distract: Area of Denial"),
		DisableTraps = 13 UMETA(DisplayName="Distract: Disable Traps"),
		Dormant = 14 UMETA(DisplayName="Distract: Dormant"),
		Assassin = 15 UMETA(DisplayName="Assassin"),
		//CaptureCarry UMETA(DisplayName = "Capture Carrier"),

		MAX = 16 UMETA(DisplayName="Invalid"),
	};
}

