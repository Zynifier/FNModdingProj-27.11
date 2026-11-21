// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "UObject/NoExportTypes.h"
#include "Kinematic/KinematicMoverSimulationTypes.h"
#include "MoveLibrary/MovementUtilsTypes.h"
#include "MoverDataModelTypes.h"
#include "MoverTypes.h"
#include "ModularMovement.generated.h"

class UMoverBlackboard;

UINTERFACE(BlueprintType)
class MOVER_API UTurnGeneratorInterface : public UInterface
{
	GENERATED_BODY()
};

class MOVER_API ITurnGeneratorInterface
{
	GENERATED_BODY()

public:
	/** Returns an additive angular velocity (per-axis degrees/second) based on the starting state and timestep */
	UFUNCTION(BlueprintNativeEvent)
	FRotator GetTurn(FRotator TargetOrientation, const FKinematicMoverTickStartData& FullStartState, const FMoverDefaultSyncState& MoverState, const FMoverTimeStep& TimeStep, const FProposedMove& ProposedMove, UMoverBlackboard* SimBlackboard);

};

/**
 * Base class for blueprint-implemented turn generators. This is necessary due to the lack of support for specifying 
 * EditInlineNew on a BP class, so it has to inherit the flag from a native parent.
 */
UCLASS(Abstract, EditInlineNew, BlueprintType, Blueprintable)
class MOVER_API UBlueprintableTurnGenerator : public UObject, public ITurnGeneratorInterface
{
	GENERATED_BODY()

};

/**
 * Modular mechanism for turning a Mover actor in place using an exact damped spring
 */
UCLASS(EditInlineNew)
class MOVER_API UExactDampedTurnGenerator : public UObject, public ITurnGeneratorInterface
{
	GENERATED_BODY()

public:
	/** Time required to reach halfway to the target orientation (smaller = quicker) */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Exact Damped Turning", meta=(ClampMin="0.01", ForceUnits="seconds", UIMin="0"))
	float HalfLifeSeconds;

};

/**
 * Modular mechanism for turning a Mover actor in place using linear angular velocity.
 */
UCLASS(EditInlineNew)
class MOVER_API ULinearTurnGenerator : public UObject, public ITurnGeneratorInterface
{
	GENERATED_BODY()

public:
	/** Maximum angular velocity of heading changes (degrees per second). AKA Yaw, AKA Z. Negative numbers will cause rotation to snap instantly to desired orientation. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Linear Turning", meta=(ClampMin="-1", ForceUnits="deg/s", UIMin="0"))
	float HeadingRate;

	/** Maximum angular velocity of pitch changes (degrees per second). Negative numbers will cause rotation to snap instantly to desired orientation. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Linear Turning", meta=(ClampMin="-1", ForceUnits="deg/s", UIMin="0"))
	float PitchRate;

	/** Maximum angular velocity of roll changes (degrees per second). Negative numbers will cause rotation to snap instantly to desired orientation. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Linear Turning", meta=(ClampMin="-1", ForceUnits="deg/s", UIMin="0"))
	float RollRate;

};

