// Copyright Epic Games, Inc. All Rights Reserved.

#include "Abilities/Tasks/FortAbilityTask_PlayAnimWaitTarget.h"

void UFortAbilityTask_PlayAnimWaitTarget::OnTargetDataCancelledCallback()
{
}

void UFortAbilityTask_PlayAnimWaitTarget::OnTargetDataReadyCallback(const FGameplayAbilityTargetDataHandle& TargetData, FGameplayTag ApplicationTag)
{
}

UFortAbilityTask_PlayAnimWaitTarget* UFortAbilityTask_PlayAnimWaitTarget::PlayAnimWaitTarget(UGameplayAbility* OwningAbility, FName TaskInstanceName, UAnimMontage* MontageToPlay, EFortSharedAnimationState AnimState, EFortGameplayAbilityMontageSectionToPlay SectionToPlay, FName OverrideSection)
{
	return nullptr;
}

UFortAbilityTask_PlayAnimWaitTarget* UFortAbilityTask_PlayAnimWaitTarget::PlayAnimWithMontageInfoAndWaitForTrigger(UGameplayAbility* OwningAbility, FName TaskInstanceName, const FFortGameplayAbilityMontageInfo& MontageInfo, EFortSharedAnimationState AnimState)
{
	return nullptr;
}
