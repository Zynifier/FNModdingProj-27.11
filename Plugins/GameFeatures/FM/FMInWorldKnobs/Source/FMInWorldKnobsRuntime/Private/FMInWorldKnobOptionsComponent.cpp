// Copyright Epic Games, Inc. All Rights Reserved.

#include "FMInWorldKnobOptionsComponent.h"
#include "Net/UnrealNetwork.h"

bool UFMInWorldKnobOptionsComponent::AreAllKnobsLoadedForNotify() const
{
	return false;
}

bool UFMInWorldKnobOptionsComponent::CanMakeUserOptionChanges() const
{
	return false;
}

void UFMInWorldKnobOptionsComponent::OnAnyOptionUpdated()
{
}

void UFMInWorldKnobOptionsComponent::OnInWorldKnobRuntimeOptionChanged(const FString& Value, UPlaylistUserOptionBase* Option)
{
}

void UFMInWorldKnobOptionsComponent::OnInWorldKnobSerializedOptionChanged(const FString& Value, UPlaylistUserOptionBase* Option, APlayerController* PlayerController)
{
}

void UFMInWorldKnobOptionsComponent::OnOptionsLoaded()
{
}

void UFMInWorldKnobOptionsComponent::OnRep_ReplicatedFabricInteractableObjects()
{
}

void UFMInWorldKnobOptionsComponent::OnRep_ReplicatedInWorldKnobInterfaceObjects()
{
}

void UFMInWorldKnobOptionsComponent::OnRep_ReplicatedModulatorPorts()
{
}

void UFMInWorldKnobOptionsComponent::OnSaveOverridesChanged()
{
}

bool UFMInWorldKnobOptionsComponent::OwnsInWorldKnobObject(UObject* InWorldKnobObject) const
{
	return false;
}

void UFMInWorldKnobOptionsComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UFMInWorldKnobOptionsComponent, ReplicatedInWorldKnobInterfaceObjects);
	DOREPLIFETIME(UFMInWorldKnobOptionsComponent, ReplicatedFabricInteractableObjects);
	DOREPLIFETIME(UFMInWorldKnobOptionsComponent, ReplicatedModulatorPorts);
}
