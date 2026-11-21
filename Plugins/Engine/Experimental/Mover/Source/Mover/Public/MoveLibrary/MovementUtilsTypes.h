// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "MovementUtilsTypes.generated.h"

UENUM()
enum class EMoveMixMode : uint8
{
	AdditiveVelocity = 0,
	// Velocity is intended to be added with other sources

	OverrideVelocity = 1,
	// Velocity should override others

	OverrideAll = 2,
};

/** Encapsulates info about an intended move that hasn't happened yet */
USTRUCT(BlueprintType)
struct MOVER_API FProposedMove
{
	GENERATED_BODY()

};

