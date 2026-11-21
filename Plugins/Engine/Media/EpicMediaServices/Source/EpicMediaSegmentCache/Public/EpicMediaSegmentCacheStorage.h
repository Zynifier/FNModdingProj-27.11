// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "EpicMediaSegmentCacheStorage.generated.h"

/**
* Cache initialization.
*/
USTRUCT()
struct EPICMEDIASEGMENTCACHE_API FEpicMediaSegmentCacheConfig
{
	GENERATED_BODY()

public:
	UPROPERTY(Config)
	bool bEnabled;

	UPROPERTY(Config)
	bool bResetCache;

	//! Try to put the cache in a persistent partition

	UPROPERTY(Config)
	bool bPersistentCache;

	//! On some platforms, we are not write-speed limited. If we do not get a configured temporary cache location, we can use the persistent location and clean during start

	UPROPERTY(Config)
	bool bAllowPersistentCacheAsTemporary;

	//! Independet of the cache location, create an empty cache

	UPROPERTY(Config)
	bool bClearCache;

	//! Max number of allowed cache entries on disk (physical file count is times 2 for "data" and "data.meta" files)

	UPROPERTY(Config)
	int32 CacheSizeMaxFiles;

	//! Max size of cache on disk

	UPROPERTY(Config)
	int64 CacheSizeOnDiskMaxBytes;

};

