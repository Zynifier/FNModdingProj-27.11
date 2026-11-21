// Copyright Epic Games, Inc. All Rights Reserved.

#include "AbilityTask_ApplyRootMotion_KatanaDashForce.h"
#include "Net/UnrealNetwork.h"

UAbilityTask_ApplyRootMotion_KatanaDashForce* UAbilityTask_ApplyRootMotion_KatanaDashForce::ApplyRootMotion_KatanaDashForce(UGameplayAbility* InOwningAbility, FName InTaskInstanceName, FVector InTargetLocation, float InDuration, float InHeightAboveGround, bool bInSetNewMovementMode, EMovementMode InMovementMode, bool bInRestrictSpeedToExpected, UCurveVector* InPathOffsetCurve, ERootMotionFinishVelocityMode InVelocityOnFinishMode, FVector InSetVelocityOnFinish, float InClampVelocityOnFinish)
{
	return nullptr;
}

void UAbilityTask_ApplyRootMotion_KatanaDashForce::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UAbilityTask_ApplyRootMotion_KatanaDashForce, HeightAboveGround);
}
