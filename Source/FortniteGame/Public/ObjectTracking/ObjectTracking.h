// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "UObject/NoExportTypes.h"
#include "ObjectTracking/FortBudgetCategory.h"
#include "ObjectTracking.generated.h"

UENUM()
namespace EFortBudgetType
{
	enum Type
	{
		/* Actual used budget*/
		Live = 0,
		/* Next potential budget */
		Preview = 1,
		Max = 2,
	};
}

USTRUCT()
struct FObjectCostVersion
{
	GENERATED_BODY()

public:
	UPROPERTY()
	int32 MajorVersion;

	UPROPERTY()
	int64 TimeStamp;

	UPROPERTY()
	uint32 MinorVersionStringHash;

#if WITH_EDITORONLY_DATA
	UPROPERTY()
	FString MinorVersionString;
#endif

};

USTRUCT(BlueprintType)
struct FVolumePerformanceMetrics
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="VolumePerformanceMetrics")
	int32 PerformanceValue;

	UPROPERTY(BlueprintReadOnly, Category="VolumePerformanceMetrics")
	int32 PerformanceMaxValue;

	UPROPERTY(BlueprintReadOnly, Category="VolumePerformanceMetrics")
	int32 PerformanceValueMargin;

	UPROPERTY(BlueprintReadOnly, Category="VolumePerformanceMetrics")
	FIntPoint PerformanceValueCellIndex;

	UPROPERTY(BlueprintReadOnly, Category="VolumePerformanceMetrics")
	int32 PerformanceLowendThreshold;

	UPROPERTY(BlueprintReadOnly, Category="VolumePerformanceMetrics")
	int32 PreviewDeltaValue;

	UPROPERTY(BlueprintReadOnly, Category="VolumePerformanceMetrics")
	EFortBudgetCategory Category;

	UPROPERTY(BlueprintReadOnly, Category="VolumePerformanceMetrics")
	int32 PlayerID;

	UPROPERTY(BlueprintReadOnly, Category="VolumePerformanceMetrics")
	int32 MostExpensivePerformanceValue;

	UPROPERTY(BlueprintReadOnly, Category="VolumePerformanceMetrics")
	int32 MostExpensivePreviewDeltaValue;

	UPROPERTY(BlueprintReadOnly, Category="VolumePerformanceMetrics")
	FIntPoint MostExpensivePerformanceValueCellIndex;

};

UCLASS()
class UVolumePerformanceMetricsHelpers : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	static void CheckIfVolumeWillBeOverMemory(const FVolumePerformanceMetrics& InMetrics, UPARAM(DisplayName="IsOverMemoryLimit") bool& bOutIsOverMemoryLimit, UPARAM(DisplayName="IsOverMemoryMargin") bool& bOutIsOverMemoryMargin);

};

