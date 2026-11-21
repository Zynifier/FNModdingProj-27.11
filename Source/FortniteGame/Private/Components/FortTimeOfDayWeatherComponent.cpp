// Copyright Epic Games, Inc. All Rights Reserved.

#include "Components/FortTimeOfDayWeatherComponent.h"
#include "Net/UnrealNetwork.h"

float UFortTimeOfDayWeatherComponent::GetBlendTimePercentage() const
{
	return float();
}

int32 UFortTimeOfDayWeatherComponent::GetCurrentWeatherEventIndex() const
{
	return int32();
}

float UFortTimeOfDayWeatherComponent::GetCurrentWeatherIntensity() const
{
	return float();
}

FVector UFortTimeOfDayWeatherComponent::GetCurrentWindDirection() const
{
	return FVector();
}

float UFortTimeOfDayWeatherComponent::GetCurrentWindStrength() const
{
	return float();
}

EGlobalWeatherState UFortTimeOfDayWeatherComponent::GetWeatherState() const
{
	return EGlobalWeatherState();
}

bool UFortTimeOfDayWeatherComponent::IsWeatherEventActive() const
{
	return false;
}

void UFortTimeOfDayWeatherComponent::OnPlaylistLoaded(FName PlaylistName, const FGameplayTagContainer& PlaylistContextTags)
{
}

void UFortTimeOfDayWeatherComponent::OnRep_WeatherEventData()
{
}

void UFortTimeOfDayWeatherComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UFortTimeOfDayWeatherComponent, WeatherEventData);
}
