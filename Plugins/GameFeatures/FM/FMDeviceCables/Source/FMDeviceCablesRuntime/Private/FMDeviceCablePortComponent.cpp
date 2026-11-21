// Copyright Epic Games, Inc. All Rights Reserved.

#include "FMDeviceCablePortComponent.h"
#include "Net/UnrealNetwork.h"

void UFMDeviceCablePortComponent::EndConnectionWithPort(UFMDeviceCablePortComponent* OtherPort)
{
}

EDeviceCablePortAnimationSyncType UFMDeviceCablePortComponent::GetAnimationSyncType() const
{
	return EDeviceCablePortAnimationSyncType();
}

const FFMDeviceCableArtifact& UFMDeviceCablePortComponent::GetCachedArtifact() const
{
	static FFMDeviceCableArtifact Dummy;
	return Dummy;
}

const TArray<UFMDeviceCablePortComponent*>& UFMDeviceCablePortComponent::GetConnectedPorts() const
{
	static TArray<UFMDeviceCablePortComponent*> Dummy;
	return Dummy;
}

const TArray<UFMDeviceCableConnectionBase*>& UFMDeviceCablePortComponent::GetConnections() const
{
	static TArray<UFMDeviceCableConnectionBase*> Dummy;
	return Dummy;
}

AFMDeviceCable* UFMDeviceCablePortComponent::GetConstantCable()
{
	return nullptr;
}

UFMDeviceCableAnimatorBase* UFMDeviceCablePortComponent::GetDeviceCableAnimator()
{
	return nullptr;
}

FGuid UFMDeviceCablePortComponent::GetGuid()
{
	return FGuid();
}

bool UFMDeviceCablePortComponent::GetIsPlayerPort() const
{
	return false;
}

bool UFMDeviceCablePortComponent::GetIsTerminalPort(EDeviceCablePortFlowType FlowType) const
{
	return false;
}

TArray<UFMDeviceCablePortComponent*> UFMDeviceCablePortComponent::GetNextPortsInConnections() const
{
	return TArray<UFMDeviceCablePortComponent*>();
}

const TArray<UFMDeviceCablePortComponent*>& UFMDeviceCablePortComponent::GetOtherPortsOnActor() const
{
	static TArray<UFMDeviceCablePortComponent*> Dummy;
	return Dummy;
}

EDeviceCableActivatedState UFMDeviceCablePortComponent::GetPortActivatedState() const
{
	return EDeviceCableActivatedState();
}

EDeviceCablePortDataType UFMDeviceCablePortComponent::GetPortDataType() const
{
	return EDeviceCablePortDataType();
}

EDeviceCablePortFlowType UFMDeviceCablePortComponent::GetPortFlowType() const
{
	return EDeviceCablePortFlowType();
}

EDeviceCablePortSelectableState UFMDeviceCablePortComponent::GetPortSelectableState() const
{
	return EDeviceCablePortSelectableState();
}

TArray<UFMDeviceCablePortComponent*> UFMDeviceCablePortComponent::GetPreviousPortsInConnections() const
{
	return TArray<UFMDeviceCablePortComponent*>();
}

bool UFMDeviceCablePortComponent::IsConnected() const
{
	return false;
}

bool UFMDeviceCablePortComponent::IsConnectedToPort(UFMDeviceCablePortComponent* Port) const
{
	return false;
}

bool UFMDeviceCablePortComponent::MatchesPortConnectionType(UFMDeviceCablePortComponent* OtherPort) const
{
	return false;
}

void UFMDeviceCablePortComponent::OnPlayerControllerPortConnected(const TArray<UFMDeviceCablePortComponent*>& ControllerPorts)
{
}

void UFMDeviceCablePortComponent::OnPlayerControllerPortDisconnected()
{
}

void UFMDeviceCablePortComponent::OnRep_ConstantCable()
{
}

void UFMDeviceCablePortComponent::OnRep_DeviceCableManager()
{
}

void UFMDeviceCablePortComponent::OnRep_ServerConnectedPorts()
{
}

void UFMDeviceCablePortComponent::OnRep_ServerPortActivatedState()
{
}

void UFMDeviceCablePortComponent::OpenConnectionToPort(UFMDeviceCablePortComponent* OtherPort)
{
}

EPortSelectStatus UFMDeviceCablePortComponent::Select(UFMDeviceCablePortComponent* PlayerSelectionPort, TArray<FPortUpdateInfo>& OutPortUpdates)
{
	return EPortSelectStatus();
}

EPortSelectStatus UFMDeviceCablePortComponent::SelectWithStaticOutputInteraction(UFMDeviceCablePortComponent* PlayerSelectionPort, TArray<FPortUpdateInfo>& OutPortUpdates)
{
	return EPortSelectStatus();
}

void UFMDeviceCablePortComponent::SetCachedArtifact(const FFMDeviceCableArtifact& InCachedArtifact)
{
}

void UFMDeviceCablePortComponent::SetDeviceCableAnimator(UFMDeviceCableAnimatorBase* InAnimator)
{
}

void UFMDeviceCablePortComponent::SetPortActivatedState(EDeviceCableActivatedState NewActivatedState)
{
}

void UFMDeviceCablePortComponent::SetPortConnectionsDirty()
{
}

void UFMDeviceCablePortComponent::SetPortSelectableState(EDeviceCablePortSelectableState NewSelectableState)
{
}

void UFMDeviceCablePortComponent::SetPortVisibility(bool bPortVisible)
{
}

void UFMDeviceCablePortComponent::UpdateStaticMesh()
{
}

void UFMDeviceCablePortComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UFMDeviceCablePortComponent, bIsOnPreviewBuildingActor);
	DOREPLIFETIME(UFMDeviceCablePortComponent, ServerConnectedPorts);
	DOREPLIFETIME(UFMDeviceCablePortComponent, ConstantCable);
	DOREPLIFETIME(UFMDeviceCablePortComponent, DeviceCableManager);
	DOREPLIFETIME(UFMDeviceCablePortComponent, ServerPortActivatedState);
	DOREPLIFETIME(UFMDeviceCablePortComponent, PortSelectableState);
}
