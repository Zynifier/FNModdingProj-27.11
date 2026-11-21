// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortMobileInteractionIconTypes.generated.h"

UENUM(BlueprintType)
enum class EMobileInteractionIconTypes : uint8
{
	Interact = 0,
	Swap = 1,
	Revive = 2,
	Blocked = 3,
	MAX = 4,
};

