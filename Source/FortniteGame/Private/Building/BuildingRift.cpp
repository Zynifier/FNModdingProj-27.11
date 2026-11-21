// Copyright Epic Games, Inc. All Rights Reserved.

#include "Building/BuildingRift.h"
#include "Net/UnrealNetwork.h"

void ABuildingRift::BroadcastRiftSpawningAI_Implementation()
{
}

void ABuildingRift::DestroyNearbyBuildings(bool bDestroyOnlyPlayerBuiltBuildings)
{
}

void ABuildingRift::NotifyAIPawnSpawned_Implementation(AFortAIPawn* SpawnedAI, const FVector& SpawnSlotLocation)
{
}

void ABuildingRift::OnGameDifficultyChanged()
{
}

void ABuildingRift::OnRep_CosmeticState()
{
}

void ABuildingRift::OnRep_RiftIsActive()
{
}

void ABuildingRift::OnRep_RiftIsVisible()
{
}

void ABuildingRift::SetNewEQSData(UEnvQuery* NewEnvironmentQuery, TArray<FEnvNamedValue> NewQueryParams)
{
}

void ABuildingRift::StartEnvironmentQuery()
{
}

void ABuildingRift::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(ABuildingRift, bRiftIsVisible);
	DOREPLIFETIME(ABuildingRift, bRiftIsActive);
	DOREPLIFETIME(ABuildingRift, CosmeticState);
}
