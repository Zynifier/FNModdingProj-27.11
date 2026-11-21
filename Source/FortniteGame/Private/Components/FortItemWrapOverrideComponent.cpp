// Copyright Epic Games, Inc. All Rights Reserved.

#include "Components/FortItemWrapOverrideComponent.h"
#include "Net/UnrealNetwork.h"

void UFortItemWrapOverrideComponent::OnRep_SoftOverride()
{
}

void UFortItemWrapOverrideComponent::OnRep_VariantData()
{
}

UFortItemWrapOverrideComponent* UFortItemWrapOverrideComponent::OverrideWrapOnActor(AActor* ActorBase, const TSoftObjectPtr<UAthenaItemWrapDefinition>& Wrap, const TArray<FMcpVariantChannelInfo>& VariantData)
{
	return nullptr;
}

void UFortItemWrapOverrideComponent::RemoveWrapFromOwner()
{
}

void UFortItemWrapOverrideComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UFortItemWrapOverrideComponent, ReplicatedItemWrapOverride);
	DOREPLIFETIME(UFortItemWrapOverrideComponent, VariantInfo);
}
