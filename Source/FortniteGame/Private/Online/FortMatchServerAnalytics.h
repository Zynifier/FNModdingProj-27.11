// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Online/FortMatchAnalytics.h"
#include "FortMatchServerAnalytics.generated.h"

USTRUCT()
struct FFortHttpRequestCompletedAnalyticsFilter
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString UrlSubstring;

	UPROPERTY()
	TArray<FString> ErrorCodes;

	UPROPERTY()
	TArray<int32> StatusCodes;

};

UCLASS(Config=Game)
class UFortMatchServerAnalytics : public UFortMatchAnalytics
{
	GENERATED_BODY()

protected:
	UPROPERTY(Config)
	float PlayersNotCompletingPhasePercentage;

	UPROPERTY(Config)
	float PlayersDisconnectingUnexpectedlyPercentage;

	UPROPERTY(Config)
	double MatchStartThreshold;

	UPROPERTY(Config)
	bool bHttpRequestCompletedDelegateEnabled;

	UPROPERTY(Config)
	TArray<FFortHttpRequestCompletedAnalyticsFilter> HttpRequestCompletedFilters;

};

