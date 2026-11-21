// Copyright Epic Games, Inc. All Rights Reserved.

#include "STW/Items/FortSchematicItemDefinition.h"

bool UFortSchematicItemDefinition::DoesResultWorldItemDisassembleRecipeMatchExactly() const
{
	return false;
}

USoundBase* UFortSchematicItemDefinition::GetCraftingSuccessSound() const
{
	return nullptr;
}

float UFortSchematicItemDefinition::GetCraftingTime(int32 Level) const
{
	return float();
}

float UFortSchematicItemDefinition::GetCraftingTimeForCharacter(int32 Level, const AFortPlayerPawn* FortPawn) const
{
	return float();
}

int32 UFortSchematicItemDefinition::GetQuantityProduced() const
{
	return int32();
}

FRecipe UFortSchematicItemDefinition::GetRecipe() const
{
	return FRecipe();
}

UFortWorldItemDefinition* UFortSchematicItemDefinition::GetResultWorldItemDefinition() const
{
	return nullptr;
}
