// Copyright Epic Games, Inc. All Rights Reserved.

#include "Attributes/FortRegenHealthSetInterface.h"

UGameplayEffect* IFortHealthRegenInterface::GetHealthRegenDelayGameplayEffect() const
{
	return nullptr;
}

UGameplayEffect* IFortHealthRegenInterface::GetHealthRegenGameplayEffect() const
{
	return nullptr;
}

TSubclassOf<UGameplayEffect> IFortHealthRegenInterface::GetHealthRegenGameplayEffectClass() const
{
	return TSubclassOf<UGameplayEffect>();
}

UGameplayEffect* IFortHealthRegenInterface::GetShieldRegenDelayGameplayEffect() const
{
	return nullptr;
}

UGameplayEffect* IFortHealthRegenInterface::GetShieldRegenGameplayEffect() const
{
	return nullptr;
}

TSubclassOf<UGameplayEffect> IFortHealthRegenInterface::GetShieldRegenGameplayEffectClass() const
{
	return TSubclassOf<UGameplayEffect>();
}
