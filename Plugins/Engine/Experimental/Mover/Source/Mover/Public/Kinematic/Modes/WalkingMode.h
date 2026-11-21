// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kinematic/KinematicMoverSimulationTypes.h"
#include "MoveLibrary/MovementUtilsTypes.h"
#include "MovementMode.h"
#include "MoverTypes.h"
#include "WalkingMode.generated.h"

class UObject;

/**
 * WalkingMode: a default movement mode for traversing surfaces and movement bases (walking, running, sneaking, etc.)
 */
UCLASS(BlueprintType, Blueprintable)
class MOVER_API UWalkingMode : public UBaseMovementMode
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="Mover")
	virtual void OnGenerateMove(const FKinematicMoverTickStartData& StartState, const FMoverTimeStep& TimeStep, FProposedMove& OutProposedMove) const;

	UFUNCTION(BlueprintCallable, Category="Mover")
	virtual void OnSimulationTick(const FSimulationTickParams& Params, FKinematicMoverTickEndData& OutputState);

protected:
	/** Optional modular object for generating rotation towards desired orientation. If not specified, linear interpolation will be used. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Instanced, Category="Mover", meta=(MustImplement="/Script/Mover.TurnGeneratorInterface"))
	TObjectPtr<UObject> TurnGenerator;

};

