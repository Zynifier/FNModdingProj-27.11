// Copyright Epic Games, Inc. All Rights Reserved.

#include "Abilities/Tasks/FortAbilityTask_PlayAnimAndWait.h"

UFortAbilityTask_PlayAnimAndWait* UFortAbilityTask_PlayAnimAndWait::CreatePlayAnimAndWaitProxy(UGameplayAbility* OwningAbility, FName TaskInstanceName, const FFortGameplayAbilityMontageInfo& PlayMontageInfo, EFortSharedAnimationState AnimState, bool bStopWhenAbilityEnds)
{
	return nullptr;
}

void UFortAbilityTask_PlayAnimAndWait::OnAnimBlendingOut(UAnimMontage* Montage, bool bInterrupted)
{
}

void UFortAbilityTask_PlayAnimAndWait::OnAnimInterrupted()
{
}
