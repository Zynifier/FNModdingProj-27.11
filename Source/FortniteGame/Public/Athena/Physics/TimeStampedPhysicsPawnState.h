// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Pawns/FortPhysicsPawn.h"
#include "TimeStampedPhysicsPawnState.generated.h"

USTRUCT()
struct FTimeStampedPhysicsPawnState
{
	GENERATED_BODY()

public:
	UPROPERTY()
	float WorldTime;

	UPROPERTY()
	FReplicatedPhysicsPawnState PhysicsPawnState;

};

