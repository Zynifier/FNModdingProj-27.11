// Copyright Epic Games, Inc. All Rights Reserved.

#include "Items/FortConsumableItemDefinition.h"

void UFortConsumableItemDefinition::ConsumeItem(const FGameplayEventData& EventData)
{
}

float UFortConsumableItemDefinition::GetAnimPlayRate() const
{
	return float();
}

float UFortConsumableItemDefinition::GetHealthRestored(int32 ItemLevel) const
{
	return float();
}

UAnimMontage* UFortConsumableItemDefinition::GetUseAnimation() const
{
	return nullptr;
}
