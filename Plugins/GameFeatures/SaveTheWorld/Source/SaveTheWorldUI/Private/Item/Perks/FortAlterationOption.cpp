// Copyright Epic Games, Inc. All Rights Reserved.

#include "Item/Perks/FortAlterationOption.h"

UFortAlterationItemDefinition* UFortAlterationOption::GetAlterationDefinition() const
{
	return nullptr;
}

EFortAlterationOptionType UFortAlterationOption::GetAlterationOptionType() const
{
	return EFortAlterationOptionType();
}

float UFortAlterationOption::GetCurrentPipCount(float MaxPipCount) const
{
	return float();
}

float UFortAlterationOption::GetNextPipCount(float MaxPipCount) const
{
	return float();
}

TArray<FFortItemQuantityPair> UFortAlterationOption::GetRequiredIngredients() const
{
	return TArray<FFortItemQuantityPair>();
}

void UFortAlterationOption::Setup(FAlterationOption& InAlterationOption, EFortAlterationOptionType InAlterationOptionType)
{
}
