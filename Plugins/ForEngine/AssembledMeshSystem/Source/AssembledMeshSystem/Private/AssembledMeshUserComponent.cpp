// Copyright Epic Games, Inc. All Rights Reserved.

#include "AssembledMeshUserComponent.h"
#include "Net/UnrealNetwork.h"

void UAssembledMeshUserComponent::CustomizationCompleted(const int32 PartIndex)
{
}

void UAssembledMeshUserComponent::GatherAndAssignAssembledMeshParts()
{
}

USkeletalMeshComponent* UAssembledMeshUserComponent::GetAttachToComponent_Implementation()
{
	return nullptr;
}

UAssembledMeshSchema* UAssembledMeshUserComponent::GetMeshPart() const
{
	return nullptr;
}

void UAssembledMeshUserComponent::OnRep_MeshParts()
{
}

void UAssembledMeshUserComponent::SetMeshPart(UAssembledMeshSchema* InMeshPart)
{
}

void UAssembledMeshUserComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UAssembledMeshUserComponent, MeshParts);
}
