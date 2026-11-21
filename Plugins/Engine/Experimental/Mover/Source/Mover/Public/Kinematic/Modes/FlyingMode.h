// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kinematic/KinematicMoverSimulationTypes.h"
#include "MoveLibrary/MovementUtilsTypes.h"
#include "MovementMode.h"
#include "MoverTypes.h"
#include "FlyingMode.generated.h"

/**
 * FlyingMode: a default movement mode for moving through the air freely, but still interacting with blocking geometry. The
 * moving actor will remain upright vs the movement plane.
 */
UCLASS(BlueprintType, Blueprintable)
class MOVER_API UFlyingMode : public UBaseMovementMode
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="Mover")
	virtual void OnGenerateMove(const FKinematicMoverTickStartData& StartState, const FMoverTimeStep& TimeStep, FProposedMove& OutProposedMove) const;

	UFUNCTION(BlueprintCallable, Category="Mover")
	virtual void OnSimulationTick(const FSimulationTickParams& Params, FKinematicMoverTickEndData& OutputState);

};

