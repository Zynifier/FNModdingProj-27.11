// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortHeliFlightModel.generated.h"

class UFortHoagieVehicleConfigs;

UENUM(BlueprintType)
enum class EHoagieBoostState : uint8
{
	Unknown = 0,
	Ready = 1,
	Started = 2,
	Finished = 3,
	Failed = 4,
};

UENUM()
enum class EHoagieState : int32
{
	STARTUP = 0,
	STARTUP_LIFT = 1,
	FLIGHT = 2,
	AUTO_LANDING = 3,
	SPIN_CRASHING = 4,
	CRASHING_NO_SPIN = 5,
	CRASH_LANDED = 6,
	LANDED = 7,
	EXPLODING = 8,
	NONE = 9,
};

USTRUCT(BlueprintType, meta=(IsBlueprintBase="true"))
struct FFortHeliFlightModel
{
	GENERATED_BODY()

private:
	UPROPERTY(Transient)
	TObjectPtr<UFortHoagieVehicleConfigs> Configs;

};

