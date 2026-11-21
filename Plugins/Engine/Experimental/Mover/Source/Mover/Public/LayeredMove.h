// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "MoveLibrary/MovementUtilsTypes.h"
#include "LayeredMove.generated.h"

/** 
* Layered Moves are methods of affecting motion on a Mover-based actor, typically for a limited time. 
* Common uses would be for jumping, dashing, blast forces, etc.
* They are ticked as part of the Mover simulation, and produce a proposed move. These proposed moves 
* are aggregated and applied to the overall attempted move.
* Multiple layered moves can be active at any time, and may produce additive motion or motion that overrides
* what the current Movement Mode may intend.
*/// Base class for all layered moves

USTRUCT(BlueprintType)
struct MOVER_API FLayeredMoveBase
{
	GENERATED_BODY()

public:
	// Determines how this object's movement contribution should be mixed with others

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Mover")
	EMoveMixMode MixMode;

	// This move will expire after a set amount of time if > 0. If 0, it will be ticked only once, regardless of time step. It will need to be manually ended if < 0. 

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Mover")
	float DurationMs;

	// The simulation time this move first ticked (< 0 means it hasn't started yet)

	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Transient, Category="Mover")
	float StartSimTimeMs;

};

// A collection of layered moves affecting a movable actor

USTRUCT(BlueprintType)
struct MOVER_API FLayeredMoveGroup
{
	GENERATED_BODY()

};

