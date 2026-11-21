// Copyright Epic Games, Inc. All Rights Reserved.

#include "Abilities/Tasks/FortAbilityTask_WaitAnimBPOverride.h"

void UFortAbilityTask_WaitAnimBPOverride::OnFinishedCharacterCustomizationCallback(AFortPlayerPawn* InPawn)
{
}

void UFortAbilityTask_WaitAnimBPOverride::OnPawnAnimBPCallback()
{
}

UFortAbilityTask_WaitAnimBPOverride* UFortAbilityTask_WaitAnimBPOverride::WaitAnimBPOverrideReady(UGameplayAbility* OwningAbility, TSoftClassPtr<UAnimInstance> AnimInstance, TSoftObjectPtr<UFortGadgetItemDefinition> GadgetItemDef)
{
	return nullptr;
}
