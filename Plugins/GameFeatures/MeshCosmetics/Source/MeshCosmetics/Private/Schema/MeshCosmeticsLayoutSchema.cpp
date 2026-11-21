// Copyright Epic Games, Inc. All Rights Reserved.

#include "Schema/MeshCosmeticsLayoutSchema.h"
#include "UObject/Class.h"

bool FCosmeticSlotSelector::operator==(const FCosmeticSlotSelector& Other) const
{
	return StaticStruct()->CompareScriptStruct(this, &Other, 0);
}

uint32 GetTypeHash(const FCosmeticSlotSelector& Value)
{
	return 0;
}
