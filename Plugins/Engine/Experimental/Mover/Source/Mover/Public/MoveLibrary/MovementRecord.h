// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "MovementRecord.generated.h"

/** Accounting record of a move as it is processed.
* Moves are composed of substeps, and these can be marked to indicate how they influence the final collapsed move.
* Relevancy means the substep (or part thereof) is contributing to the reflected movement state. Example: a character moves forward across a slightly
* irregular sidewalk, and then is adjusted downward to keep it sticking closely to the sidewalk. The forward move is a relevant substep, while the vertical heigh adjustment is not.
*/
USTRUCT(BlueprintType)
struct MOVER_API FMovementRecord
{
	GENERATED_BODY()

};

/** A part of movement accounting, representing a single piece of a move operation, such as a slide, floor adjustment, etc. */
USTRUCT(BlueprintType)
struct MOVER_API FMovementSubstep
{
	GENERATED_BODY()

};

