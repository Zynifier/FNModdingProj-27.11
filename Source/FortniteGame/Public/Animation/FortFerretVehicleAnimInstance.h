// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "Animation/FortAnimTypes.h"
#include "Animation/FortVehicleAnimInstance.h"
#include "FortFerretVehicleAnimInstance.generated.h"

class AFortAthenaFerretVehicle;

UCLASS(BlueprintType, Blueprintable, HideCategories=("AnimInstance"))
class UFortFerretVehicleAnimInstance : public UFortVehicleAnimInstance
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerPawn")
	TObjectPtr<AFortAthenaFerretVehicle> FerretVehicle;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortFerretVehicleAnimInstance")
	FRotator FerretVehicleSpeed;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortFerretVehicleAnimInstance")
	bool bForwardSpeedIsNearlyZero;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortFerretVehicleAnimInstance")
	bool bForwardSpeedIsGreaterThanOne;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortFerretVehicleAnimInstance")
	bool bReverseSpeedIsGreaterThanOne;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortFerretVehicleAnimInstance")
	bool bSpeedIsGreaterThanFiveAndPlayerHitSpace;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortFerretVehicleAnimInstance")
	bool bIsBraking;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortFerretVehicleAnimInstance")
	bool bIsBoosting;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortFerretVehicleAnimInstance")
	bool bIsBoostReady;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortFerretVehicleAnimInstance")
	bool bPlayerHitSpaceBar;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortFerretVehicleAnimInstance")
	bool bOnGround;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortFerretVehicleAnimInstance")
	FVector ControlTorque;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortFerretVehicleAnimInstance")
	FRotator RudderAngle;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortFerretVehicleAnimInstance")
	FRotator AileronAngle;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortFerretVehicleAnimInstance")
	FRotator ElevatorAngle;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortFerretVehicleAnimInstance")
	FRotator FlapAngle;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortFerretVehicleAnimInstance")
	FRotator Altitude;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortFerretVehicleAnimInstance")
	float SteerPitchAngle;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortFerretVehicleAnimInstance")
	FRotator PropellorAngle;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortFerretVehicleAnimInstance")
	FRotator BoostPercent;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FerretDriver")
	EPlaneDirection FerretCardinalDirection;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FerretDriver")
	float ElevatorDeadZone;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FerretDriver")
	float RudderDeadZone;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FerretDriver")
	bool bFerretShouldPlayStartTransition;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FerretDriver")
	bool bFerretShouldPlayStopTransition;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FerretDriver")
	EPlaneDirection FerretStopCardinalDirection;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FerretDriver")
	EPlaneDirection FerretPrePivotCardinalDirection;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FerretDriver")
	bool bFerretShouldPlayPivotTransition;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FerretDriver")
	float AbsSteerAngle;

};

