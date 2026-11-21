// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortVehicleRuntimeModifiers.generated.h"

USTRUCT(BlueprintType)
struct FVehicleRuntimeModifiers
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	uint8 DataVersion;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="VehicleRuntimeModifiers")
	uint8 bHasInfiniteFuel : 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="VehicleRuntimeModifiers")
	uint8 bSupportCosmeticWrap : 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="VehicleRuntimeModifiers")
	float WaterDestructionDelay;

	UPROPERTY(BlueprintReadOnly, Transient, Category="VehicleRuntimeModifiers")
	float SelfDestructTime;

	UPROPERTY(BlueprintReadOnly, Transient, Category="VehicleRuntimeModifiers")
	float MaxTimeExplosion;

	UPROPERTY(BlueprintReadOnly, Transient, Category="VehicleRuntimeModifiers")
	float MaxTimeZeroHealth;

	UPROPERTY(BlueprintReadOnly, Transient, Category="VehicleRuntimeModifiers")
	float MaxTimeSelfDestructCleanup;

};

