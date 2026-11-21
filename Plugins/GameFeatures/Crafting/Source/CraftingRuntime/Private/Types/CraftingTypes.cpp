// Copyright Epic Games, Inc. All Rights Reserved.

#include "Types/CraftingTypes.h"
#include "UObject/Class.h"

bool FCraftingMultiKey::operator==(const FCraftingMultiKey& Other) const
{
	return StaticStruct()->CompareScriptStruct(this, &Other, 0);
}

uint32 GetTypeHash(const FCraftingMultiKey& Value)
{
	return 0;
}
