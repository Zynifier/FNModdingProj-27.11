// Copyright Epic Games, Inc. All Rights Reserved.

#include "STW/Items/FortSchematicItem.h"

int32 UFortSchematicItem::GetRequiredTeamLevelToCraft() const
{
	return int32();
}

int32 UFortSchematicItem::GetSchematicQuantityProduced() const
{
	return int32();
}

FRecipe UFortSchematicItem::GetSchematicRecipe() const
{
	return FRecipe();
}

bool UFortSchematicItem::IsBulkCraftable() const
{
	return false;
}
