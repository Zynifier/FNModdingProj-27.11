// Copyright Epic Games, Inc. All Rights Reserved.

#include "ChallengeBundles/FortChallengeBundleScheduleDefinition.h"

bool UFortChallengeBundleScheduleDefinition::DoesChallengeBundleScheduleExpire() const
{
	return false;
}

TArray<UFortChallengeBundleItemDefinition*> UFortChallengeBundleScheduleDefinition::GetBundleDefinitions() const
{
	return TArray<UFortChallengeBundleItemDefinition*>();
}

FString UFortChallengeBundleScheduleDefinition::GetCalendarEventName() const
{
	return FString();
}

FString UFortChallengeBundleScheduleDefinition::GetEventName(bool bGetExpirationEvent) const
{
	return FString();
}

int32 UFortChallengeBundleScheduleDefinition::GetNumBundles() const
{
	return int32();
}

int32 UFortChallengeBundleScheduleDefinition::GetSortPriority() const
{
	return int32();
}
