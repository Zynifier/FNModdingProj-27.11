// Copyright Epic Games, Inc. All Rights Reserved.

#include "FMDeviceCableWildcardOrderingComponent.h"
#include "Net/UnrealNetwork.h"

void UFMDeviceCableWildcardOrderingComponent::OnInputPortConnected(UFMDeviceCablePortComponent* ConnectedPort)
{
}

void UFMDeviceCableWildcardOrderingComponent::OnInputPortDataTypeChanged(UFMDeviceCableWildcardPortComponent* WildcardPort, EDeviceCablePortDataType DataType)
{
}

void UFMDeviceCableWildcardOrderingComponent::OnInputPortDisconnected(UFMDeviceCablePortComponent* DisconnectedPort)
{
}

void UFMDeviceCableWildcardOrderingComponent::OnOutputPortConnected(UFMDeviceCablePortComponent* SourcePort, UFMDeviceCablePortComponent* ConnectedPort)
{
}

void UFMDeviceCableWildcardOrderingComponent::OnOutputPortDisconnected(UFMDeviceCablePortComponent* SourcePort, UFMDeviceCablePortComponent* DisconnectedPort)
{
}

void UFMDeviceCableWildcardOrderingComponent::OnOutputPortSlotSetFromSave(UFMDeviceCableWildcardPortComponent* WildcardPort, bool bHasConnections)
{
}

void UFMDeviceCableWildcardOrderingComponent::OnRep_ServerPortStates()
{
}

void UFMDeviceCableWildcardOrderingComponent::SetInputRoot(FVector RootLocation)
{
}

void UFMDeviceCableWildcardOrderingComponent::SetOutputPortsExpanded(bool bExpanded)
{
}

void UFMDeviceCableWildcardOrderingComponent::SetOutputRoot(FVector RootLocation)
{
}

void UFMDeviceCableWildcardOrderingComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UFMDeviceCableWildcardOrderingComponent, ServerPortStates);
}
