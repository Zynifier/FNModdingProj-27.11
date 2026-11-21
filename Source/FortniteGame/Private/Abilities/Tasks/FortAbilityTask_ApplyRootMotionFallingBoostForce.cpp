// Copyright Epic Games, Inc. All Rights Reserved.

#include "Abilities/Tasks/FortAbilityTask_ApplyRootMotionFallingBoostForce.h"
#include "Net/UnrealNetwork.h"

UFortAbilityTask_ApplyRootMotionFallingBoostForce* UFortAbilityTask_ApplyRootMotionFallingBoostForce::ApplyRootMotionFallingBoostForce(UGameplayAbility* OwningAbility, FName TaskInstanceName, float VerticalImpulse, float Duration, float GravityScalar, float MaxAcceleration, float LateralFriction, float MaxLateralSpeed)
{
	return nullptr;
}

void UFortAbilityTask_ApplyRootMotionFallingBoostForce::OnLandedCallback(const FHitResult& Hit)
{
}

void UFortAbilityTask_ApplyRootMotionFallingBoostForce::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UFortAbilityTask_ApplyRootMotionFallingBoostForce, VerticalImpulse);
	DOREPLIFETIME(UFortAbilityTask_ApplyRootMotionFallingBoostForce, Duration);
	DOREPLIFETIME(UFortAbilityTask_ApplyRootMotionFallingBoostForce, GravityScalar);
	DOREPLIFETIME(UFortAbilityTask_ApplyRootMotionFallingBoostForce, MaxAcceleration);
	DOREPLIFETIME(UFortAbilityTask_ApplyRootMotionFallingBoostForce, LateralFriction);
	DOREPLIFETIME(UFortAbilityTask_ApplyRootMotionFallingBoostForce, MaxLateralSpeed);
}
