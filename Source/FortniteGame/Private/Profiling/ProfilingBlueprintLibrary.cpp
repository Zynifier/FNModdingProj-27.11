// Copyright Epic Games, Inc. All Rights Reserved.

#include "Profiling/ProfilingBlueprintLibrary.h"

FCreativePerfCost UCreativeProfilingHelper::CaptureActorThermometerValue(AActor* InActor, EFortBudgetCategory Category)
{
	return FCreativePerfCost();
}

FCreativePerfCost UCreativeProfilingHelper::CaptureOverallThermometerValue(float InPrevCapture, float& OutComparison, EFortBudgetCategory Category)
{
	return FCreativePerfCost();
}

void UCreativeProfilingHelper::PrintThermometerCaptureToCsv(FCreativePerfCost InCapture, const FString& InFileName, const FString& OptionalCaptureName)
{
}

void UCreativeProfilingHelper::PrintThermometerCaptureToLog(FCreativePerfCost InCapture, const FString& CaptureName)
{
}

void UFrameStatsProfilingHelper::StartRecordingFrameStats(const FString& FPSChartLabel)
{
}

void UFrameStatsProfilingHelper::StopRecordingFrameStats(const FString& MapName)
{
}

TMap<FString, float> UMemoryStatsProfilingHelper::CaptureMemoryValues(TMap<FString, float> InPrevCapture, TMap<FString, float>& OutComparison, bool bConvertToMB)
{
	return TMap<FString, float>();
}

void UMemoryStatsProfilingHelper::FinalizeMemoryCaptureCsv(const FString& InFileName)
{
}

void UMemoryStatsProfilingHelper::PrintMemoryCaptureToCsv(TMap<FString, float> InCapture, const FString& InFileName, const FString& OptionalCaptureName)
{
}

void UMemoryStatsProfilingHelper::PrintMemoryCaptureToLog(TMap<FString, float> InCapture, bool bCaptureIsInMB)
{
}

TMap<FString, float> UPrimitiveStatsProfilingHelper::CapturePrimitiveValues(TMap<FString, float> InPrevCapture, TMap<FString, float>& OutComparison, TArray<FString> DesiredStats)
{
	return TMap<FString, float>();
}

void UPrimitiveStatsProfilingHelper::EnablePrimitiveStatsCapture()
{
}

void UPrimitiveStatsProfilingHelper::FinalizePrimitiveCaptureCsv(const FString& InFileName)
{
}

void UPrimitiveStatsProfilingHelper::PrintPrimitiveCaptureToCsv(TMap<FString, float> InCapture, const FString& InFileName, const FString& OptionalCaptureName)
{
}

void UPrimitiveStatsProfilingHelper::PrintPrimitiveCaptureToLog(TMap<FString, float> InCapture)
{
}

void UVideoCaptureProfilingHelper::StartCapturingVideo(const FString& Filename, float MaxDuration)
{
}

void UVideoCaptureProfilingHelper::StopCapturingVideo()
{
}
