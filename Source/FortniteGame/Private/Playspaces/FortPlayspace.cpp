// Copyright Epic Games, Inc. All Rights Reserved.

#include "Playspaces/FortPlayspace.h"
#include "Net/UnrealNetwork.h"

AFortPlayspaceReplicatedState* AFortPlayspace::GetReplicatedState()
{
	return nullptr;
}

void AFortPlayspace::HandleMatchStarted()
{
}

void AFortPlayspace::HandleMatchStarted_Internal()
{
}

void AFortPlayspace::OnMeshNetworkEventBurst(const FName& EventName, const EMeshNetworkNodeType NodeType, const FString& EventParameters)
{
}

void AFortPlayspace::OnMeshNetworkEventChange(const FName& EventName, const FDateTime& EventStartTime, const EMeshNetworkNodeType NodeType, const FString& EventParameters)
{
}

void AFortPlayspace::OnMeshNetworkEventEnd(const FName& EventName, const EMeshNetworkNodeType NodeType)
{
}

void AFortPlayspace::OnMeshNetworkEventStart(const FName& EventName, const FDateTime& EventStartTime, const EMeshNetworkNodeType NodeType, const FString& EventParameters)
{
}

void AFortPlayspace::OnMeshNetworkReady(EMeshNetworkNodeType NodeType)
{
}

void AFortPlayspace::OnRep_ShouldCreateEventRouter()
{
}

void AFortPlayspace::PostHandleMatchStarted()
{
}

void AFortPlayspace::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AFortPlayspace, ReplicatedState);
	DOREPLIFETIME(AFortPlayspace, bShouldCreateEventRouter);
}
