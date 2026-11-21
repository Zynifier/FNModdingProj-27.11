// Copyright Epic Games, Inc. All Rights Reserved.

#include "Render/EntityActorStaticMeshRenderComponent.h"
#include "Net/UnrealNetwork.h"

void UEntityActorStaticMeshRenderComponent::OnRep_EnableCollision()
{
}

void UEntityActorStaticMeshRenderComponent::OnRep_MaxDrawDistance()
{
}

void UEntityActorStaticMeshRenderComponent::OnRep_MeshMaterials()
{
}

void UEntityActorStaticMeshRenderComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UEntityActorStaticMeshRenderComponent, ShadowVar_MeshMaterials);
	DOREPLIFETIME(UEntityActorStaticMeshRenderComponent, ShadowVar_EnableCollision);
	DOREPLIFETIME(UEntityActorStaticMeshRenderComponent, ShadowVar_MaxDrawDistance);
}
