// Copyright Epic Games, Inc. All Rights Reserved.

#include "DateTime/FortDateTimeLibrary.h"

FDateTime UFortDateTimeLibrary::GetMcpRelativeUtcNow(const AFortPlayerController* FortPC)
{
	return FDateTime();
}

FTimespan UFortDateTimeLibrary::GetTimeSinceAthenaSeasonStart(const AFortPlayerController* FortPC)
{
	return FTimespan();
}

FTimespan UFortDateTimeLibrary::GetTimeSinceEventTagStart(const AFortPlayerController* FortPC, const FString& EventTag)
{
	return FTimespan();
}

FText UFortDateTimeLibrary::GetTimespanAsText(const FTimespan& Timespan, bool bShowHoursWhenZero, bool bShowSeconds, ETimespanAsTextFormat FormatType, ETimespanUnitDisplayFormat UnitDisplayType)
{
	return FText();
}

FTimespan UFortDateTimeLibrary::GetTimeTillEventTagEnds(const AFortPlayerController* FortPC, const FString& EventTag)
{
	return FTimespan();
}
