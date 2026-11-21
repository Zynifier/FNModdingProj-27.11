// Copyright Epic Games, Inc. All Rights Reserved.

#include "FortAthenaLivingWorldVolume.h"

void AFortAthenaLivingWorldVolume::DisablePointProvider()
{
}

bool AFortAthenaLivingWorldVolume::DoesStartEnabled() const
{
	return false;
}

void AFortAthenaLivingWorldVolume::EnablePointProvider()
{
}

bool AFortAthenaLivingWorldVolume::IsPointProviderEnabled() const
{
	return false;
}

void AFortAthenaLivingWorldVolume::OnCurrentPlaylistLoaded(FName PlaylistName, const FGameplayTagContainer& PlaylistContextTags)
{
}

void AFortAthenaLivingWorldVolume::OnNavigationFinishedGeneration(ANavigationData* NavData)
{
}

void AFortAthenaLivingWorldVolume::OnWorldFinishedInitialization(const FGameplayTagContainer& ContextTags)
{
}

void AFortAthenaLivingWorldVolume::ResetSpawnRotation()
{
}

void AFortAthenaLivingWorldVolume::RunEQS()
{
}

void AFortAthenaLivingWorldVolume::SetEQSQuery(UEnvQuery* Query)
{
}

void AFortAthenaLivingWorldVolume::SetEQSQueryConfigParam(const FName ParameterName, float Value)
{
}

void AFortAthenaLivingWorldVolume::SetFiltersTags(const FGameplayTagContainer& TagContainer)
{
}

void AFortAthenaLivingWorldVolume::SetSpawnRotation(const FRotator& Rotation)
{
}
