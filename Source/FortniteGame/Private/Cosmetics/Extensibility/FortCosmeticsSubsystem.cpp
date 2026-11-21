// Copyright Epic Games, Inc. All Rights Reserved.

#include "Cosmetics/Extensibility/FortCosmeticsSubsystem.h"
#include "UObject/Class.h"

bool FCosmeticsPassLookupKey::operator==(const FCosmeticsPassLookupKey& Other) const
{
	return StaticStruct()->CompareScriptStruct(this, &Other, 0);
}

uint32 GetTypeHash(const FCosmeticsPassLookupKey& Value)
{
	return 0;
}
