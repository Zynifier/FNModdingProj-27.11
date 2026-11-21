// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AthenaLevelInfo.generated.h"

USTRUCT(BlueprintType)
struct FAthenaLevelInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="AthenaLevelInfo")
	int32 AccountLevel;

	UPROPERTY(BlueprintReadOnly, Category="AthenaLevelInfo")
	int32 Level;

	UPROPERTY(BlueprintReadOnly, Category="AthenaLevelInfo")
	int32 MaxLevel;

	UPROPERTY(BlueprintReadOnly, Category="AthenaLevelInfo")
	int32 LevelXp;

	UPROPERTY(BlueprintReadOnly, Category="AthenaLevelInfo")
	int32 LevelXpForLevel;

	UPROPERTY(BlueprintReadOnly, Category="AthenaLevelInfo")
	int32 BookLevel;

	UPROPERTY(BlueprintReadOnly, Category="AthenaLevelInfo")
	int32 BookMaxLevel;

	UPROPERTY(BlueprintReadOnly, Category="AthenaLevelInfo")
	int32 BookLevelXp;

	UPROPERTY(BlueprintReadOnly, Category="AthenaLevelInfo")
	int32 BookLevelXpForLevel;

};

