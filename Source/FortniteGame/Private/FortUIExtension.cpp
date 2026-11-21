// Copyright Epic Games, Inc. All Rights Reserved.

#include "FortUIExtension.h"
#include "UObject/Class.h"

bool FUIExtension::operator==(const FUIExtension& Other) const
{
	return StaticStruct()->CompareScriptStruct(this, &Other, 0);
}

uint32 GetTypeHash(const FUIExtension& Value)
{
	return 0;
}
