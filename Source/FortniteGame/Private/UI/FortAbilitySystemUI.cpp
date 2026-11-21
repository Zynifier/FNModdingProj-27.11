// Copyright Epic Games, Inc. All Rights Reserved.

#include "UI/FortAbilitySystemUI.h"

UGameplayEffect* UFortAbilitySystemUI::GetDefaultObjectOfGameplayEffectType(TSubclassOf<UGameplayEffect> EffectType)
{
	return nullptr;
}

FFortGameplayEffectDescription UFortAbilitySystemUI::GetStaticGameplayEffectDescription(const UGameplayEffect* Effect, float Level)
{
	return FFortGameplayEffectDescription();
}
