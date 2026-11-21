// Copyright Epic Games, Inc. All Rights Reserved.

#include "Athena/AthenaTravelLogFormatting.h"

FText UAthenaTravelLogFormatting::FormatTravelLogEntry(UObject* WorldContextObject, const FAthenaTravelLogEntry& Entry)
{
	return FText();
}

bool UAthenaTravelLogFormatting::IsTravelLogTextDisplayEnabled()
{
	return false;
}

bool UAthenaTravelLogFormatting::ShouldDisplayText(const FAthenaTravelLogEntry& Entry)
{
	return false;
}
