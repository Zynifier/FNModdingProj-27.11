// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "EpicMediaSegmentCacheStorage.h"
#include "EpicMediaSegmentCacheInit.generated.h"

UCLASS(Config=Engine)
class EPICMEDIASEGMENTCACHE_API UEpicMediaSegmentCacheInit : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(Config)
	FEpicMediaSegmentCacheConfig CacheConfig;

};

