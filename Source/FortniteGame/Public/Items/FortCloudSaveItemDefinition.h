// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Items/FortMetadataItemDefinition.h"
#include "FortCloudSaveItemDefinition.generated.h"

USTRUCT()
struct FFortCloudSaveRecordInfo
{
	GENERATED_BODY()

public:
	UPROPERTY()
	int32 RecordIndex;

	UPROPERTY()
	int32 ArchiveNumber;

	UPROPERTY()
	FString RecordFilename;

};

USTRUCT()
struct FFortCloudSaveInfo
{
	GENERATED_BODY()

public:
	UPROPERTY()
	int32 SaveCount;

	UPROPERTY()
	TArray<FFortCloudSaveRecordInfo> SavedRecords;

};

UCLASS(Abstract, MinimalAPI)
class UFortCloudSaveItemDefinition : public UFortMetadataItemDefinition
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Category="Save")
	int32 ContentVersion;

};

