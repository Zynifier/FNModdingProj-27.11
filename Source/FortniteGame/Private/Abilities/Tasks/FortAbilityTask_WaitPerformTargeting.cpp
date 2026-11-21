// Copyright Epic Games, Inc. All Rights Reserved.

#include "Abilities/Tasks/FortAbilityTask_WaitPerformTargeting.h"

void UFortAbilityTask_WaitPerformTargeting::OnTargetDataCancelledCallback()
{
}

void UFortAbilityTask_WaitPerformTargeting::OnTargetDataReadyCallback(const FGameplayAbilityTargetDataHandle& TargetData, FGameplayTag ApplicationTag)
{
}

UFortAbilityTask_WaitPerformTargeting* UFortAbilityTask_WaitPerformTargeting::WaitPerformTargeting(UGameplayAbility* OwningAbility, FName TaskInstanceName, UTargetingPreset* TargetingPreset, bool bForceTargetingOnServer, bool bUseAsyncTargeting)
{
	return nullptr;
}

UFortAbilityTask_WaitPerformTargeting* UFortAbilityTask_WaitPerformTargeting::WaitPerformTargetingWithTargets(UGameplayAbility* OwningAbility, FName TaskInstanceName, UTargetingPreset* TargetingPreset, bool bForceTargetingOnServer, bool bUseAsyncTargeting, const TArray<AActor*> InTargets)
{
	return nullptr;
}
