// Copyright Epic Games, Inc. All Rights Reserved.

#include "FortEventTrackerModule.h"

UFortEventTrackerModule::UFortEventTrackerModule(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

const UFortEventScreenData* UFortEventTrackerModule::GetEventScreenData() const
{
	return nullptr;
}

bool UFortEventTrackerModule_PremiumUpsell::IsPremiumTrackOwned() const
{
	return false;
}

bool UFortEventTrackerModule_RewardDetails::IsPremiumTrackOwned() const
{
	return false;
}
