// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Animation/FortAnimInstance.h"
#include "FortCombatTypes.h"
#include "FortMovementEnums.h"
#include "FortAIAnimInstance.generated.h"

class UAnimNotify;

UCLASS(MinimalAPI, BlueprintType, Blueprintable, HideCategories=("AnimInstance"))
class UFortAIAnimInstance : public UFortAnimInstance
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="AI")
	float Speed;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="AI")
	float UpwardVelocity;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="AI")
	float MovementDirection;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="AI")
	float LowerBodyCurrentWeight;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="AI")
	float LowerBodyBlendTime;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="AI")
	int32 RunVariation;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="AI")
	int32 WalkVariation;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="AI")
	TEnumAsByte<EFortMovementStyle::Type> MovementStyle;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="AI")
	uint8 BlockGetUp : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="AI")
	uint8 bIsStunned : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="AI")
	uint8 bIsKnockedback : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="AI")
	uint8 bIsStaggered : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="AI")
	uint8 bIsSleeping : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="AI")
	uint8 bIsDBNO : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="AI")
	uint8 bIsDead : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="AI")
	uint8 bIsSprinting : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="AI")
	uint8 bIsCowering : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="AI")
	uint8 bHasWeapon : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="AI")
	uint8 bAdditiveHitReactLoop : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="AI")
	uint8 bUseAltSleepAnim : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="AI")
	uint8 bShouldUseMovementLocomotion : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="AI")
	uint8 bCanLookAtAimTarget : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="AI")
	uint8 bIsTargeting : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="AI")
	uint8 bTransitionToIdle : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="AI")
	TEnumAsByte<EFortWeaponCoreAnimation::Type> WeaponCoreAnimation;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="AI")
	bool bStartTurn;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="AI")
	float TurnAngle;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="AI")
	float TurnRate;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="AI")
	float ForwardHeading;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="AI")
	float MovementHeading;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="AI")
	float HeadingDelta;

protected:
	UFUNCTION()
	FORTNITEGAME_API void AnimNotify_SleepingFullyBlended(const UAnimNotify* Notify);

};

