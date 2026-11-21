// Copyright Epic Games, Inc. All Rights Reserved.

#include "Cosmetics/Variants/FortCosmeticVariantInfo.h"
#include "UObject/Class.h"

bool FCosmeticVariantInfo::operator==(const FCosmeticVariantInfo& Other) const
{
	return StaticStruct()->CompareScriptStruct(this, &Other, 0);
}

uint32 GetTypeHash(const FCosmeticVariantInfo& Value)
{
	return 0;
}
