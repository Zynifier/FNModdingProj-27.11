// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Core/QualitativePerfMetrics.h"
#include "QualitativePerfMetricSettings.generated.h"

USTRUCT()
struct FPerPlatformMetricProfiles
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleAnywhere, Category="PerPlatformMetricProfiles")
	TMap<FString, FString> DeviceProfileToMetricProfileMapping;

};

USTRUCT()
struct FQualitativePerfMetricProfile
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Config, Category="QualitativePerfMetricProfile")
	FName ProfileName;

	UPROPERTY(EditAnywhere, Config, Category="QualitativePerfMetricProfile")
	FName ParentProfileName;

	UPROPERTY(EditAnywhere, Config, Category="QualitativePerfMetricProfile", meta=(TitleProperty="{Metric}"))
	TArray<FQualitativePerfMetricScale> QualityScales;

	UPROPERTY(EditAnywhere, Config, Category="QualitativePerfMetricProfile", meta=(TitleProperty="{Metric}"))
	TArray<FQualitativePerfMetricScale> HealthScales;

};

UCLASS(Config=Game, DefaultConfig, EditInlineNew)
class UQualitativePerfMetricSettings : public UObject
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Config, Category="QualitativePerfMetricSettings")
	FString SemanticVersion;

	UPROPERTY(EditAnywhere, Config, Category="QualitativePerfMetricSettings", meta=(TitleProperty="{ProfileName} : {ParentProfileName}"))
	TArray<FQualitativePerfMetricProfile> Profiles;

#if WITH_EDITORONLY_DATA
	UPROPERTY(Transient)
	bool bLoadPerPlatformProfiles;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(VisibleAnywhere, Transient, Category="QualitativePerfMetricSettings", meta=(EditCondition="bLoadPerPlatformProfiles"))
	TMap<FString, FPerPlatformMetricProfiles> PerPlatformProfiles;
#endif

};

