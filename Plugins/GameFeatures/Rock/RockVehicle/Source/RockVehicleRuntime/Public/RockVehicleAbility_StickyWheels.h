// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "RockScalableFloat.h"
#include "RockVehicleAbility_Physics.h"
#include "RockVehicleAbility_StickyWheels.generated.h"

USTRUCT()
struct FRockVehileAbilityInContinous_StickyWheels : public FRockVehicleAbilityInContinuous
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	FVector ContactNormal;

	UPROPERTY(Transient)
	float Scale;

	UPROPERTY(Transient)
	bool bAnyWheelsOnGround;

};

UCLASS(BlueprintType, Blueprintable, meta=(BlueprintSpawnableComponent))
class ROCKVEHICLERUNTIME_API URockVehicleAbility_StickyWheels : public URockVehicleAbility_Physics
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="StickyWheels")
	FRockScalableFloat StickyForceScaleGround;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="StickyWheels")
	FRockScalableFloat StickyForceScaleWall;

	UPROPERTY(Transient)
	FVector ContactNormal;

	UPROPERTY(Transient)
	float Scale;

	UPROPERTY(Transient)
	bool bAnyWheelsOnGround;

};

