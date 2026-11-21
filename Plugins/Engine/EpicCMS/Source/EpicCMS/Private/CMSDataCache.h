// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Misc/DateTime.h"
#include "CMSDataCache.generated.h"

USTRUCT()
struct FDownloadCacheEntry
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString Filepath;

	UPROPERTY()
	FString SourceUrl;

	UPROPERTY()
	FDateTime LastAccessTime;

};

USTRUCT()
struct FDownloadCache
{
	GENERATED_BODY()

private:
	UPROPERTY()
	int32 Version;

	/*SourceUrl*/
	UPROPERTY()
	TMap<FString, FDownloadCacheEntry> Cache;

};

