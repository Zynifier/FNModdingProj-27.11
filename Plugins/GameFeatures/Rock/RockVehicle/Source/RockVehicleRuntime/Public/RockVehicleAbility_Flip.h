// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "RockScalableFloat.h"
#include "RockVehicleAbility_Physics.h"
#include "RockVehicleAbility_Flip.generated.h"

USTRUCT()
struct FRockVehicleAbilityInContinuous_Flip : public FRockVehicleAbilityInContinuous
{
	GENERATED_BODY()

public:
	UPROPERTY()
	bool bWheelsOnGround;

};

USTRUCT()
struct FRockVehicleAbilityInPersistent_Flip : public FRockVehicleAbilityInPersistent
{
	GENERATED_BODY()

};

UCLASS(BlueprintType, Blueprintable, meta=(BlueprintSpawnableComponent))
class ROCKVEHICLERUNTIME_API URockVehicleAbility_Flip : public URockVehicleAbility_Physics
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="AutoFlip")
	FRockScalableFloat Impulse;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="AutoFlip")
	FRockScalableFloat Torque;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="AutoFlip")
	FRockScalableFloat Duration;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="AutoFlip")
	FRockScalableFloat ContactNormalThresholdDegrees;

	UPROPERTY(Transient)
	bool bWheelsOnGround;

};

