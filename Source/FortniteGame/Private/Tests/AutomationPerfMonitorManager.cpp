// Copyright Epic Games, Inc. All Rights Reserved.

#include "Tests/AutomationPerfMonitorManager.h"

UAutomationPerfMonitorManager* UAutomationPerfMonitorManager::GetPerfMonitorInstance()
{
	return nullptr;
}

float UAutomationPerfMonitorManager::GetStatAverage(const FString& StatName)
{
	return float();
}

bool UAutomationPerfMonitorManager::IsRecordingFTestPerf()
{
	return false;
}

void UAutomationPerfMonitorManager::StartRecordingFTestPerf(TArray<FString> StatsToRecord)
{
}

void UAutomationPerfMonitorManager::StopRecordingFTestPerf()
{
}
