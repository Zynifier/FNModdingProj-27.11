// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Animation/FortVehicleAnimInstance.h"
#include "FortAntelopeVehicleAnimInstance.generated.h"

class AFortAthenaAntelopeVehicle;

UCLASS(BlueprintType, Blueprintable, HideCategories=("AnimInstance"))
class UFortAntelopeVehicleAnimInstance : public UFortVehicleAnimInstance
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerPawn")
	TObjectPtr<AFortAthenaAntelopeVehicle> AntelopeVehicle;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortAntelopeVehicleAnimInstance")
	float VehicleSpeed;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortAntelopeVehicleAnimInstance")
	bool bForwardSpeedIsNearlyZero;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortAntelopeVehicleAnimInstance")
	bool bForwardSpeedIsGreaterThanOne;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortAntelopeVehicleAnimInstance")
	bool bReverseSpeedIsGreaterThanOne;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortAntelopeVehicleAnimInstance")
	bool bSpeedIsGreaterThanFiveAndPlayerHitSpace;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortAntelopeVehicleAnimInstance")
	bool bIsBraking;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortAntelopeVehicleAnimInstance")
	bool bIsBoosting;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortAntelopeVehicleAnimInstance")
	bool bPlayerHitSpaceBar;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortAntelopeVehicleAnimInstance")
	float ChargingValue;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="ATV")
	float ChargingMax;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="ATV")
	float ChargingMin;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="ATV")
	float ChargingInterpSpeed;

};

