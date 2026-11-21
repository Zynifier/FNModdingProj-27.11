// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ObjectiveGateComponentTypes.generated.h"

UENUM()
enum class EGateCheckType : uint8
{
	/* Requires all gates on an objective to be open to allow progression. Does not affect individual gate opening */
	RequireAll = 0,
	/* If any gate on the objective is in an open state this will allow objective progression. Does not affect individual gate opening */
	RequireAny = 1,
	/* requires the last gate in the array to be open to allow objective progression.
	* This will not allow gates to open unless the previous gate in the array is open.
	* The final gate can still use advanced gate logic to require others to be open at the same time.
	* Each gate state checked in order will use advanced logic if it is specified but only for determining if it is already open, not if it can open.
	* Note: Sequential ordering only affects gate opening not closing. And only affects opening when directly called, not if triggered off a timer from close.
	*/
	RequireSequentialOrder = 2,
};

UENUM()
enum class EGateResetBehavior : uint8
{
	// This gate does not reset the quest or the objective

	DoesNotReset = 0,
	// This gate will reset the objective when it closes, does not reset tracked data

	ResetObjectiveOnGateClose = 1,
	// This gate will reset the objective when it closes, and also resets instanced data (like data fromm the tracked data component)

	ResetObjectiveAndDataOnGateClose = 2,
	// This gate will reset the entire quest when it closes

	ResetQuestOnGateClose = 3,
};

UENUM()
enum class EGateType : uint8
{
	// specify an event tag and this gate will open when that event is received

	SingleEvent = 0,
	// Specify a FortGameplayAbility_ObjectiveGate to use to control this event

	GameplayAbility = 1,
	// Choose a verb and setup a filter that will open or close the gate when the filter passes

	Verb = 2,
};

UENUM()
enum class EObjectiveGateRelation : uint8
{
	// The listed gate must be open for this to count as open

	RequiredOpen = 0,
	// The listed gate must be closed for this to count as open

	RequiredClosed = 1,
	/* The listed gate must be in the same natural state as this gate for this to count as open
	 * Note: Both gates being opened or both being closed will count as open!
	 */
	RequiredSame = 2,
	// The listed gate must be in a different state than this one to for this to count as open

	RequiredOpposite = 3,
	// If the listed gate is open this one will count as open

	Substitution = 4,
};

