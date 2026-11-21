// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "LayeredMove.h"
#include "LaunchMove.generated.h"

/** Launch Move: provides an impulse velocity to the actor after (optionally) forcing them into a particular movement mode */
USTRUCT(BlueprintType)
struct MOVER_API FLayeredMove_Launch : public FLayeredMoveBase
{
	GENERATED_BODY()

public:
	// Velocity to apply to the actor. Could be additive or overriding depending on MixMode setting.

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Mover", meta=(ForceUnits="cm/s"))
	FVector LaunchVelocity;

	// Optional movement mode name to force the actor into before applying the impulse velocity.

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Mover")
	FName ForceMovementMode;

};

