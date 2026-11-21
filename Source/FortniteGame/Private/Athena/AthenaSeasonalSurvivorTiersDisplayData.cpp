// Copyright Epic Games, Inc. All Rights Reserved.

#include "Athena/AthenaSeasonalSurvivorTiersDisplayData.h"

int32 UAthenaSeasonalSurvivorTiersDisplayData::GetMaxTier() const
{
	return int32();
}

FSurvivorPresigeData UAthenaSeasonalSurvivorTiersDisplayData::GetPrestigeData(const int32 PrestigeLevel) const
{
	return FSurvivorPresigeData();
}

const UAthenaSeasonalSurvivorTiersDisplayData* UAthenaSeasonalSurvivorTiersDisplayData::GetSurvivorTierDisplayData(UObject* WorldContextObject)
{
	return nullptr;
}
