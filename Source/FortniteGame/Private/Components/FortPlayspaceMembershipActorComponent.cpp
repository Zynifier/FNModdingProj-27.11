// Copyright Epic Games, Inc. All Rights Reserved.

#include "Components/FortPlayspaceMembershipActorComponent.h"
#include "Net/UnrealNetwork.h"

UFortPlayspaceMembershipActorComponent::UFortPlayspaceMembershipActorComponent(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UFortPlayspaceMembershipActorComponent::AttemptToBindToPlayspace()
{
}

UFortPlayspaceMembershipActorComponent* UFortPlayspaceMembershipActorComponent::FindOrCreatePlayspaceMembershipActorComponentOnActor(const AActor* Owner)
{
	return nullptr;
}

UPlayspaceComponent* UFortPlayspaceMembershipActorComponent::FindOrCreatePlayspaceMembershipComponentAndReturnComponent(TSubclassOf<UPlayspaceComponent> ComponentClass, const AActor* Owner)
{
	return nullptr;
}

APlayspace* UFortPlayspaceMembershipActorComponent::GetBoundPlayspace() const
{
	return nullptr;
}

APlayspace* UFortPlayspaceMembershipActorComponent::GetBoundPlayspaceByClass(TSubclassOf<APlayspace> PlayspaceClass) const
{
	return nullptr;
}

UPlayspaceComponent* UFortPlayspaceMembershipActorComponent::GetBoundPlayspaceComponent(TSubclassOf<UPlayspaceComponent> ComponentClass) const
{
	return nullptr;
}

void UFortPlayspaceMembershipActorComponent::HandleBoundPlayspaceEndplayEvent(AActor* InOwner, EEndPlayReason::Type EndPlayReason)
{
}

void UFortPlayspaceMembershipActorComponent::OnRep_BoundPlayspace()
{
}

void UFortPlayspaceMembershipActorComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UFortPlayspaceMembershipActorComponent, BoundPlayspace);
}
