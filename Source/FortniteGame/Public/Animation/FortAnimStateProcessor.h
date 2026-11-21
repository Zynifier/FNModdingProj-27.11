// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AnimationSharingTypes.h"
#include "FortAnimStateProcessor.generated.h"

UENUM(BlueprintType)
enum class EDeimosAnimState : uint8
{
	Idle = 0,
	Running = 1,
	Attack = 2,
	Dance = 3,
	Dying = 4,
	Died = 5,
	FullBodyHitReact = 6,
	AdditiveHitReact = 7,
	ActiveIdle = 8,
	Falling = 9,
	Frozen = 10,
	RangedAttack = 11,
	Walking = 12,
	Sprinting = 13,
};

UCLASS(BlueprintType, Blueprintable)
class UFortAnimationSharingStateProcessor : public UAnimationSharingStateProcessor
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="FortAnimationSharingStateProcessor")
	float RunningVelocityThreshold;

	UPROPERTY(EditAnywhere, Category="FortAnimationSharingStateProcessor")
	float WalkingVelocityThreshold;

	UPROPERTY(EditAnywhere, Category="FortAnimationSharingStateProcessor")
	float SprintingVelocityThreshold;

	UPROPERTY(EditAnywhere, Category="FortAnimationSharingStateProcessor")
	float IdleVelocityThreshold;

	UPROPERTY(EditAnywhere, Category="FortAnimationSharingStateProcessor")
	float FallingZVelocityThreshold;

};

