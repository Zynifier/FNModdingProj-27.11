// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Tween.generated.h"

UENUM(BlueprintType)
enum class ETweenInitializationPoint : uint8
{
	/** Waits until after the initial Delay before initializing To/From values and updating the Target. */
	AfterDelay = 0,
	/** Initializes To/From values and updates the Target as soon as the Tween starts, even if there is an initial Delay. */
	OnPlay = 1,
};

UENUM(BlueprintType)
enum class ETweenLoopType : uint8
{
	/** When reaching one end, the tween stops playing. */
	None = 0,
	/** When reaching one end, the tween resets to the opposite end and continues. */
	Repeat = 1,
	/** When reaching one end, the tween reverses direction and continues. */
	PingPong = 2,
};

UENUM(BlueprintType)
enum class ETweenPlayDirection : uint8
{
	/** Plays from the beginning of the tween to the end. */
	Forward = 0,
	/** Plays from the end of the tween to the beginning. */
	Backward = 1,
};

UENUM(BlueprintType)
enum class ETweenResetDestination : uint8
{
	/** Reset to the beginning of the tween. */
	Beginning = 0,
	/** Reset to the end of the tween. */
	End = 1,
};

