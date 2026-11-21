// Copyright Epic Games, Inc. All Rights Reserved.

#include "Creative/FortCreativeRoundSettings.h"

void AFortCreativeRoundSettings::ClearResourcesGivenPerRound()
{
}

void AFortCreativeRoundSettings::ClearResourcesGivenToWinnersPerRound()
{
}

void AFortCreativeRoundSettings::EndRound(AFortPlayerController* InstigatorPC)
{
}

int32 AFortCreativeRoundSettings::GetResourceGivenPerRound(const EFortResourceType::Type InResourceType) const
{
	return int32();
}

int32 AFortCreativeRoundSettings::GetResourceGivenToWinnersPerRound(const EFortResourceType::Type InResourceType) const
{
	return int32();
}

int32 AFortCreativeRoundSettings::GetRoundIndex_Implementation() const
{
	return int32();
}

bool AFortCreativeRoundSettings::IsActive() const
{
	return false;
}

void AFortCreativeRoundSettings::SetResourceGivenPerRound(const EFortResourceType::Type InResourceType, const int32 Amount)
{
}

void AFortCreativeRoundSettings::SetResourceGivenToWinnersPerRound(const EFortResourceType::Type InResourceType, const int32 Amount)
{
}
