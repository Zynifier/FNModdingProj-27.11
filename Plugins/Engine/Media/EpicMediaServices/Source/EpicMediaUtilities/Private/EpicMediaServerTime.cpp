// Copyright Epic Games, Inc. All Rights Reserved.

#include "EpicMediaServerTime.h"

void AEpicMediaServerTime::ClientReportServerTime_Implementation(double requestUtcTime, double serverUtcTime)
{
}

bool AEpicMediaServerTime::GetTimeUtc(FDateTime& OutDateTime) const
{
	return false;
}

void AEpicMediaServerTime::ServerRequestServerTime_Implementation(double requestUtcTime)
{
}
