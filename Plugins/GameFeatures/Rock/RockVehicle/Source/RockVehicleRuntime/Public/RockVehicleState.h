// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "Athena/FortAthenaVehicleInputState.h"
#include "Pawns/FortPhysicsPawn.h"
#include "RockVehicleState.generated.h"

USTRUCT()
struct FRockVehicleState
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FReplicatedPhysicsPawnState RigidBodyState;

	UPROPERTY()
	FFortAthenaVehicleInputState PrevDriverInput;

	UPROPERTY()
	bool bWheelsOnGround;

	UPROPERTY()
	bool bAnyWheelsOnGround;

	UPROPERTY()
	FVector AverageSpringNormal;

};

