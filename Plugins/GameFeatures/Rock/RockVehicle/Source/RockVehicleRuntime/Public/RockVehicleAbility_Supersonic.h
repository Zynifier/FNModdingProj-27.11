// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "RockScalableFloat.h"
#include "RockVehicleAbility.h"
#include "RockVehicleAbility_Supersonic.generated.h"

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FSupersonicTrailsActivate);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FSupersonicTrailsDeactivate);

UCLASS(BlueprintType, Blueprintable, meta=(BlueprintSpawnableComponent))
class ROCKVEHICLERUNTIME_API URockVehicleAbility_Supersonic : public URockVehicleAbility
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintAssignable)
	FSupersonicTrailsActivate OnTrailsActivate;

	UPROPERTY(BlueprintAssignable)
	FSupersonicTrailsDeactivate OnTrailsDeactivate;

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="RockVehicleAbility_Supersonic")
	FRockScalableFloat TurnOffTime;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="RockVehicleAbility_Supersonic")
	FRockScalableFloat TurnOnTime;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="RockVehicleAbility_Supersonic")
	bool bUseTurnOnTimeRequirement;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="RockVehicleAbility_Supersonic")
	FRockScalableFloat TurnOffSpeedBuffer;

	UPROPERTY(Transient)
	float TimeBelowSupersonic;

	UPROPERTY(Transient)
	float WorldTimeSupersonicExceeded;

};

