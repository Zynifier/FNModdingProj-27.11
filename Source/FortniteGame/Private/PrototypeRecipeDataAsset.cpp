// Copyright Epic Games, Inc. All Rights Reserved.

#include "PrototypeRecipeDataAsset.h"

int32 UPrototypeRecipeDataAsset::GetCraftingDuration()
{
	return int32();
}

bool UPrototypeRecipeDataAsset::GetHiddenByDefault()
{
	return false;
}

TArray<FPrototypeCraftingIngredient> UPrototypeRecipeDataAsset::GetInputs()
{
	return TArray<FPrototypeCraftingIngredient>();
}

int32 UPrototypeRecipeDataAsset::GetMaxNumberOfOutputs()
{
	return int32();
}

TArray<FPrototypeCraftingOutput> UPrototypeRecipeDataAsset::GetOutputs()
{
	return TArray<FPrototypeCraftingOutput>();
}
