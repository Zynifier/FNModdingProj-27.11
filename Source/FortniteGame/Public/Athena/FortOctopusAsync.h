// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "Athena/Vehicle/FortSphericalDriveModel.h"
#include "Athena/Vehicle/FortVehicleAsync.h"
#include "FortOctopusAsync.generated.h"

class UFortOctopusVehicleConfigs;

USTRUCT()
struct FOctopusAsyncDef
{
	GENERATED_BODY()

};

USTRUCT()
struct FOctopusInPersistent : public FFortVehicleInPersistent
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TObjectPtr<UFortOctopusVehicleConfigs> FortOctopusVehicleConfigs;

	UPROPERTY()
	TArray<FSphericalDriveContact> CachedContactPoints;

	UPROPERTY()
	float BoostForce;

	UPROPERTY()
	float MaxVerticalBoostForce;

	UPROPERTY()
	float BoostSpeedKmh;

	UPROPERTY()
	FVector TowhookAimDir;

};

USTRUCT()
struct FOctopusOutContinuous : public FFortVehicleOutContinuous
{
	GENERATED_BODY()

};

USTRUCT()
struct FOctopusOutPersistent : public FFortVehicleOutPersistent
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FQuat ShellRotation;

};

