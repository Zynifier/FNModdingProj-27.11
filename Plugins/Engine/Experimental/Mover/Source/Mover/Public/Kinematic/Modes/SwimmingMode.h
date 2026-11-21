// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kinematic/KinematicMoverSimulationTypes.h"
#include "MoveLibrary/MovementUtilsTypes.h"
#include "MovementMode.h"
#include "MoverTypes.h"
#include "SwimmingMode.generated.h"

/**
 * SwimmingMode: a default movement mode for traversing water volumes
 */
UCLASS(BlueprintType, Blueprintable)
class MOVER_API USwimmingMode : public UBaseMovementMode
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="Mover")
	virtual void OnGenerateMove(const FKinematicMoverTickStartData& StartState, const FMoverTimeStep& TimeStep, FProposedMove& OutProposedMove) const;

	UFUNCTION(BlueprintCallable, Category="Mover")
	virtual void OnSimulationTick(const FSimulationTickParams& Params, FKinematicMoverTickEndData& OutputState);

};

