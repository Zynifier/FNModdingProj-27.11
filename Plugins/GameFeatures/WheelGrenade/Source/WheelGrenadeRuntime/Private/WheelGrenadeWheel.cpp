// Copyright Epic Games, Inc. All Rights Reserved.

#include "WheelGrenadeWheel.h"

float AWheelGrenadeWheel::GetHealth() const
{
	return float();
}

float AWheelGrenadeWheel::GetMaxHealth() const
{
	return float();
}

void AWheelGrenadeWheel::HandleOutOfHealth_Implementation(const float InDamage, const FGameplayTagContainer& InTags, const FGameplayEffectContextHandle& InEffectContext, AController* InEventInstigator, AActor* InDamageCauser)
{
}

UAbilitySystemComponent* AWheelGrenadeWheel::GetAbilitySystemComponent() const
{
	return nullptr;
}
