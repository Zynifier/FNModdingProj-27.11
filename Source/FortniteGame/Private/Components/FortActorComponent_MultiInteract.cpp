// Copyright Epic Games, Inc. All Rights Reserved.

#include "Components/FortActorComponent_MultiInteract.h"
#include "Net/UnrealNetwork.h"

UFortActorComponent_MultiInteract::UFortActorComponent_MultiInteract(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UFortActorComponent_MultiInteract::AddInteractingActor(AActor* InteractingActorToAdd)
{
}

int32 UFortActorComponent_MultiInteract::GetInteractingActorCount(const bool bIncludePlayers, const bool bIncludeNonPlayers) const
{
	return int32();
}

float UFortActorComponent_MultiInteract::GetInteractionDuration() const
{
	return float();
}

float UFortActorComponent_MultiInteract::GetMultiplier() const
{
	return float();
}

float UFortActorComponent_MultiInteract::GetServerInteractionDuration() const
{
	return float();
}

void UFortActorComponent_MultiInteract::HandleInteractingActorDestroyed(AActor* DestroyedActor)
{
}

bool UFortActorComponent_MultiInteract::HasMaxInteractingActors() const
{
	return false;
}

bool UFortActorComponent_MultiInteract::IsMultipleInteractionEnabled() const
{
	return false;
}

void UFortActorComponent_MultiInteract::OnRep_InteractingNonPlayerActorCount()
{
}

void UFortActorComponent_MultiInteract::OnRep_InteractingPlayers()
{
}

void UFortActorComponent_MultiInteract::OnRep_ServerInteractionData()
{
}

void UFortActorComponent_MultiInteract::RemoveInteractingActor(AActor* InteractingActorToRemove)
{
}

void UFortActorComponent_MultiInteract::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UFortActorComponent_MultiInteract, ServerInteractionData);
	DOREPLIFETIME(UFortActorComponent_MultiInteract, InteractingPlayers);
	DOREPLIFETIME(UFortActorComponent_MultiInteract, InteractingNonPlayerActorCount);
}
