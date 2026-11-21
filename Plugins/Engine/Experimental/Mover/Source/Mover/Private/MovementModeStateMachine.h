// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "MovementMode.h"
#include "MovementModeStateMachine.generated.h"

class UBaseMovementMode;

/**
 * - Any movement modes registered are co-owned by the state machine
 * - There is always an active mode, falling back to a do-nothing 'null' mode
 * - Queuing a mode that is already active will cause it to exit and re-enter
 * - Modes only switch during simulation tick
 */
UCLASS()
class UMovementModeStateMachine : public UObject
{
	GENERATED_BODY()

protected:
	UPROPERTY()
	TMap<FName, TObjectPtr<UBaseMovementMode>> Modes;

};

/**
 * NullMovementMode: a default do-nothing mode used as a placeholder when no other mode is active
 */
UCLASS(NotBlueprintable)
class UNullMovementMode : public UBaseMovementMode
{
	GENERATED_BODY()

};

