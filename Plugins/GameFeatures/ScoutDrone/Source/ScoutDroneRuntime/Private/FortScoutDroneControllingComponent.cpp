// Copyright Epic Games, Inc. All Rights Reserved.

#include "FortScoutDroneControllingComponent.h"
#include "Net/UnrealNetwork.h"

AFortScoutDrone* UFortScoutDroneControllingComponent::GetControlledDrone() const
{
	return nullptr;
}

void UFortScoutDroneControllingComponent::OnControlledDroneDestroyed(AActor* InControlledDrone)
{
}

void UFortScoutDroneControllingComponent::OnOwningPlayerStartedDBNO()
{
}

void UFortScoutDroneControllingComponent::OnPlayerInterruptionTagsChanged(const FGameplayTag Tag, int32 NewCount)
{
}

void UFortScoutDroneControllingComponent::OnRep_ControlledDrone()
{
}

void UFortScoutDroneControllingComponent::OnRep_CurrentDestructionData()
{
}

void UFortScoutDroneControllingComponent::OnWeaponEquipped(AFortWeapon* NewWeapon, AFortWeapon* PrevWeapon)
{
}

void UFortScoutDroneControllingComponent::ServerRequestDroneDismissal_Implementation()
{
}

void UFortScoutDroneControllingComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UFortScoutDroneControllingComponent, ControlledDrone);
	DOREPLIFETIME(UFortScoutDroneControllingComponent, CurrentDestructionData);
}
