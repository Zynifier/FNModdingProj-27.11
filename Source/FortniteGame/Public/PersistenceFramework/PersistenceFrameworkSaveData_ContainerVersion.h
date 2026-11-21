// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "PersistenceFrameworkSaveData_ContainerVersion.generated.h"

USTRUCT()
struct FORTNITEGAME_API FPersistenceFrameworkSaveData_ContainerVersion
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FName Guid;

	UPROPERTY()
	uint64 Version;

};

USTRUCT()
struct FORTNITEGAME_API FPersistenceFrameworkSaveData_VersionTable
{
	GENERATED_BODY()

protected:
	UPROPERTY()
	TMap<uint64, FName> VersionToGuid;

	UPROPERTY()
	FPersistenceFrameworkSaveData_ContainerVersion HighestVersion;

};

