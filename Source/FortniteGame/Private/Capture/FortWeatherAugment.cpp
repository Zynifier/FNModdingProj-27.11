// Copyright Epic Games, Inc. All Rights Reserved.

#include "Capture/FortWeatherAugment.h"

const FGameplayTagContainer& AFortWeatherAugment::GetWeatherTags() const
{
	static FGameplayTagContainer Dummy;
	return Dummy;
}
