// Copyright Epic Games, Inc. All Rights Reserved.

#include "Cosmetics/Extensibility/FortCosmeticExtensibilityTypes.h"
#include "UObject/Class.h"

bool FCosmeticFlowGraphKey::operator==(const FCosmeticFlowGraphKey& Other) const
{
	return StaticStruct()->CompareScriptStruct(this, &Other, 0);
}

uint32 GetTypeHash(const FCosmeticFlowGraphKey& Value)
{
	return 0;
}

bool FCosmeticFlowOptionSetKey::operator==(const FCosmeticFlowOptionSetKey& Other) const
{
	return StaticStruct()->CompareScriptStruct(this, &Other, 0);
}

uint32 GetTypeHash(const FCosmeticFlowOptionSetKey& Value)
{
	return 0;
}
