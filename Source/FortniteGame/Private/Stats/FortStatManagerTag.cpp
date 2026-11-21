// Copyright Epic Games, Inc. All Rights Reserved.

#include "Stats/FortStatManagerTag.h"
#include "UObject/Class.h"

bool FFortStatManagerTag::operator==(const FFortStatManagerTag& Other) const
{
	return StaticStruct()->CompareScriptStruct(this, &Other, 0);
}

uint32 GetTypeHash(const FFortStatManagerTag& Value)
{
	return 0;
}
