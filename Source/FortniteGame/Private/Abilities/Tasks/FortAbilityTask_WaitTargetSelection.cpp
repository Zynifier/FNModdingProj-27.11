// Copyright Epic Games, Inc. All Rights Reserved.

#include "Abilities/Tasks/FortAbilityTask_WaitTargetSelection.h"

void UFortAbilityTask_WaitTargetSelection::OnTargetDataCancelledCallback()
{
}

void UFortAbilityTask_WaitTargetSelection::OnTargetDataReadyCallback(const FGameplayAbilityTargetDataHandle& TargetData, FGameplayTag ApplicationTag)
{
}

UFortAbilityTask_WaitTargetSelection* UFortAbilityTask_WaitTargetSelection::WaitTargetSelection(UGameplayAbility* OwningAbility, FName TaskInstanceName, FGameplayTag InApplicationTag, bool bForceTargetingOnServer)
{
	return nullptr;
}
