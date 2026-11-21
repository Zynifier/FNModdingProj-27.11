// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kinematic/Modes/FallingMode.h"
#include "PhysicsMover/PhysicsMoverSimulationTypes.h"
#include "PhysicsDrivenFallingMode.generated.h"

/**
 * PhysicsDrivenFallingMode: Override base kinematic falling mode for physics based motion.
 */
UCLASS(BlueprintType, Blueprintable)
class MOVER_API UPhysicsDrivenFallingMode : public UFallingMode, public IPhysicsCharacterMovementModeInterface
{
	GENERATED_BODY()

public:
	// Maximum torque the character can apply to rotate in air about the vertical axis

	UPROPERTY(EditAnywhere, Category="Physics Mover", meta=(ClampMin="0", ForceUnits="NewtonMeters", UIMin="0"))
	float TwistTorqueLimit;

	// Maximum torque the character can apply to remain upright

	UPROPERTY(EditAnywhere, Category="Physics Mover", meta=(ClampMin="0", ForceUnits="NewtonMeters", UIMin="0"))
	float SwingTorqueLimit;

	// Target height for the character. This is the desired distance from the bottom of the capsule to the floor

	UPROPERTY(EditAnywhere, Category="Physics Mover", meta=(ClampMin="0", ForceUnits="cm", UIMin="0"))
	float TargetHeight;

	// Length of vertical query from the center of the character to find the ground

	UPROPERTY(EditAnywhere, Category="Physics Mover", meta=(ClampMin="0", ForceUnits="cm", UIMin="0"))
	float FloorSweepDistance;

	// Radius of ground query

	UPROPERTY(EditAnywhere, Category="Physics Mover", meta=(ClampMin="0", ForceUnits="cm", UIMin="0"))
	float FloorSweepRadius;

};

