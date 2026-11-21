// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "FortAthenaWheeledVehicleMovementComponent.generated.h"

USTRUCT()
struct FReplicatedAthenaVehicleState
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FVector ForwardVectorTarget;

};

