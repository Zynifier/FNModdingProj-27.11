// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Attributes/FortAttributeSet.h"
#include "FortVehicleMovementSet.generated.h"

UCLASS(BlueprintType)
class UFortVehicleMovementSet : public UFortAttributeSet
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="Movement")
	FFortGameplayAttributeData FrontLateralFrictionScale;

	UPROPERTY(BlueprintReadOnly, Category="Movement")
	FFortGameplayAttributeData RearLateralFrictionScale;

	UPROPERTY(BlueprintReadOnly, Category="Movement")
	FFortGameplayAttributeData BrakeForceTractionScale;

	UPROPERTY(BlueprintReadOnly, Category="Movement")
	FFortGameplayAttributeData ForwardForceTractionScale;

	UPROPERTY(BlueprintReadOnly, Category="Movement")
	FFortGameplayAttributeData SlopeAntigravityScale;

	UPROPERTY(BlueprintReadOnly, Category="Movement")
	FFortGameplayAttributeData TopSpeedScale;

	UPROPERTY(BlueprintReadOnly, Category="Movement")
	FFortGameplayAttributeData VehicleGravityScale;

	UPROPERTY(BlueprintReadOnly, Category="Movement")
	FFortGameplayAttributeData BrakeBeforeReverse;

};

