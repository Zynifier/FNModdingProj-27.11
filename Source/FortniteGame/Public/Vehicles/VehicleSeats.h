// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "VehicleSeats.generated.h"

UENUM(BlueprintType)
enum class EVehicleSeats : uint8
{
	Driver = 0,
	Passenger1 = 1,
	Passenger2 = 2,
	Passenger3 = 3,
	Passenger4 = 4,
	Passenger5 = 5,
	Passenger6 = 6,
	MaxCount = 7,
};

