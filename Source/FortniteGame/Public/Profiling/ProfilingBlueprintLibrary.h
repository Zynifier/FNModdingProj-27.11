// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ObjectTracking/FortBudgetCategory.h"
#include "ProfilingBlueprintLibrary.generated.h"

class AActor;
enum class EFortBudgetCategory : uint8;

USTRUCT(BlueprintType)
struct FAnimClassStats
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, Category="AnimClassStats")
	FString AnimClassName;

	UPROPERTY(BlueprintReadWrite, Category="AnimClassStats")
	TMap<FString, float> StatValues;

};

USTRUCT(BlueprintType)
struct FCreativePerfCost
{
	GENERATED_BODY()

};

UCLASS(meta=(ScriptName="CreativeBlueprintProfiling"))
class UCreativeProfilingHelper : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Profiling | Creative", meta=(AutoCreateRefTerm="InPrevCapture, OutComparison"))
	static FCreativePerfCost CaptureActorThermometerValue(AActor* InActor, EFortBudgetCategory Category = EFortBudgetCategory::Memory);

	UFUNCTION(BlueprintCallable, Category="Profiling | Creative", meta=(AutoCreateRefTerm="InPrevCapture, OutComparison"))
	static FCreativePerfCost CaptureOverallThermometerValue(float InPrevCapture, float& OutComparison, EFortBudgetCategory Category = EFortBudgetCategory::Memory);

	UFUNCTION(BlueprintCallable, Category="Profiling | Memstats")
	static void PrintThermometerCaptureToCsv(FCreativePerfCost InCapture, const FString& InFileName, const FString& OptionalCaptureName = TEXT(""));

	UFUNCTION(BlueprintCallable, Category="Profiling | Creative")
	static void PrintThermometerCaptureToLog(FCreativePerfCost InCapture, const FString& CaptureName);

};

UCLASS(meta=(ScriptName="FrameStatsProfiling"))
class UFrameStatsProfilingHelper : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Profiling | Framestats")
	static void StartRecordingFrameStats(const FString& FPSChartLabel);

	UFUNCTION(BlueprintCallable, Category="Profiling | Framestats")
	static void StopRecordingFrameStats(const FString& MapName = TEXT("None"));

};

UCLASS(meta=(ScriptName="MemoryStatsProfiling"))
class UMemoryStatsProfilingHelper : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Profiling | Memstats", meta=(AutoCreateRefTerm="InPrevCapture, OutComparison"))
	static TMap<FString, float> CaptureMemoryValues(TMap<FString, float> InPrevCapture, TMap<FString, float>& OutComparison, bool bConvertToMB = false);

	UFUNCTION(BlueprintCallable, Category="Profiling | Memstats")
	static void FinalizeMemoryCaptureCsv(const FString& InFileName);

	UFUNCTION(BlueprintCallable, Category="Profiling | Memstats")
	static void PrintMemoryCaptureToCsv(TMap<FString, float> InCapture, const FString& InFileName, const FString& OptionalCaptureName = TEXT(""));

	UFUNCTION(BlueprintCallable, Category="Profiling | Memstats")
	static void PrintMemoryCaptureToLog(TMap<FString, float> InCapture, bool bCaptureIsInMB = false);

};

UCLASS(meta=(ScriptName="PrimitiveStatsProfiling"))
class UPrimitiveStatsProfilingHelper : public UObject
{
	GENERATED_BODY()

private:
	UFUNCTION(BlueprintCallable, Category="Profiling | Primitives", meta=(AutoCreateRefTerm="InPrevCapture, OutComparison, DesiredStats"))
	static TMap<FString, float> CapturePrimitiveValues(TMap<FString, float> InPrevCapture, TMap<FString, float>& OutComparison, TArray<FString> DesiredStats);

	UFUNCTION(BlueprintCallable, Category="Profiling | Primitives")
	static void EnablePrimitiveStatsCapture();

	UFUNCTION(BlueprintCallable, Category="Profiling | Primitives")
	static void FinalizePrimitiveCaptureCsv(const FString& InFileName);

	UFUNCTION(BlueprintCallable, Category="Profiling | Primitives")
	static void PrintPrimitiveCaptureToCsv(TMap<FString, float> InCapture, const FString& InFileName, const FString& OptionalCaptureName = TEXT(""));

	UFUNCTION(BlueprintCallable, Category="Profiling | Primitives")
	static void PrintPrimitiveCaptureToLog(TMap<FString, float> InCapture);

};

UCLASS(meta=(ScriptName="VideoCaptureProfiling"))
class UVideoCaptureProfilingHelper : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Profiling | Video")
	static void StartCapturingVideo(const FString& Filename, float MaxDuration = 0.000000f);

	UFUNCTION(BlueprintCallable, Category="Profiling | Video")
	static void StopCapturingVideo();

};

