// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "FortVehicleState.generated.h"

USTRUCT(BlueprintType, meta=(IsBlueprintBase="true"))
struct FGearConfig
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="GearConfig")
	float TopSpeed;

	UPROPERTY(EditAnywhere, Category="GearConfig")
	float MinSpeed;

	UPROPERTY(EditAnywhere, Category="GearConfig")
	float PushForce;

	UPROPERTY(EditAnywhere, Category="GearConfig")
	float RampTime;

	UPROPERTY(EditAnywhere, Category="GearConfig")
	float SteeringAngleMultiplier;

	UPROPERTY(EditAnywhere, Category="GearConfig")
	uint8 bAutoBrake : 1;

	UPROPERTY(EditAnywhere, Category="GearConfig")
	uint8 bIgnoreGravity : 1;

	UPROPERTY(EditAnywhere, Category="GearConfig")
	uint8 bForwardGear : 1;

};

USTRUCT(BlueprintType, meta=(IsBlueprintBase="true"))
struct FSpringConfig
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="SpringConfig")
	FTransform LocalStartTM;

	UPROPERTY(EditAnywhere, Category="SpringConfig")
	FTransform LocalApplyTM;

	UPROPERTY(EditAnywhere, Category="SpringConfig")
	float SpringLength;

	UPROPERTY(EditAnywhere, Category="SpringConfig")
	float SpringStiff;

	UPROPERTY(EditAnywhere, Category="SpringConfig")
	float SpringDamp;

	UPROPERTY(EditAnywhere, Category="SpringConfig")
	float MaxAccelChange;

};

USTRUCT()
struct FFortVehicleDerived
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Config, Category="Movement")
	TArray<FSpringConfig> Springs;

	UPROPERTY(EditAnywhere, Category="FortVehicleDerived")
	TArray<FGearConfig> InternalGears;

	UPROPERTY(EditAnywhere, Category="FortVehicleDerived")
	TArray<FGearConfig> InternalSprintGears;

	UPROPERTY(EditAnywhere, Category="FortVehicleDerived")
	FVector LocalFrontFrictionPt;

	UPROPERTY(EditAnywhere, Category="FortVehicleDerived")
	FVector LocalRearFrictionPt;

	UPROPERTY(EditAnywhere, Category="FortVehicleDerived")
	float FrontMassRatio;

	UPROPERTY(EditAnywhere, Category="FortVehicleDerived")
	float RearMassRatio;

};

USTRUCT()
struct FVehicleSimAux
{
	GENERATED_BODY()

};

