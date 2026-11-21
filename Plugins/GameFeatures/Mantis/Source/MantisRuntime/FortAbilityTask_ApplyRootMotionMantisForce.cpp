// Copyright Epic Games, Inc. All Rights Reserved.

#include "FortAbilityTask_ApplyRootMotionMantisForce.h"
#include "Net/UnrealNetwork.h"

void UFortAbilityTask_ApplyRootMotionMantisForce::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UFortAbilityTask_ApplyRootMotionMantisForce, Duration);
	DOREPLIFETIME(UFortAbilityTask_ApplyRootMotionMantisForce, TechniqueMontage);
	DOREPLIFETIME(UFortAbilityTask_ApplyRootMotionMantisForce, WarpInfo);
}
