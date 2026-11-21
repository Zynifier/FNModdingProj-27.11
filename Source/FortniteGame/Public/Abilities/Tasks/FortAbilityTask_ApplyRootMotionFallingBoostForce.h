// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/Tasks/AbilityTask_ApplyRootMotion_Base.h"
#include "Engine/HitResult.h"
#include "GameFramework/RootMotionSource.h"
#include "Math/MathFwd.h"
#include "FortAbilityTask_ApplyRootMotionFallingBoostForce.generated.h"

class UFortAbilityTask_ApplyRootMotionFallingBoostForce;
class UGameplayAbility;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FApplyRootMotionFallingBoostForceDelegate);

USTRUCT()
struct FFortRootMotionSource_FallingBoost : public FRootMotionSource
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FVector StartLocation;

	UPROPERTY()
	FVector StartVelocity;

	UPROPERTY(NotReplicated)
	FVector LastDesiredVelocity;

	UPROPERTY()
	float VerticalImpulse;

	UPROPERTY()
	float GravityScalar;

	UPROPERTY()
	float MaxAcceleration;

	UPROPERTY()
	float LateralFriction;

	UPROPERTY()
	float MaxLateralSpeed;

	UPROPERTY(NotReplicated)
	bool bHasAppliedVerticalImpulse;

	UPROPERTY(NotReplicated)
	FVector LatestRepMovementLocation;

};

UCLASS()
class UFortAbilityTask_ApplyRootMotionFallingBoostForce : public UAbilityTask_ApplyRootMotion_Base
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Mantis|Ability|Tasks", meta=(BlueprintInternalUseOnly="TRUE", DefaultToSelf="OwningAbility", HidePin="OwningAbility"))
	static UFortAbilityTask_ApplyRootMotionFallingBoostForce* ApplyRootMotionFallingBoostForce(UGameplayAbility* OwningAbility, FName TaskInstanceName, float VerticalImpulse, float Duration, float GravityScalar, float MaxAcceleration, float LateralFriction, float MaxLateralSpeed);

	UFUNCTION()
	void OnLandedCallback(const FHitResult& Hit);

	UPROPERTY(BlueprintAssignable)
	FApplyRootMotionFallingBoostForceDelegate OnFinish;

protected:
	UPROPERTY(Replicated)
	float VerticalImpulse;

	UPROPERTY(Replicated)
	float Duration;

	UPROPERTY(Replicated)
	float GravityScalar;

	UPROPERTY(Replicated)
	float MaxAcceleration;

	UPROPERTY(Replicated)
	float LateralFriction;

	UPROPERTY(Replicated)
	float MaxLateralSpeed;

};

