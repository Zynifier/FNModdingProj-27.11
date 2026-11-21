// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortRecordVersion.generated.h"

USTRUCT()
struct FReflectedEngineVersion
{
	GENERATED_BODY()

public:
	UPROPERTY()
	int32 Major;

	UPROPERTY()
	int32 Minor;

	UPROPERTY()
	int32 Patch;

	UPROPERTY()
	int32 Changelist;

	UPROPERTY()
	FString Branch;

};

USTRUCT()
struct FFortRecordVersion
{
	GENERATED_BODY()

public:
	UPROPERTY()
	int32 DataVersion;

	UPROPERTY()
	int32 PackageFileVersion;

	UPROPERTY()
	FReflectedEngineVersion EngineVersion;

};

