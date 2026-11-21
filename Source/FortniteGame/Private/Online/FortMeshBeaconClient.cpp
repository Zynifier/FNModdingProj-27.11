// Copyright Epic Games, Inc. All Rights Reserved.

#include "Online/FortMeshBeaconClient.h"
#include "Net/UnrealNetwork.h"

void AFortMeshBeaconClient::OnRep_GameplayTagIndexHash()
{
}

void AFortMeshBeaconClient::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AFortMeshBeaconClient, GameplayTagIndexHash);
}
