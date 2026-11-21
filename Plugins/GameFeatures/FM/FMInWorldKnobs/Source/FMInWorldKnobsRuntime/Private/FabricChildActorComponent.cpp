// Copyright Epic Games, Inc. All Rights Reserved.

#include "FabricChildActorComponent.h"

UFMDeviceCableModulatorPortComponent* UFabricChildActorComponent::CreateModulatorPortIfNeeded()
{
	return nullptr;
}

AFabricButtonBase* UFabricChildActorComponent::GetChildActorAsFabricButton() const
{
	return nullptr;
}

TScriptInterface<IFabricInteractable> UFabricChildActorComponent::GetChildActorAsFabricInteractable() const
{
	return TScriptInterface<IFabricInteractable>();
}

AFMInWorldKnobActorBase* UFabricChildActorComponent::GetChildActorAsInWorldKnobActorBase() const
{
	return nullptr;
}

FString UFabricChildActorComponent::GetKnobOptionKey() const
{
	return FString();
}

void UFabricChildActorComponent::OnModulatorPortConnected(UFMDeviceCablePortComponent* ConnectedPort)
{
}

void UFabricChildActorComponent::OnModulatorPortDisconnected(UFMDeviceCablePortComponent* DisconnectedPort)
{
}
