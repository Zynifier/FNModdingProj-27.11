// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "InventoryTypes.generated.h"

UENUM(BlueprintType)
enum class EVkInventoryMoveBehaviour : uint8
{
	SwapSlotNumber = 0,
	EmplaceSlotNumber = 1,
};

UENUM(BlueprintType)
enum class EVkInventoryMoveResult : uint8
{
	Success = 0,
	Failed = 1,
	//Was unable to perform the requested task (gameplay logic prevented it?).

	InvalidRequest = 2,
	//Request's parameters were rejected.

	NoChange = 3,
};

