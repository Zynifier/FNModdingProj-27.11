// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/HitResult.h"
#include "Math/MathFwd.h"
#include "Kinematic/KinematicMoverSimulationTypes.h"
#include "MoveLibrary/MovementBaseUtils.h"
#include "MoveLibrary/MovementUtils.h"
#include "MoveLibrary/MovementUtilsTypes.h"
#include "MovementMode.h"
#include "MoverTypes.h"
#include "FallingMode.generated.h"

// Fired after the actor lands on a valid surface. First param is the name of the mode this actor is in after landing. Second param is the hit result from hitting the floor.

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FMover_OnLanded, const FName&, NextMovementModeName, const FHitResult&, HitResult);

/**
 * FallingMode: a default movement mode for moving through the air and jumping, typically influenced by gravity and air control
 */
UCLASS(BlueprintType, Blueprintable)
class MOVER_API UFallingMode : public UBaseMovementMode
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="Mover")
	virtual void OnGenerateMove(const FKinematicMoverTickStartData& StartState, const FMoverTimeStep& TimeStep, FProposedMove& OutProposedMove) const;

	UFUNCTION(BlueprintCallable, Category="Mover")
	virtual void OnSimulationTick(const FSimulationTickParams& Params, FKinematicMoverTickEndData& OutputState);

	// Broadcast when this actor lands on a valid surface.

	UPROPERTY(BlueprintAssignable, Category="Mover")
	FMover_OnLanded OnLanded;

	/**
	 * When falling, amount of movement control available to the actor.
	 * 0 = no control, 1 = full control
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Mover", meta=(ClampMax="1.0", ClampMin="0"))
	float AirControlPercentage;

	/**
 	 * Deceleration to apply to air movement when falling slower than terminal velocity.
 	 * Note: This is NOT applied to vertical velocity, only movement plane velocity
 	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Mover", meta=(ClampMin="0", ForceUnits="cm/s^2"))
	float FallingDeceleration;

	/**
     * Deceleration to apply to air movement when falling faster than terminal velocity
	 * Note: This is NOT applied to vertical velocity, only movement plane velocity
     */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Mover", meta=(ClampMin="0", ForceUnits="cm/s^2"))
	float OverTerminalSpeedFallingDeceleration;

	/**
	 * If the actor's movement plane velocity is greater than this speed falling will start applying OverTerminalSpeedFallingDeceleration instead of FallingDeceleration
	 * The expected behavior is to set OverTerminalSpeedFallingDeceleration higher than FallingDeceleration so the actor will slow down faster
	 * when going over TerminalMovementPlaneSpeed.
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Mover", meta=(ClampMin="0", ForceUnits="cm/s"))
	float TerminalMovementPlaneSpeed;

	/** When exceeding maximum vertical speed, should it be enforced via a hard clamp? If false, VerticalFallingDeceleration will be used for a smoother transition to the terminal speed limit. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Mover")
	bool bShouldClampTerminalVerticalSpeed;

	/** Deceleration to apply to vertical velocity when it's greater than TerminalVerticalSpeed. Only used if bShouldClampTerminalVerticalSpeed is false. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Mover", meta=(ClampMin="0", EditCondition="!bShouldClampTerminalVerticalSpeed", ForceUnits="cm/s^2"))
	float VerticalFallingDeceleration;

	/**
	 * If the actors vertical velocity is greater than this speed VerticalFallingDeceleration will be applied to vertical velocity
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Mover", meta=(ClampMin="0", ForceUnits="cm/s"))
	float TerminalVerticalSpeed;

protected:
	/**
	 * Is called at the end of the tick in falling mode. Handles checking any landings that should occur and switching to specific modes
	 * (i.e. landing on a walkable surface would switch to the walking movement mode) 
	 */
	UFUNCTION(BlueprintPure, Category="Mover")
	virtual void ProcessLanded(const FFloorCheckResult& FloorResult, FVector& Velocity, FRelativeBaseInfo& BaseInfo, FKinematicMoverTickEndData& TickEndData) const;

};

