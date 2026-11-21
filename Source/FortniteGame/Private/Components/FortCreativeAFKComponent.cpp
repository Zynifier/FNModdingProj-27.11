// Copyright Epic Games, Inc. All Rights Reserved.

#include "Components/FortCreativeAFKComponent.h"
#include "Net/UnrealNetwork.h"

void UFortCreativeAFKComponent::DisableAFKTracking(AFortPlayerController* InstigatorPC, EFortMinigameEnd EndMethod, EFortMinigameState NextState)
{
}

void UFortCreativeAFKComponent::EnableAFKTracking()
{
}

void UFortCreativeAFKComponent::OnPlayerInteracted()
{
}

void UFortCreativeAFKComponent::OnPlayerSpawnedBuildingActor(AFortPlayerController* Spawner, ABuildingActor* SpawnedBuilding)
{
}

void UFortCreativeAFKComponent::OnRep_LastInputChangeTimestamp()
{
}

void UFortCreativeAFKComponent::ServerRecordInputChange_Implementation()
{
}

void UFortCreativeAFKComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UFortCreativeAFKComponent, LastInputChangeTimestamp);
}
