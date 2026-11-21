// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "FortFlightModel.generated.h"

USTRUCT(BlueprintType, meta=(IsBlueprintBase="true"))
struct FFlightParams
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FlightParams")
	float TopSpeedKmh;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FlightParams")
	float LiftoffSpeedKmh;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FlightParams")
	float LandingSpeedKmh;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FlightParams")
	float ControlSpeedKmh;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FlightParams")
	float HeadingStabilizationRate;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FlightParams")
	float HeadingStabilizationMaxForwardVelocityKmh;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FlightParams")
	float HeadingStabilizationMaxDegPerSecond;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FlightParams")
	float VerticalStabilizationDrag;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FlightParams")
	float HorizontalStabilizationDrag;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FlightParams")
	float VerticalStabilizationTorque;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FlightParams")
	float MaxVerticalStabilizationTorque;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FlightParams")
	float HorizontalStabilizationTorque;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FlightParams")
	float MaxHorizontalStabilizationTorque;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FlightParams")
	float RotationalDampingCoefficient;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FlightParams")
	float MaxRotationalDampingTorque;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FlightParams")
	float TailLength;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FlightParams")
	float LowSpeedThrust;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FlightParams")
	float HighSpeedThrust;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FlightParams")
	float AntigravityHorizontal;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FlightParams")
	float AntigravityUp;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FlightParams")
	float AntigravityDown;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FlightParams")
	float ControlFrameHeight;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FlightParams")
	float ControlFrameDistance;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FlightParams")
	float ControlFrameDistanceInterpPerSecond;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FlightParams")
	float ControlFrameOrbitInterpPerSecond;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FlightParams")
	float ControlFrameRollInterpPerSecond;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FlightParams")
	FVector ControlFrameDefaultRollUp;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FlightParams")
	float ControlFrameRollUpAcceleration;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FlightParams")
	float ControlFrameRollUpMaxVelocity;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FlightParams")
	float ControlFrameRollUpDamping;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FlightParams")
	float ControlFrameMinUpNudge;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FlightParams")
	float ControlFrameMaxUpNudge;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FlightParams")
	float ControlFrameUpsideDownIgnoreNudgePercent;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FlightParams")
	float SteerPitchRate;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FlightParams")
	float SteerYawRate;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FlightParams")
	float SteerMaxHeadingDiffDegrees;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FlightParams")
	float RollPerHeadingDiff;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FlightParams")
	float HeadingMatchRate;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FlightParams")
	float RollMatchRate;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FlightParams")
	float MatchingTorqueCap;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FlightParams")
	float StallVelocityLow;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FlightParams")
	float StallVelocityHigh;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FlightParams")
	float MinStallYawMultiplier;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FlightParams")
	float MaxStallYawMultiplier;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FlightParams")
	float StallHighVelocityDeviationAngle;

};

USTRUCT(BlueprintType, meta=(IsBlueprintBase="true"))
struct FFortFlightModel
{
	GENERATED_BODY()

};

USTRUCT()
struct FFortFlightParamsRuntimeModifiers
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	float TopSpeedKmh;

	UPROPERTY(Transient)
	float RollPerHeadingDiff;

	UPROPERTY(Transient)
	float LowSpeedThrust;

	UPROPERTY(Transient)
	float HighSpeedThrust;

	UPROPERTY(Transient)
	float RollMatchRate;

	UPROPERTY(Transient)
	float MaxRotationalDampingTorque;

	UPROPERTY(Transient)
	float RotationalDampingCoefficient;

	UPROPERTY(Transient)
	float SteerYawRate;

	UPROPERTY(Transient)
	float SteerPitchRate;

	UPROPERTY(Transient)
	float HeadingMatchRate;

};

