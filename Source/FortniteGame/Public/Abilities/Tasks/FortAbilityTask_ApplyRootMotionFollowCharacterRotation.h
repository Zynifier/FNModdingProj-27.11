// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/Tasks/AbilityTask_ApplyRootMotion_Base.h"
#include "GameFramework/RootMotionSource.h"
#include "Math/MathFwd.h"
#include "FortAbilityTask_ApplyRootMotionFollowCharacterRotation.generated.h"

class UCurveFloat;
class UFortAbilityTask_ApplyRootMotionFollowCharacterRotation;
class UGameplayAbility;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FApplyRootMotionFollowCharacterRotationDelegate);

USTRUCT()
struct FRootMotionSource_FollowCharacterRotation : public FRootMotionSource_ConstantForce
{
	GENERATED_BODY()

public:
	UPROPERTY()
	float ConstantStrength;

	UPROPERTY()
	bool bWasWalkingLastFrame;

	UPROPERTY()
	bool bWasFallingLastFrame;

	UPROPERTY()
	float WalkingAccumulatedTime;

	UPROPERTY()
	float FallingAccumulatedTime;

};

UCLASS()
class UFortAbilityTask_ApplyRootMotionFollowCharacterRotation : public UAbilityTask_ApplyRootMotion_Base
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Ability|Tasks", meta=(BlueprintInternalUseOnly="TRUE", DefaultToSelf="OwningAbility", HidePin="OwningAbility"))
	static UFortAbilityTask_ApplyRootMotionFollowCharacterRotation* ApplyRootMotionFollowCharacterRotation(UGameplayAbility* OwningAbility, FName TaskInstanceName, float StrengthInWater, float Duration, bool bIsAdditive, UCurveFloat* StrengthOverTimeOnLand, ERootMotionFinishVelocityMode VelocityOnFinishMode, FVector SetVelocityOnFinish, float ClampVelocityOnFinish, bool bEnableGravity);

	UPROPERTY(BlueprintAssignable)
	FApplyRootMotionFollowCharacterRotationDelegate OnFinish;

protected:
	UPROPERTY(Replicated)
	float Strength;

	UPROPERTY(Replicated)
	float Duration;

	UPROPERTY(Replicated)
	bool bIsAdditive;

	UPROPERTY(Replicated)
	TObjectPtr<UCurveFloat> StrengthOverTime;

	UPROPERTY(Replicated)
	bool bEnableGravity;

};

