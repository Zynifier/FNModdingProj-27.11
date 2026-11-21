// Copyright Epic Games, Inc. All Rights Reserved.

#include "Core/FortSpatialGrid.h"
#include "UObject/Class.h"

bool FFortSpatialCellIndex::operator==(const FFortSpatialCellIndex& Other) const
{
	return StaticStruct()->CompareScriptStruct(this, &Other, 0);
}

uint32 GetTypeHash(const FFortSpatialCellIndex& Value)
{
	return 0;
}
