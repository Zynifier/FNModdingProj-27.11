// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kinematic/Modes/WalkingMode.h"
#include "PhysicsMover/PhysicsMoverSimulationTypes.h"
#include "PhysicsDrivenWalkingMode.generated.h"

/**
 * PhysicsDrivenWalkingMode: Override base kinematic walking mode for physics based motion.
 */
UCLASS(BlueprintType, Blueprintable)
class MOVER_API UPhysicsDrivenWalkingMode : public UWalkingMode, public IPhysicsCharacterMovementModeInterface
{
	GENERATED_BODY()

public:
	// Maximum force the character can apply to reach the motion target

	UPROPERTY(EditAnywhere, Category="Physics Mover", meta=(ClampMin="0", ForceUnits="Newtons", UIMin="0"))
	float RadialForceLimit;

	// Maximum force the character can apply to hold in place while standing on an unwalkable incline

	UPROPERTY(EditAnywhere, Category="Physics Mover", meta=(ClampMin="0", ForceUnits="Newtons", UIMin="0"))
	float FrictionForceLimit;

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

	UPROPERTY(EditAnywhere, Category="Physics Mover", meta=(ClampMin="0", ForceUnits="cm", UIMin="0"))
	float CharacterRadius;

	// Damping factor to control the softness of the interaction between the character and the ground
// Set to 0 for no damping and 1 for maximum damping

	UPROPERTY(EditAnywhere, Category="Physics Mover", meta=(ClampMax="1", ClampMin="0", UIMax="1", UIMin="0"))
	float GroundDamping;

	// With this enabled, in addition to the constraint radial force, the mover applies an initial velocity to reach the target
// movement. This allows for a separation between pushing force and force to reach the target movement.
// A value of 1 means the character will always be able to reach the target motion (if there are no obstacles) regardless of
// the radial force limit.
// A value of 0 means the only thing moving the character is the constraint

	UPROPERTY(EditAnywhere, Category="Physics Mover", meta=(ClampMax="1", ClampMin="0", UIMax="1", UIMin="0"))
	float FractionalVelocityToTarget;

	// Time limit for being unsupported before moving from a walking to a falling state.
// This provides some grace period when walking off of an edge during which locomotion
// and jumping are still possible even though the character has started falling under gravity

	UPROPERTY(EditAnywhere, Category="Physics Mover", meta=(ClampMin="0", ForceUnits="s", UIMin="0"))
	float MaxUnsupportedTimeBeforeFalling;

};

