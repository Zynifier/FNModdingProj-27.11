// Copyright Epic Games, Inc. All Rights Reserved.

#include "Athena/ControllerComponents/FortControllerComponent_MapDiscoverability.h"
#include "Net/UnrealNetwork.h"

void UFortControllerComponent_MapDiscoverability::CancelTeleportToAllLocations()
{
}

void UFortControllerComponent_MapDiscoverability::DiscoverAllAreas()
{
}

void UFortControllerComponent_MapDiscoverability::DiscoverAllLandmarks()
{
}

void UFortControllerComponent_MapDiscoverability::DiscoverAllPois()
{
}

void UFortControllerComponent_MapDiscoverability::EventsReadyStub(const TArray<FString>& Events)
{
}

const FText& UFortControllerComponent_MapDiscoverability::GetMapTextForLocation(const FGameplayTag& Location) const
{
	static FText Dummy;
	return Dummy;
}

UMaterialInstanceDynamic* UFortControllerComponent_MapDiscoverability::GetStencilMID() const
{
	return nullptr;
}

void UFortControllerComponent_MapDiscoverability::PlaylistLoadedStub(FName PlaylistName, const FGameplayTagContainer& PlaylistContextTags)
{
}

void UFortControllerComponent_MapDiscoverability::SetDiscoverStatusByTag(const FString& Tag, bool bDiscovered)
{
}

void UFortControllerComponent_MapDiscoverability::SetSuppressDiscoveryEvents(bool bSuppress)
{
}

void UFortControllerComponent_MapDiscoverability::TeleportToAllLocations(float DelayBetween)
{
}

void UFortControllerComponent_MapDiscoverability::UndiscoverAllAreas()
{
}

void UFortControllerComponent_MapDiscoverability::UndiscoverAllLandmarks()
{
}

void UFortControllerComponent_MapDiscoverability::UndiscoverAllPois()
{
}

void UFortControllerComponent_MapDiscoverability::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UFortControllerComponent_MapDiscoverability, DiscoveredData);
}
