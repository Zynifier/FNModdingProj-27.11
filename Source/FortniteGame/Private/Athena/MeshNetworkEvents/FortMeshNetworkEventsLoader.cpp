// Copyright Epic Games, Inc. All Rights Reserved.

#include "Athena/MeshNetworkEvents/FortMeshNetworkEventsLoader.h"
#include "Net/UnrealNetwork.h"

void AFortMeshNetworkEventsLoader::MulticastMeshNetEventBurst_Implementation(FName EventName, const FString& EventParams, const FGameplayTagContainer& Filters)
{
}

void AFortMeshNetworkEventsLoader::OnMeshNetworkReady(EMeshNetworkNodeType NodeType)
{
}

void AFortMeshNetworkEventsLoader::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AFortMeshNetworkEventsLoader, ActiveMeshNetworkEvents);
}
