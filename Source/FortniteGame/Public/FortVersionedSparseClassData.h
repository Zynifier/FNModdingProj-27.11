// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortVersionedSparseClassData.generated.h"

USTRUCT()
struct FFortSparseClassDataVersionEntry
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleDefaultsOnly, Category="FortSparseClassDataVersionEntry")
	int32 Version;

};

USTRUCT(BlueprintType)
struct FFortVersionedSparseClassData
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleDefaultsOnly, Category="FortVersionedSparseClassData")
	TMap<FString, FFortSparseClassDataVersionEntry> ClassToProcessedVersionMap;

};

