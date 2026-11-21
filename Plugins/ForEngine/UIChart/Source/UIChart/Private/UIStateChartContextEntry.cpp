// Copyright Epic Games, Inc. All Rights Reserved.

#include "UIStateChartContextEntry.h"

bool UUIStateChartContextEntry::GetCommonValueAsBool() const
{
	return false;
}

float UUIStateChartContextEntry::GetCommonValueAsFloat() const
{
	return float();
}

int32 UUIStateChartContextEntry::GetCommonValueAsInt() const
{
	return int32();
}

FString UUIStateChartContextEntry::GetCommonValueAsString() const
{
	return FString();
}

bool UUIStateChartContextEntry::GetPlayerValueAsBool(const ULocalPlayer* InLocalPlayer) const
{
	return false;
}

float UUIStateChartContextEntry::GetPlayerValueAsFloat(const ULocalPlayer* InLocalPlayer) const
{
	return float();
}

int32 UUIStateChartContextEntry::GetPlayerValueAsInt(const ULocalPlayer* InLocalPlayer) const
{
	return int32();
}

FString UUIStateChartContextEntry::GetPlayerValueAsString(const ULocalPlayer* InLocalPlayer) const
{
	return FString();
}

bool UUIStateChartContextEntry::IsEmptyForPlayer(ULocalPlayer* InLocalPlayer) const
{
	return false;
}
