// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortExposedAssetProviderVersionCache.generated.h"

USTRUCT()
struct FFortExposedAssetProviderCachedVersion
{
	GENERATED_BODY()

public:
#if WITH_EDITORONLY_DATA
	UPROPERTY()
	bool bImplementsExposedAssetProvider;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY()
	uint32 VersionHash;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY()
	uint32 ParentVersionHash;
#endif

};

