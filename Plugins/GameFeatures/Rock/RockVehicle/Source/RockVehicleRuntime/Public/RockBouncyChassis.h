// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "RockBouncyChassis.generated.h"

USTRUCT(BlueprintType)
struct ROCKVEHICLERUNTIME_API FRockBoxSpringSetup
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="RockBoxSpringSetup")
	FVector Strength;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="RockBoxSpringSetup")
	FVector Damping;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="RockBoxSpringSetup")
	FVector MaxDisplacement;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="RockBoxSpringSetup")
	float MaxSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="RockBoxSpringSetup")
	float Mass;

};

USTRUCT(BlueprintType)
struct ROCKVEHICLERUNTIME_API FRockBoxSpring
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="RockBoxSpring")
	FRockBoxSpringSetup Setup;

};

USTRUCT(BlueprintType)
struct ROCKVEHICLERUNTIME_API FBouncyChassisInstance
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="BouncyChassisInstance")
	FRockBoxSpring Spring;

};

USTRUCT()
struct ROCKVEHICLERUNTIME_API FSpringSettings
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="SpringSettings")
	float Strength;

	UPROPERTY(EditAnywhere, Category="SpringSettings")
	float Damping;

};

USTRUCT()
struct ROCKVEHICLERUNTIME_API FBouncyChassisSetup
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="BouncyChassisSetup")
	FSpringSettings PitchSpring;

	UPROPERTY(EditAnywhere, Category="BouncyChassisSetup")
	float PitchMaxAngleDegrees;

	UPROPERTY(EditAnywhere, Category="BouncyChassisSetup")
	FSpringSettings RollSpring;

	UPROPERTY(EditAnywhere, Category="BouncyChassisSetup")
	float RollMaxAngleDegrees;

	UPROPERTY(EditAnywhere, Category="BouncyChassisSetup")
	FSpringSettings ZSpring;

	UPROPERTY(EditAnywhere, Category="BouncyChassisSetup")
	float ZMaxDrop;

	UPROPERTY(EditAnywhere, Category="BouncyChassisSetup")
	float ZMaxRaise;

	UPROPERTY(EditAnywhere, Category="Advanced")
	FVector MaxDisplacement;

	UPROPERTY(EditAnywhere, Category="Advanced")
	FVector MassOffset;

};

USTRUCT(BlueprintType)
struct ROCKVEHICLERUNTIME_API FBouncyChassisState
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="BouncyChassisState")
	float PitchDegrees;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="BouncyChassisState")
	float RollDegrees;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="BouncyChassisState")
	float TranslationZ;

};

