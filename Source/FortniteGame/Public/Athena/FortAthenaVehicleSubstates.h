// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortAthenaVehicleSubstates.generated.h"

UENUM()
enum class EBounceCompressionState : uint8
{
	None = 0,
	Crouching = 1,
	Crouched = 2,
	Jumping = 3,
	Recoiling = 4,
};

UENUM()
enum class ENaturalSlideState : uint8
{
	None = 0,
	//Not in power slide

	Entering = 1,
	//Entering power slide

	InProgress = 2,
	//Currently in power slide

	Exiting = 3,
};

UENUM()
enum class EPowerSlideState : uint8
{
	None = 0,
	//Not in power slide

	Entering = 1,
	//Entering power slide

	InProgress = 2,
	//Currently in power slide

	Exiting = 3,
};

USTRUCT()
struct FVehicleBounceState
{
	GENERATED_BODY()

public:
	UPROPERTY()
	EBounceCompressionState CompressionState;

	UPROPERTY()
	float CompressionValue;

	UPROPERTY()
	float StateCooldown;

};

