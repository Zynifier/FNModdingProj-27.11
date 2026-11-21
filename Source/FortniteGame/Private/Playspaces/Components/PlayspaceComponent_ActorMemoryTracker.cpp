// Copyright Epic Games, Inc. All Rights Reserved.

#include "Playspaces/Components/PlayspaceComponent_ActorMemoryTracker.h"
#include "Net/UnrealNetwork.h"

void UPlayspaceComponent_ActorMemoryTracker::OnRep_MemoryThreshold()
{
}

void UPlayspaceComponent_ActorMemoryTracker::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UPlayspaceComponent_ActorMemoryTracker, MemoryThreshold);
}
