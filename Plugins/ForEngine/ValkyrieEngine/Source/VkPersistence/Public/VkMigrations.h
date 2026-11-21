// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "VkMigrations.generated.h"

USTRUCT()
struct FVkPersistenceVersion
{
	GENERATED_BODY()

public:
	UPROPERTY()
	int32 Version;

	UPROPERTY()
	FString Name;

};

