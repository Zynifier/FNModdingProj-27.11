// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortMovementEnums.generated.h"

UENUM(BlueprintType)
namespace EFortMovementStyle
{
	enum Type
	{
		Running = 0,
		Walking = 1,
		Charging = 2,
		Sprinting = 3,
		PersonalVehicle = 4,
		Flying = 5,
		Tethered = 6,
	};
}

UENUM(BlueprintType)
namespace EFortMovementUrgency
{
	enum Type
	{
		None = 0,
		Low = 1,
		Medium = 2,
		High = 3,
		NumLevels = 4 UMETA(DisplayName="Invalid"),
	};
}

