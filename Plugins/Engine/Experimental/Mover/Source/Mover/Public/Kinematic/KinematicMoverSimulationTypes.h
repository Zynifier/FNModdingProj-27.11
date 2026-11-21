// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "MoverTypes.h"
#include "KinematicMoverSimulationTypes.generated.h"

// Auxiliary state that is input into the simulation (changes rarely)

USTRUCT(BlueprintType)
struct MOVER_API FKinematicMoverAuxStateContext
{
	GENERATED_BODY()

};

/**
 * The client generates this representation of "input" to the simulated actor for one simulation frame. This can be direct mapping
 * of controls, or more abstract data. It is composed of a collection of typed structs that can be customized per project.
 */
USTRUCT(BlueprintType)
struct MOVER_API FKinematicMoverInputCmdContext
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, Category="Mover")
	FMoverDataCollection InputCollection;

};

/** State we are evolving frame to frame and keeping in sync (frequently changing). It is composed of a collection of typed structs 
 *  that can be customized per project. Mover actors are required to have FMoverDefaultSyncState as one of these structs.
 */
USTRUCT(BlueprintType)
struct MOVER_API FKinematicMoverSyncState
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, Category="Mover")
	FMoverDataCollection SyncStateCollection;

};

/**
 * Filled out by a MovementMode during simulation tick to indicate its ending state, allowing for a residual time step and switching modes mid-tick
 */
USTRUCT(BlueprintType)
struct MOVER_API FMovementModeTickEndState
{
	GENERATED_BODY()

public:
	// Any unused tick time

	UPROPERTY(BlueprintReadWrite, Category="Mover")
	float RemainingMs;

	UPROPERTY(BlueprintReadWrite, Category="Mover")
	FName NextModeName;

};

/**
 * Contains all state data produced by a simulation tick, including new simulation state
 */
USTRUCT(BlueprintType)
struct MOVER_API FKinematicMoverTickEndData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Mover")
	FKinematicMoverSyncState SyncState;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Mover")
	FKinematicMoverAuxStateContext AuxState;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Mover")
	FMovementModeTickEndState MovementEndState;

};

/**
 * Contains all state data for the start of a simulation tick
 */
USTRUCT(BlueprintType)
struct MOVER_API FKinematicMoverTickStartData
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="Mover")
	FKinematicMoverInputCmdContext InputCmd;

	UPROPERTY(BlueprintReadOnly, Category="Mover")
	FKinematicMoverSyncState SyncState;

	UPROPERTY(BlueprintReadOnly, Category="Mover")
	FKinematicMoverAuxStateContext AuxState;

};

