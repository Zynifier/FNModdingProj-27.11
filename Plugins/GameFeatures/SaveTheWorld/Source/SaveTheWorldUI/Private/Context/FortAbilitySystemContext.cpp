// Copyright Epic Games, Inc. All Rights Reserved.

#include "Context/FortAbilitySystemContext.h"

bool UFortAbilitySystemContext::HasMatchingGameplayTag(FGameplayTag TagToCheck) const
{
	return false;
}

void UFortAbilitySystemContext::RegisterForAttributeChanged(UWidget* Widget, UAbilitySystemComponent* ASC, FGameplayAttribute Attribute, FAttributeChangedDelegate Callback)
{
}

void UFortAbilitySystemContext::RemoveDelegatesFromWidget(UWidget* Widget)
{
}
