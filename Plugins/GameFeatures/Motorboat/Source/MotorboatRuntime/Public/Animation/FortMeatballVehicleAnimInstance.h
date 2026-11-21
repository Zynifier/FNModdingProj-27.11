// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "Animation/FortVehicleAnimInstance.h"
#include "FortMeatballVehicleAnimInstance.generated.h"

class AFortMeatballVehicle;

UCLASS(BlueprintType, Blueprintable, HideCategories=("AnimInstance"))
class UFortMeatballVehicleAnimInstance : public UFortVehicleAnimInstance
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerPawn")
	TObjectPtr<AFortMeatballVehicle> Meatball;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortMeatballVehicleAnimInstance")
	float MeatballSpeed;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortMeatballVehicleAnimInstance")
	float SteeringAngle;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortMeatballVehicleAnimInstance")
	float BoostCharge;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortMeatballVehicleAnimInstance")
	FVector SeatOffset;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortMeatballVehicleAnimInstance")
	FRotator SeatRotation;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortMeatballVehicleAnimInstance")
	FRotator CurrentDriveJiggle;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortMeatballVehicleAnimInstance")
	FRotator SteeringRotator;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortMeatballVehicleAnimInstance")
	FRotator SpeedGuageRotator;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortMeatballVehicleAnimInstance")
	FRotator BoostPercentRotator;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortMeatballVehicleAnimInstance")
	FRotator RandomJiggleRotatorMotorTop;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortMeatballVehicleAnimInstance")
	FRotator RandomJiggleRotatorMotorBase;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortMeatballVehicleAnimInstance")
	bool bIsMovingForward;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortMeatballVehicleAnimInstance")
	bool bIsDrivingFast;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortMeatballVehicleAnimInstance")
	bool bIsBraking;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortMeatballVehicleAnimInstance")
	bool bIsBoosting;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortMeatballVehicleAnimInstance")
	bool bIsBoostReady;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortMeatballVehicleAnimInstance")
	bool bIsBoostStarting;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortMeatballVehicleAnimInstance")
	bool bIsBoostEnding;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortMeatballVehicleAnimInstance")
	bool bIsRocketReady;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortMeatballVehicleAnimInstance")
	bool bIsRocketOnCoolDown;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortMeatballVehicleAnimInstance")
	bool bIsSteeringLeft;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortMeatballVehicleAnimInstance")
	bool bIsSteeringRight;

};

