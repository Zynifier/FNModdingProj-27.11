// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/Tasks/AbilityTask_ApplyRootMotionMoveToForce.h"
#include "Engine/EngineTypes.h"
#include "GameFramework/RootMotionSource.h"
#include "Math/MathFwd.h"
#include "AbilityTask_ApplyRootMotion_KatanaDashForce.generated.h"

class UAbilityTask_ApplyRootMotion_KatanaDashForce;
class UCurveVector;
class UGameplayAbility;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FApplyRootMotionDelegate_KatanaDashForce);

USTRUCT()
struct FRootMotionSource_KatanaDashForce : public FRootMotionSource_MoveToForce
{
	GENERATED_BODY()

public:
	UPROPERTY()
	float HeightAboveGround;

};

UCLASS(MinimalAPI)
class UAbilityTask_ApplyRootMotion_KatanaDashForce : public UAbilityTask_ApplyRootMotionMoveToForce
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Ability|Tasks", meta=(BlueprintInternalUseOnly="true", DefaultToSelf="InOwningAbility", HidePin="InOwningAbility"))
	static UAbilityTask_ApplyRootMotion_KatanaDashForce* ApplyRootMotion_KatanaDashForce(UGameplayAbility* InOwningAbility, FName InTaskInstanceName, FVector InTargetLocation, float InDuration, float InHeightAboveGround, bool bInSetNewMovementMode, EMovementMode InMovementMode, bool bInRestrictSpeedToExpected, UCurveVector* InPathOffsetCurve, ERootMotionFinishVelocityMode InVelocityOnFinishMode, FVector InSetVelocityOnFinish, float InClampVelocityOnFinish);

private:
	UPROPERTY(Replicated)
	float HeightAboveGround;

};

