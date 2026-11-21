// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "FortVehicleTypes.h"
#include "FortVehicleAsync.generated.h"

class UFortPhysicsVehicleConfigs;

USTRUCT()
struct FFortVehicleInPersistent
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TObjectPtr<UFortPhysicsVehicleConfigs> FortPhysicsVehicleConfigs;

	UPROPERTY()
	uint8 bUseForceHeading : 1;

	UPROPERTY()
	uint8 bHasDriver : 1;

	UPROPERTY()
	uint8 bHasPassengers : 1;

	UPROPERTY()
	uint8 bIsTouchingAnything : 1;

	UPROPERTY()
	uint8 bAttemptAsyncOrientationCorrection : 1;

	UPROPERTY()
	uint8 bUseGravity : 1;

	UPROPERTY()
	float WaterLevel;

	UPROPERTY()
	FVector LocalFrontFrictionPt;

	UPROPERTY()
	FVector LocalRearFrictionPt;

	UPROPERTY()
	float FrontMassRatio;

	UPROPERTY()
	float RearMassRatio;

	UPROPERTY()
	float TopSpeedCurrentMultiplier;

	UPROPERTY()
	FReplicatedAthenaVehicleAttributes VehicleAttributes;

	UPROPERTY()
	TArray<ETireStates> TireStates;

};

USTRUCT()
struct FFortVehicleInternalPersistent
{
	GENERATED_BODY()

};

USTRUCT()
struct FFortVehicleOutContinuous
{
	GENERATED_BODY()

public:
	UPROPERTY()
	float SteeringAngle;

	UPROPERTY()
	FVector AverageSpringNormal;

};

USTRUCT()
struct FFortVehicleOutPersistent
{
	GENERATED_BODY()

public:
	UPROPERTY()
	uint8 bCanDriveOnIncline : 1;

	UPROPERTY()
	uint8 bWheelsOnGround : 1;

	UPROPERTY()
	uint8 bAnyWheelsOnGround : 1;

	UPROPERTY()
	uint8 bIsTouchingDrivableGround : 1;

	UPROPERTY()
	uint8 bIsAsyncCorrectingOrientation : 1;

	UPROPERTY()
	uint8 bIsTouchingGroundWithoutWheels : 1;

	UPROPERTY()
	uint8 bPossiblyTouchingTop : 1;

	UPROPERTY()
	uint8 bOnRoad : 1;

	UPROPERTY()
	uint8 bOnLandscape : 1;

	UPROPERTY()
	uint8 bOnDirt : 1;

	UPROPERTY()
	uint8 bOnVehicle : 1;

	UPROPERTY()
	uint8 bBoosting : 1;

	UPROPERTY()
	uint8 bOnGrass : 1;

	UPROPERTY()
	uint8 bOnSnow : 1;

	UPROPERTY()
	uint8 bOnIce : 1;

	UPROPERTY()
	uint8 bOnMud : 1;

	UPROPERTY(NotReplicated)
	TArray<ETireSurfaces> TireSurfaces;

	UPROPERTY()
	float TotalBrakingDelta;

};

