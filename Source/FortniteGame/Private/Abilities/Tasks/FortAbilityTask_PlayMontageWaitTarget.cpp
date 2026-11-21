// Copyright Epic Games, Inc. All Rights Reserved.

#include "Abilities/Tasks/FortAbilityTask_PlayMontageWaitTarget.h"

void UFortAbilityTask_PlayMontageWaitTarget::EnableScalingWithRateOfFire()
{
}

void UFortAbilityTask_PlayMontageWaitTarget::OnTargetDataCancelledCallback()
{
}

void UFortAbilityTask_PlayMontageWaitTarget::OnTargetDataReadyCallback(const FGameplayAbilityTargetDataHandle& TargetData, FGameplayTag ApplicationTag)
{
}

UFortAbilityTask_PlayMontageWaitTarget* UFortAbilityTask_PlayMontageWaitTarget::PlayMontageInfoAndWaitForTrigger(UGameplayAbility* OwningAbility, FName TaskInstanceName, const FFortGameplayAbilityMontageInfo& MontageInfo, EFortAbilityTargetDataPolicy TargetDataPolicy)
{
	return nullptr;
}

UFortAbilityTask_PlayMontageWaitTarget* UFortAbilityTask_PlayMontageWaitTarget::PlayMontageWaitTarget(UGameplayAbility* OwningAbility, FName TaskInstanceName, UAnimMontage* MontageToPlay, float AnimPlayRate, EFortGameplayAbilityMontageSectionToPlay SectionToPlay, FName OverrideSection, float AnimRootMotionTranslationScale, EFortAbilityTargetDataPolicy TargetDataPolicy)
{
	return nullptr;
}

UFortAbilityTask_PlayMontageWaitTarget* UFortAbilityTask_PlayMontageWaitTarget::PlayMontageWithCharPartsWait(UGameplayAbility* OwningAbility, FName TaskInstanceName, UAnimMontage* MontageToPlay, TArray<FFortCharacterPartMontageInfo> CharacterPartMontages, float AnimPlayRate, EFortGameplayAbilityMontageSectionToPlay SectionToPlay, FName OverrideSection, float AnimRootMotionTranslationScale, EFortAbilityTargetDataPolicy TargetDataPolicy)
{
	return nullptr;
}
