// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/NetSerialization.h"
#include "Math/MathFwd.h"
#include "FortAthenaVehicleInputState.generated.h"

USTRUCT(BlueprintType)
struct FFortAthenaVehicleInputState
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="Input")
	float ForwardAlpha;

	UPROPERTY(BlueprintReadOnly, Category="Input")
	float RightAlpha;

	UPROPERTY(BlueprintReadOnly, Category="Input")
	float PitchAlpha;

	UPROPERTY(BlueprintReadOnly, Category="Input")
	float LookUpDelta;

	UPROPERTY(BlueprintReadOnly, Category="Input")
	float TurnDelta;

	UPROPERTY(BlueprintReadOnly, Category="Input")
	float SteerAlpha;

	UPROPERTY(BlueprintReadOnly, Category="Input")
	float GravityOffset;

	UPROPERTY(BlueprintReadOnly, Category="Input")
	FVector MovementDir;

	UPROPERTY(BlueprintReadOnly, Category="Input")
	uint8 bIsReversing : 1;

	UPROPERTY(BlueprintReadOnly, Category="Input")
	uint8 bIsSprinting : 1;

	UPROPERTY(BlueprintReadOnly, Category="Input")
	uint8 bIsJumping : 1;

	UPROPERTY(BlueprintReadOnly, Category="Input")
	uint8 bIsBraking : 1;

	UPROPERTY(BlueprintReadOnly, Category="Input")
	uint8 bIsHonking : 1;

	UPROPERTY(BlueprintReadOnly, Category="Input")
	uint8 bIgnoreForwardInAir : 1;

	UPROPERTY(BlueprintReadOnly, Category="Input")
	uint8 bMovementModifier0 : 1;

	UPROPERTY(BlueprintReadOnly, Category="Input")
	uint8 bMovementModifier1 : 1;

	UPROPERTY(BlueprintReadOnly, Category="Input")
	uint8 bMovementModifier2 : 1;

	UPROPERTY(BlueprintReadOnly, Category="Input")
	uint8 bUsingGamepad : 1;

	UPROPERTY(BlueprintReadOnly, Category="Input")
	uint8 bUsingTrigger : 1;

};

USTRUCT()
struct FFortAthenaVehicleInputStateReliable
{
	GENERATED_BODY()

public:
	UPROPERTY()
	uint8 bIsReversing : 1;

	UPROPERTY()
	uint8 bIsSprinting : 1;

	UPROPERTY()
	uint8 bIsJumping : 1;

	UPROPERTY()
	uint8 bIsBraking : 1;

	UPROPERTY()
	uint8 bIsHonking : 1;

	UPROPERTY()
	uint8 bIgnoreForwardInAir : 1;

	UPROPERTY()
	uint8 bMovementModifier0 : 1;

	UPROPERTY()
	uint8 bMovementModifier1 : 1;

	UPROPERTY()
	uint8 bMovementModifier2 : 1;

	UPROPERTY()
	uint8 bUsingGamepad : 1;

	UPROPERTY()
	uint8 bUsingTrigger : 1;

};

USTRUCT()
struct FFortAthenaVehicleInputStateUnreliable
{
	GENERATED_BODY()

public:
	UPROPERTY()
	float ForwardAlpha;

	UPROPERTY()
	float RightAlpha;

	UPROPERTY()
	float PitchAlpha;

	UPROPERTY()
	float LookUpDelta;

	UPROPERTY()
	float TurnDelta;

	UPROPERTY()
	float SteerAlpha;

	UPROPERTY()
	float GravityOffset;

	UPROPERTY()
	FVector_NetQuantize100 MovementDir;

};

