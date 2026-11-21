// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "NetPhysicsMoveSimulation.generated.h"

USTRUCT(BlueprintType)
struct FNetPhysicsMoveInputCmd
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, Category="Input")
	TArray<float> AxisValues;

	UPROPERTY(BlueprintReadWrite, Category="Input")
	TArray<bool> ActionValues;

	UPROPERTY(BlueprintReadWrite, Category="Input")
	FRotator ViewRotation;

};

// Server-Authoratative Network object state

USTRUCT(BlueprintType)
struct FNetPhysicsMoveObject
{
	GENERATED_BODY()

public:
	UPROPERTY()
	bool bEnabled;

};

// Non networked object state

USTRUCT(BlueprintType)
struct FNetPhysicsMoveObjectLocal
{
	GENERATED_BODY()

};

