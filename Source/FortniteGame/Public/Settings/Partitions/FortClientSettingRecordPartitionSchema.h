// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortClientSettingRecordPartitionSchema.generated.h"

class UFortClientSettingRecordPartition;

USTRUCT()
struct FFortClientSettingRecordPartitionSchema
{
	GENERATED_BODY()

private:
	UPROPERTY()
	FName ResolvingPartitionName;

	UPROPERTY()
	TArray<uint8> PartitionContents;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UFortClientSettingRecordPartition> ResolvedPartition;

};

