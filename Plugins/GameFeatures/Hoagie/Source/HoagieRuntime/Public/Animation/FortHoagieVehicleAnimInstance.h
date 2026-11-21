// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "Animation/FortAnimTypes.h"
#include "Animation/FortVehicleAnimInstance.h"
#include "FortHoagieVehicleAnimInstance.generated.h"

UCLASS(MinimalAPI, BlueprintType, Blueprintable, HideCategories=("AnimInstance"))
class UFortHoagieVehicleAnimInstance : public UFortVehicleAnimInstance
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Transient, Category="FortHoagieVehicleAnimInstance")
	FRotator EngineRotation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category="FortHoagieVehicleAnimInstance")
	FRotator MainRotorRotation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category="FortHoagieVehicleAnimInstance")
	FRotator TailRotorRotaton;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortHoagieVehicleAnimInstance")
	FRotator BoosterFanRotation;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortHoagieVehicleAnimInstance")
	EFortCardinalDirection BoostCardinalDirection;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortHoagieVehicleAnimInstance")
	float EngineRotationInterpSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortHoagieVehicleAnimInstance")
	float EngineRotationDuringBoostInterpSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortHoagieVehicleAnimInstance")
	float EngineFlipSpeedThreshold;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortHoagieVehicleAnimInstance")
	float BoostDirectionDeadzone;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortHoagieVehicleAnimInstance")
	float EngineFlipDeadzone;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortHoagieVehicleAnimInstance")
	float DriverRoll;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortHoagieVehicleAnimInstance")
	float DriverYaw;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortHoagieVehicleAnimInstance")
	float VerticalSpeed;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortHoagieVehicleAnimInstance")
	float FwdSpeed;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortHoagieVehicleAnimInstance")
	float LocalBoostDirection;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortHoagieVehicleAnimInstance")
	float YawBlendSpaceInput;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortHoagieVehicleAnimInstance")
	float NormalizedAcceleration;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortHoagieVehicleAnimInstance")
	bool bShouldHideBlades;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortHoagieVehicleAnimInstance")
	bool bIsBoostOnCD;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortHoagieVehicleAnimInstance")
	bool bIsBoostReady;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortHoagieVehicleAnimInstance")
	bool bIsMovingForward;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortHoagieVehicleAnimInstance")
	bool bIsReversing;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortHoagieVehicleAnimInstance")
	bool bIsMovingAnyDirection;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortHoagieVehicleAnimInstance")
	bool bIsBoosting;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortHoagieVehicleAnimInstance")
	bool bShouldReverse;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortHoagieVehicleAnimInstance")
	bool bShouldGoBackToIdle;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortHoagieVehicleAnimInstance")
	bool bShouldApplyBoostAdditive;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortHoagieVehicleAnimInstance")
	bool bIsEngineShuttingOff;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortHoagieVehicleAnimInstance")
	bool bTransition_Default_ReverseStart;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortHoagieVehicleAnimInstance")
	bool bTransition_BoostLoop_Reverse;

};

