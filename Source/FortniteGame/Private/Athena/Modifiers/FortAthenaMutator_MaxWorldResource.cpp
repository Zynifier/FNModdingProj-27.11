// Copyright Epic Games, Inc. All Rights Reserved.

#include "Athena/Modifiers/FortAthenaMutator_MaxWorldResource.h"
#include "Net/UnrealNetwork.h"

void AFortAthenaMutator_MaxWorldResource::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AFortAthenaMutator_MaxWorldResource, MaxWorldResources);
}
