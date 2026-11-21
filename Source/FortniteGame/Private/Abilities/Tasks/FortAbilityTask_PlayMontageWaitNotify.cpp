// Copyright Epic Games, Inc. All Rights Reserved.

#include "Abilities/Tasks/FortAbilityTask_PlayMontageWaitNotify.h"

void UFortAbilityTask_PlayMontageWaitNotify::OnAbilityCancelled()
{
}

void UFortAbilityTask_PlayMontageWaitNotify::OnMontageBlendingOut(UAnimMontage* Montage, bool bInterrupted)
{
}

void UFortAbilityTask_PlayMontageWaitNotify::OnMontageEnded(UAnimMontage* Montage, bool bInterrupted)
{
}

void UFortAbilityTask_PlayMontageWaitNotify::OnMontageNotifyBegin(UAnimSequenceBase* Animation, FGameplayTag NotifyTag)
{
}

void UFortAbilityTask_PlayMontageWaitNotify::OnMontageNotifyEnd(UAnimSequenceBase* Animation, FGameplayTag NotifyTag)
{
}

UFortAbilityTask_PlayMontageWaitNotify* UFortAbilityTask_PlayMontageWaitNotify::PlayMontageAndWaitNotify(UGameplayAbility* OwningAbility, FName TaskInstanceName, UAnimMontage* MontageToPlay, float PlayRate, FName StartSection, bool bStopWhenAbilityEnds, float RootMotionTranslationScale)
{
	return nullptr;
}
