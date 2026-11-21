// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortCreativeVkPalette.h"
#include "VkDeltasStorage.generated.h"

USTRUCT()
struct FVkDeltasStorage_PackageFileMap
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TMap<FString, FString> PackageDeltaFiles;

};

USTRUCT()
struct FVkProjectDeltas_ProjectIndex
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString SnapshotId;

	UPROPERTY()
	FFortCreativeVkPalette Palette;

	UPROPERTY()
	FVkDeltasStorage_PackageFileMap FileMap;

};

