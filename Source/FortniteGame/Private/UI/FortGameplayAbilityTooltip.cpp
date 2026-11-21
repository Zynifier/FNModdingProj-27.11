// Copyright Epic Games, Inc. All Rights Reserved.

#include "UI/FortGameplayAbilityTooltip.h"

bool UFortGameplayAbilityTooltip::GetApplicationTag_Implementation(const UGameplayAbility* AbilityInstance, FGameplayTag& OutTag) const
{
	return false;
}

bool UFortGameplayAbilityTooltip::GetTextForTokenFromAbilityInstance(const UGameplayAbility* AbilityInstance, const FGameplayTag& Tag, const UFortTooltipContext* Context, const FGameplayTag& Token, FText& OutText) const
{
	return false;
}

bool UFortGameplayAbilityTooltip::GetTextForTokenFromAbilityInstanceInternal_Implementation(const UGameplayAbility* AbilityInstance, const FGameplayTag& Tag, const UFortTooltipContext* Context, const FGameplayTag& Token, FText& OutText) const
{
	return false;
}

bool UFortGameplayAbilityTooltip::GetTextForTokenFromAbilitySpec(const FGameplayAbilitySpec& Spec, const FGameplayTag& Tag, const UFortTooltipContext* Context, const FGameplayTag& Token, FText& OutText) const
{
	return false;
}

bool UFortGameplayAbilityTooltip::GetTextForTokenFromAbilitySpecInternal_Implementation(const FGameplayAbilitySpec& Spec, const FGameplayTag& Tag, const UFortTooltipContext* Context, const FGameplayTag& Token, FText& OutText) const
{
	return false;
}

void UFortGameplayAbilityTooltip::InitializeAbilityInstance(const UGameplayAbility* AbilityInstance, const UFortTooltipContext* Context) const
{
}

void UFortGameplayAbilityTooltip::InitializeAbilityInstanceInternal_Implementation(const UGameplayAbility* AbilityInstance, const UFortTooltipContext* Context) const
{
}
