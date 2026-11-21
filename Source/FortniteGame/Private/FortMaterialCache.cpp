// Copyright Epic Games, Inc. All Rights Reserved.

#include "FortMaterialCache.h"

void UFortMaterialCache::ReleaseMaterial(UMaterialInstanceDynamic*& MaterialInstance)
{
}

bool UFortMaterialCache::ReserveMaterial(UMaterialInstanceDynamic*& OutMaterialInstance)
{
	return false;
}

UFortMaterialCache* UFortMaterialCacheManager::GetCache(UObject* WorldContextObject, const FDataTableRowHandle& CacheSettings, UMaterialInterface* BaseMaterial)
{
	return nullptr;
}
