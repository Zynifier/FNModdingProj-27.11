// Copyright Epic Games, Inc. All Rights Reserved.

#include "FMDeviceCableControllerComponent.h"
#include "Net/UnrealNetwork.h"

void UFMDeviceCableControllerComponent::DropCable()
{
}

bool UFMDeviceCableControllerComponent::IsCableConnectionValid(UFMDeviceCablePortComponent* OtherPort) const
{
	return false;
}

bool UFMDeviceCableControllerComponent::IsHoldingCable() const
{
	return false;
}

void UFMDeviceCableControllerComponent::OnCreativePlotLinkedVolumeChanged(AFortVolume* FortVolume)
{
}

void UFMDeviceCableControllerComponent::OnFortPawnChanged(AFortPawn* Pawn)
{
}

void UFMDeviceCableControllerComponent::OnNoFabricInteractablesHit()
{
}

void UFMDeviceCableControllerComponent::OnRep_ServerControllerPort()
{
}

void UFMDeviceCableControllerComponent::OnRep_ServerDeviceCableManager()
{
}

void UFMDeviceCableControllerComponent::OnWeaponEquipped(AFortWeapon* NewWeapon, AFortWeapon* PrevWeapon)
{
}

void UFMDeviceCableControllerComponent::SelectPort(UFMDeviceCablePortComponent* SelectedPort)
{
}

void UFMDeviceCableControllerComponent::ServerDisconnectController_Implementation()
{
}

void UFMDeviceCableControllerComponent::ServerPortActivatedStateChanged_Implementation(UFMDeviceCablePortComponent* Port, EDeviceCableActivatedState ActivatedState)
{
}

void UFMDeviceCableControllerComponent::ServerPortsUpdated_Implementation(const TArray<FPortUpdateInfo>& PortChangeInfos)
{
}

void UFMDeviceCableControllerComponent::ServerSelectPort_Implementation(UFMDeviceCablePortComponent* SelectedPort)
{
}

void UFMDeviceCableControllerComponent::ServerVolumeChanged_Implementation()
{
}

void UFMDeviceCableControllerComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UFMDeviceCableControllerComponent, ServerControllerPort);
	DOREPLIFETIME(UFMDeviceCableControllerComponent, ServerDeviceCableManager);
}
