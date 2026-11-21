// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortFlowAnalytics_Internal.generated.h"

USTRUCT()
struct FFortFlowAnalyticsImpressionSection_Internal
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString ContentID;

	UPROPERTY()
	int32 Row;

	UPROPERTY()
	int32 Column;

};

USTRUCT()
struct FFortFlowAnalyticsImpressionData_Internal
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString SectionID;

	UPROPERTY()
	double SessionTimerOffset;

	UPROPERTY()
	double DurationActive;

	UPROPERTY()
	TArray<FFortFlowAnalyticsImpressionSection_Internal> SectionContents;

};

