// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Misc/DateTime.h"
#include "Misc/Timespan.h"
#include "FortDateTimeLibrary.generated.h"

class AFortPlayerController;
enum class ETimespanAsTextFormat : uint8;
enum class ETimespanUnitDisplayFormat : uint8;

UENUM(BlueprintType)
enum class ETimespanAsTextFormat : uint8
{
	DaysHoursMinutesSeconds = 0,
	Colons = 1,
	//Will show milliseconds if we're less than 1 hour.

	ColonsWithMilliseconds = 2,
	// Shows only the largest unit (e.g., 2 days -> 1 day -> 23 hours -> 1 hour -> 59 minutes, etc...)

	Approximate = 3,
	ApproximateWithWeeks = 4,
	// largest unit is weeks

	ApproximateWithMonths = 5,
	// largest unit is months

	ApproximateWithYears = 6,
};

UENUM(BlueprintType)
enum class ETimespanUnitDisplayFormat : uint8
{
	Full = 0,
	// e.g. "Days" "Months"

	Abbreviated = 1,
};

UCLASS(MinimalAPI)
class UFortDateTimeLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="FortDateTime")
	static FDateTime GetMcpRelativeUtcNow(const AFortPlayerController* FortPC);

	UFUNCTION(BlueprintPure, Category="FortDateTime")
	static FTimespan GetTimeSinceAthenaSeasonStart(const AFortPlayerController* FortPC);

	UFUNCTION(BlueprintPure, Category="FortDateTime")
	static FTimespan GetTimeSinceEventTagStart(const AFortPlayerController* FortPC, const FString& EventTag);

	UFUNCTION(BlueprintPure, Category="TimeOfDay")
	static FText GetTimespanAsText(const FTimespan& Timespan, bool bShowHoursWhenZero = true, bool bShowSeconds = false, ETimespanAsTextFormat FormatType = ETimespanAsTextFormat::DaysHoursMinutesSeconds, ETimespanUnitDisplayFormat UnitDisplayType = ETimespanUnitDisplayFormat::Full);

	UFUNCTION(BlueprintPure, Category="FortDateTime")
	static FTimespan GetTimeTillEventTagEnds(const AFortPlayerController* FortPC, const FString& EventTag);

};

