// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kinematic/Modes/SwimmingMode.h"
#include "PhysicsMover/PhysicsMoverSimulationTypes.h"
#include "PhysicsDrivenSwimmingMode.generated.h"

/**
 * PhysicsDrivenSwimmingMode: Override base kinematic Swimming mode for physics based motion.
 */
UCLASS(BlueprintType, Blueprintable)
class MOVER_API UPhysicsDrivenSwimmingMode : public USwimmingMode, public IPhysicsCharacterMovementModeInterface
{
	GENERATED_BODY()

};

