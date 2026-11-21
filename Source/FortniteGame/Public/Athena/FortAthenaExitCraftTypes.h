// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortAthenaExitCraftTypes.generated.h"

UENUM(BlueprintType)
enum class EFortExitRequirements : uint8
{
	AnyPlayer = 0,
	WholeSquad = 1,
};

