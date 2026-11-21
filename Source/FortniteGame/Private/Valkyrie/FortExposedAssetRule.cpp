// Copyright Epic Games, Inc. All Rights Reserved.

#include "Valkyrie/FortExposedAssetRule.h"
#include "UObject/Class.h"

bool FFortExposedAsset::operator==(const FFortExposedAsset& Other) const
{
	return StaticStruct()->CompareScriptStruct(this, &Other, 0);
}

uint32 GetTypeHash(const FFortExposedAsset& Value)
{
	return 0;
}
