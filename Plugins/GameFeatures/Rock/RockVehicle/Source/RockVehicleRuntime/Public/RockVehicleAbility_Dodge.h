// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "RockScalableFloat.h"
#include "RockVehicleAbility_Physics.h"
#include "RockVehicleAbility_Dodge.generated.h"

USTRUCT(BlueprintType)
struct FRockDodgeImpulse
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="RockDodgeImpulse")
	FRockScalableFloat VelocityChange;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="RockDodgeImpulse")
	FRockScalableFloat MaxSpeedScale;

};

USTRUCT()
struct FRockDodgeImpulse_PhysicsThread
{
	GENERATED_BODY()

};

USTRUCT()
struct FRockVehicleAbilityInContinuous_Dodge : public FRockVehicleAbilityInContinuous
{
	GENERATED_BODY()

public:
	UPROPERTY()
	bool bWheelsOnGround;

};

USTRUCT()
struct FRockVehicleAbilityInPersistent_Dodge : public FRockVehicleAbilityInPersistent
{
	GENERATED_BODY()

};

UCLASS(BlueprintType, Blueprintable, meta=(BlueprintSpawnableComponent))
class ROCKVEHICLERUNTIME_API URockVehicleAbility_Dodge : public URockVehicleAbility_Physics
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Dodge")
	FRockDodgeImpulse ForwardImpulse;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Dodge")
	FRockDodgeImpulse BackwardImpulse;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Dodge")
	FRockDodgeImpulse SideImpulse;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Dodge")
	FRockScalableFloat MinTimeAfterJump;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Dodge")
	FRockScalableFloat MinTorqueTime;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Dodge")
	FRockScalableFloat MaxTorqueTime;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Dodge")
	FRockScalableFloat ForwardTorque;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Dodge")
	FRockScalableFloat SideTorque;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Dodge")
	FRockScalableFloat ZLiftTime;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Dodge")
	FRockScalableFloat ZLiftAccel;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Dodge")
	FRockScalableFloat ZDampingTime;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Dodge")
	FRockScalableFloat ZDamping;

	UPROPERTY()
	FRockScalableFloat InputThreshold;

	UPROPERTY(Transient)
	FVector2D DodgeInput;

	UPROPERTY(Transient)
	bool bWheelsOnGround;

};

