// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "JsonObjectWrapper.h"
#include "Online/Collections/FortCollectionsTypes.h"
#include "FortMcpCollectionsBulkUpdateEntry.generated.h"

USTRUCT()
struct FFortMcpCollectionsBulkUpdateEntry
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString Category;

	UPROPERTY()
	FString Variant;

	UPROPERTY()
	TArray<FString> ContextTags;

	UPROPERTY()
	FJsonObjectWrapper Properties;

	UPROPERTY()
	EFortCollectedState SeenState;

	UPROPERTY()
	int32 Count;

};

USTRUCT()
struct FFortMcpCollectionsVariant
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString Category;

	UPROPERTY()
	FString Variant;

};

