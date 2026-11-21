// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "FortBudgetGridMemoryStats.generated.h"

USTRUCT(BlueprintType)
struct FFortBudgetGridCellMemoryStats
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="FortBudgetGridCellMemoryStats")
	int32 MemoryValue;

	UPROPERTY(BlueprintReadOnly, Category="FortBudgetGridCellMemoryStats")
	int32 PreviewValue;

	UPROPERTY(BlueprintReadOnly, Category="FortBudgetGridCellMemoryStats")
	FIntPoint CellIndex;

};

USTRUCT(BlueprintType)
struct FFortBudgetGridMemoryStats
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="FortBudgetGridMemoryStats")
	int32 MinValue;

	UPROPERTY(BlueprintReadOnly, Category="FortBudgetGridMemoryStats")
	FIntPoint MinValueCellIndex;

	UPROPERTY(BlueprintReadOnly, Category="FortBudgetGridMemoryStats")
	int32 MaxValue;

	UPROPERTY(BlueprintReadOnly, Category="FortBudgetGridMemoryStats")
	FIntPoint MaxValueCellIndex;

	UPROPERTY(BlueprintReadOnly, Category="FortBudgetGridMemoryStats")
	int32 AverageValue;

	UPROPERTY(BlueprintReadOnly, Category="FortBudgetGridMemoryStats")
	int32 MedianValue;

};

