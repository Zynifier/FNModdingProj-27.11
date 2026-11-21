// Copyright Epic Games, Inc. All Rights Reserved.

#include "DagwoodNetworkPhysics.h"
#include "Net/UnrealNetwork.h"

FFortDagwoodCmd UDagwoodNetworkPhysicsComponent::GetPendingInputCmd() const
{
	return FFortDagwoodCmd();
}

FDagwoodInPersistent UDagwoodNetworkPhysicsComponent::GetState_GT() const
{
	return FDagwoodInPersistent();
}

FDagwoodState_PT UDagwoodNetworkPhysicsComponent::GetState_PT() const
{
	return FDagwoodState_PT();
}

void UDagwoodNetworkPhysicsComponent::SetPendingInputCmd(const FFortDagwoodCmd& In)
{
}

void UDagwoodNetworkPhysicsComponent::SetState_GT(const FDagwoodInPersistent& In)
{
}

void UDagwoodNetworkPhysicsComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UDagwoodNetworkPhysicsComponent, NetworkPhysicsState);
	DOREPLIFETIME(UDagwoodNetworkPhysicsComponent, ReplicatedManagedState);
}
