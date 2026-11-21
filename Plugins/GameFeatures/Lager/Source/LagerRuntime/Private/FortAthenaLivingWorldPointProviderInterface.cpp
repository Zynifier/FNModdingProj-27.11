// Copyright Epic Games, Inc. All Rights Reserved.

#include "FortAthenaLivingWorldPointProviderInterface.h"

void IFortAthenaLivingWorldPointProviderInterface::DisablePointProvider()
{
}

void IFortAthenaLivingWorldPointProviderInterface::EnablePointProvider()
{
}

void IFortAthenaLivingWorldPointProviderInterface::GetFiltersTags(FGameplayTagContainer& FilterTags) const
{
}

FVector IFortAthenaLivingWorldPointProviderInterface::GetPointProviderLocation()
{
	return FVector();
}

float IFortAthenaLivingWorldPointProviderInterface::GetPointProviderMaxRadius()
{
	return float();
}
