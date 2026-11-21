// Copyright Epic Games, Inc. All Rights Reserved.

#include "Athena/MeshNetworkEvents/FortMeshNetworkEventsSubsystem.h"

bool UFortMeshNetworkEventsSubsystem::GetActiveMeshNetworkEvent(FMeshNetworkEventStateData& OutEventData, const FName& EventName, const FGameplayTagContainer& EventFilters) const
{
	return false;
}

void UFortMeshNetworkEventsSubsystem::GetActiveMeshNetworkEvents(TArray<FMeshNetworkEventStateData>& ActiveMeshNetworkEvents) const
{
}

EMeshNetworkNodeType UFortMeshNetworkEventsSubsystem::GetMeshNetworkNodeType() const
{
	return EMeshNetworkNodeType();
}

bool UFortMeshNetworkEventsSubsystem::IsMeshNetworkEventActive(const FName& EventName, const FGameplayTagContainer& Filters) const
{
	return false;
}
