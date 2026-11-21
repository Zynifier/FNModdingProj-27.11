// Copyright Epic Games, Inc. All Rights Reserved.

#include "Helpers/FortAthenaLivingWorldPointProvidersEnabler.h"

bool AFortAthenaLivingWorldPointProvidersEnabler::DoesStartEnabled() const
{
	return false;
}

void AFortAthenaLivingWorldPointProvidersEnabler::EvaluateAndEnablePointProviders()
{
}

const TArray<TScriptInterface<IFortAthenaLivingWorldPointProviderInterface>>& AFortAthenaLivingWorldPointProvidersEnabler::GetEnabledLinkedPointProviders() const
{
	static TArray<TScriptInterface<IFortAthenaLivingWorldPointProviderInterface>> Dummy;
	return Dummy;
}

const FGameplayTagContainer& AFortAthenaLivingWorldPointProvidersEnabler::GetEnablerTags() const
{
	static FGameplayTagContainer Dummy;
	return Dummy;
}

bool AFortAthenaLivingWorldPointProvidersEnabler::HasCompletedEvaluation() const
{
	return false;
}

void AFortAthenaLivingWorldPointProvidersEnabler::OnCurrentPlaylistLoaded(FName PlaylistName, const FGameplayTagContainer& PlaylistContextTags)
{
}

void AFortAthenaLivingWorldPointProvidersEnabler::RemoveClosestPointProvidersToPoint(const FVector& Point, const float MaximumDistance, const int32 PointsToDisable)
{
}
