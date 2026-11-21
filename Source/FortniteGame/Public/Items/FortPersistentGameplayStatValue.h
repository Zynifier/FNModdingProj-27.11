// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortPersistentGameplayStatValue.generated.h"

USTRUCT()
struct FFortPersistentGameplayStatValue
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString StatName;

	UPROPERTY()
	int32 StatValue;

};

USTRUCT()
struct FFortPersistentGameplayStatContainer
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TArray<FFortPersistentGameplayStatValue> GameplayStats;

};

