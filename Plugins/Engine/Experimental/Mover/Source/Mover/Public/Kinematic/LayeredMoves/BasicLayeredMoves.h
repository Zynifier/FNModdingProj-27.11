// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "LayeredMove.h"
#include "BasicLayeredMoves.generated.h"

UENUM(BlueprintType)
enum class ELayeredMove_ConstantVelocitySettingsFlags : uint8
{
	NoFlags = 0,
	// Velocity direction is determined when this move starts, relative to the target actor. This flag is incompatible with other Velocity**** flags

	VelocityStartRelative = 1,
	// Velocity direction is always relative to the target actor, even if its orientation changes. This flag is incompatible with other Velocity**** flags

	VelocityAlwaysRelative = 2,
};

/** Jump Impulse: introduces an instantaneous upwards change in velocity. This overrides the existing 'up' component of the actor's current velocity */
USTRUCT(BlueprintType)
struct MOVER_API FLayeredMove_JumpImpulse : public FLayeredMoveBase
{
	GENERATED_BODY()

public:
	// Units per second, in whatever direction the target actor considers 'up'

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Mover")
	float UpwardsSpeed;

};

/** Linear Velocity: A method of inducing a straight-line velocity on an actor over time  */
USTRUCT(BlueprintType)
struct MOVER_API FLayeredMove_LinearVelocity : public FLayeredMoveBase
{
	GENERATED_BODY()

public:
	// Units per second, could be worldspace vs relative depending on Flags

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Mover")
	FVector Velocity;

	// @see ELayeredMove_ConstantVelocitySettingsFlags

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Mover")
	uint8 SettingsFlags;

};

/** Teleport: instantly moves an actor to a new location */
USTRUCT(BlueprintType)
struct MOVER_API FLayeredMove_Teleport : public FLayeredMoveBase
{
	GENERATED_BODY()

public:
	// Location to teleport to, in world space

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Mover")
	FVector TargetLocation;

};

