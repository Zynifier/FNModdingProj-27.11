// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "VkContentServiceTypes.h"
#include "FortCreativeVkPalette.generated.h"

USTRUCT()
struct FFortCreativeVkPalette_ProjectInfo
{
	GENERATED_BODY()

public:
	UPROPERTY()
	int32 LinkVersion;

	UPROPERTY(Transient)
	TArray<FVkModuleVersionRef> PublicModules;

};

USTRUCT()
struct FFortCreativeVkPalette
{
	GENERATED_BODY()

private:
	UPROPERTY()
	TMap<FString, FFortCreativeVkPalette_ProjectInfo> MnemonicMap;

};

