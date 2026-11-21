// Copyright Epic Games, Inc. All Rights Reserved.

#include "Playspaces/Components/PlayspaceComponent_CreativeSpawnTracker.h"
#include "Net/UnrealNetwork.h"

void UPlayspaceComponent_CreativeCollectionBase::SetCreativeActorCollection(const UFortCreativeActorCollection* NewActorCollection)
{
}

void UPlayspaceComponent_CreativeCollectionBase::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UPlayspaceComponent_CreativeCollectionBase, CreativeCollection);
}
