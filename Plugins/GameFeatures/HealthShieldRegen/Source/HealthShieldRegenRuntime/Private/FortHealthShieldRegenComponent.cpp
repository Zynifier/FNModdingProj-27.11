// Copyright Epic Games, Inc. All Rights Reserved.

#include "FortHealthShieldRegenComponent.h"

bool UFortHealthShieldRegenComponent::AllowHealthShieldRegen()
{
	return false;
}

void UFortHealthShieldRegenComponent::AssignHealthShieldRegen_HealthListenerDelegates(const UGameplayAbility* OwningAbility, FFortHealthShieldRegen_HealthDelegateContainer Delegates)
{
}

void UFortHealthShieldRegenComponent::AssignHealthShieldRegen_ShieldListenerDelegates(const UGameplayAbility* OwningAbility, FFortHealthShieldRegen_ShieldDelegateContainer Delegates)
{
}

void UFortHealthShieldRegenComponent::ClearHealthShieldRegen_HealthListenerDelegates(const UGameplayAbility* OwningAbility)
{
}

void UFortHealthShieldRegenComponent::ClearHealthShieldRegen_ShieldListenerDelegates(const UGameplayAbility* OwningAbility)
{
}
