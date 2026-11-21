// Copyright Epic Games, Inc. All Rights Reserved.

#include "MeshNetworkComponent.h"

EMeshNetworkNodeType UMeshNetworkComponent::GetMeshNetworkNodeType() const
{
	return EMeshNetworkNodeType();
}

bool UMeshNetworkComponent::IsConnectedToMeshRoot() const
{
	return false;
}
