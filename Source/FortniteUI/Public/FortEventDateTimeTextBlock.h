// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonTextBlock.h"
#include "Misc/DateTime.h"
#include "Misc/Timespan.h"
#include "FortEventDateTimeTextBlock.generated.h"

UENUM()
enum DateFormat
{
	CountdownTextual = 0,
	CountdownNumeric = 1,
	CountdownNumUnder12Hours = 2,
	Date = 3,
	// Only used for short duration timers that are calendar independent (and thus should react to time dilation)

	CountdownNumericDilatable = 4,
};

UCLASS(BlueprintType, PrioritizeCategories=("Content"))
class UFortEventDateTimeTextBlock : public UCommonTextBlock
{
	GENERATED_BODY()

public:
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnCurrentTimeTextBlockUpdated, const double, Seconds);

public:
	UFUNCTION(BlueprintPure, Category="DateTime Text Block")
	FDateTime GetDateTime() const;

	UFUNCTION(BlueprintCallable, Category="DateTime Text Block")
	void SetCountDownCompletionText(const FText InCompletionText);

	UFUNCTION(BlueprintCallable, Category="DateTime Text Block")
	void SetDateTimeValue(const FDateTime InDateTime, DateFormat InFormatStyle = CountdownNumeric, float InRefreshDelay = 1.000000f);

	UFUNCTION(BlueprintCallable, Category="DateTime Text Block")
	void SetTimespanValue(const FTimespan InTimespan, DateFormat InFormatStyle = CountdownNumeric);

};

