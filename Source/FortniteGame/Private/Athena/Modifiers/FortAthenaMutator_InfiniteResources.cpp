// Copyright Epic Games, Inc. All Rights Reserved.

#include "Athena/Modifiers/FortAthenaMutator_InfiniteResources.h"
#include "Net/UnrealNetwork.h"

void AFortAthenaMutator_InfiniteResources::OnRep_bInfiniteResources()
{
}

void AFortAthenaMutator_InfiniteResources::UpdateResourceIcons()
{
}

void AFortAthenaMutator_InfiniteResources::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AFortAthenaMutator_InfiniteResources, bInfiniteResources);
}
