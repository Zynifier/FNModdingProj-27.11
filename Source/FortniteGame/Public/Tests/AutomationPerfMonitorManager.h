// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "AutomationPerfMonitorManager.generated.h"

class UAutomationPerfMonitorManager;

UCLASS(Config=Game, BlueprintType)
class UAutomationPerfMonitorManager : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="FunctionalTesting")
	static UAutomationPerfMonitorManager* GetPerfMonitorInstance();

	UFUNCTION(BlueprintCallable, Category="FunctionalTesting")
	float GetStatAverage(const FString& StatName);

	UFUNCTION(BlueprintCallable, Category="FunctionalTesting")
	bool IsRecordingFTestPerf();

	UFUNCTION(BlueprintCallable, Category="FunctionalTesting")
	void StartRecordingFTestPerf(TArray<FString> StatsToRecord);

	UFUNCTION(BlueprintCallable, Category="FunctionalTesting")
	void StopRecordingFTestPerf();

	UPROPERTY()
	TArray<FString> DesiredStats;

	UPROPERTY()
	bool bRecording;

	UPROPERTY()
	float TimeSinceLastRecord;

	UPROPERTY()
	int32 LastGoodFrame;

};

