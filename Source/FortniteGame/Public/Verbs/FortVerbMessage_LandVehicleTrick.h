// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Verbs/FortVerbMessage_VehicleBase.h"
#include "FortVerbMessage_LandVehicleTrick.generated.h"

USTRUCT()
struct FFortVerbMessage_LandVehicleTrick : public FFortVerbMessage_VehicleBase
{
	GENERATED_BODY()

private:
	UPROPERTY(VisibleAnywhere, Category="FortVerbMessage_LandVehicleTrick")
	int32 PointsGained;

	UPROPERTY(VisibleAnywhere, Category="FortVerbMessage_LandVehicleTrick")
	int32 TrickCount;

	UPROPERTY(VisibleAnywhere, Category="FortVerbMessage_LandVehicleTrick")
	float AirDistance;

	UPROPERTY(VisibleAnywhere, Category="FortVerbMessage_LandVehicleTrick")
	float AirHeight;

	UPROPERTY(VisibleAnywhere, Category="FortVerbMessage_LandVehicleTrick")
	float AirTime;

};

