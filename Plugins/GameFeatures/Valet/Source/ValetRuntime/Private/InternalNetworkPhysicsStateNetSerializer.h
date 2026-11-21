// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "InternalNetworkPhysicsStateNetSerializer.generated.h"

USTRUCT()
struct FNetworkPhysicsStateNetSerializerDebugData
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FVector Force;

	UPROPERTY()
	FVector Torque;

	UPROPERTY()
	FVector LinearImpulse;

	UPROPERTY()
	FVector AngularImpulse;

};

USTRUCT()
struct FNetworkPhysicsStateNetSerializerDebugState
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FNetworkPhysicsStateNetSerializerDebugData DebugData[3];

};

USTRUCT()
struct FNetworkPhysicsStateNetSerializerState
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FVector Location;

	UPROPERTY()
	FVector LinearVelocity;

	UPROPERTY()
	FVector AngularVelocity;

	UPROPERTY()
	FQuat Rotation;

	UPROPERTY()
	int32 NetworkHandle;

	UPROPERTY()
	int32 Frame;

	UPROPERTY()
	uint8 ObjectState;

};

