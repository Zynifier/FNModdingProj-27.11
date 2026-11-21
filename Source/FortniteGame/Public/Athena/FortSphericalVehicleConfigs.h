// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/FortPhysicsVehicleConfigs.h"
#include "FortSphericalVehicleConfigs.generated.h"

UCLASS(BlueprintType, Blueprintable)
class UFortSphericalVehicleConfigs : public UFortPhysicsVehicleConfigs
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Config, Category="Spherical Vehicle")
	bool bKeepPassengersUpright;

	UPROPERTY(EditDefaultsOnly, Config, Category="Spherical Vehicle|Water")
	bool bAdjustSpeedOnWaterEntry;

	UPROPERTY(EditDefaultsOnly, Config, Category="Spherical Vehicle|Water", meta=(EditCondition="bAdjustSpeedOnWaterEntry"))
	float MaxVerticalWaterEntrySpeedUp;

	UPROPERTY(EditDefaultsOnly, Config, Category="Spherical Vehicle|Water", meta=(EditCondition="bAdjustSpeedOnWaterEntry"))
	float MaxVerticalWaterEntrySpeedDown;

	UPROPERTY(EditDefaultsOnly, Config, Category="Spherical Vehicle|Water", meta=(EditCondition="bAdjustSpeedOnWaterEntry"))
	float MaxHorizontalWaterEntrySpeed;

};

