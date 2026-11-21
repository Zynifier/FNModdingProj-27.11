// Copyright Epic Games, Inc. All Rights Reserved.

#include "Components/PlayspaceControllerComponent_PlayerSpawning.h"
#include "Net/UnrealNetwork.h"

UPlayspaceControllerComponent_PlayerSpawning::UPlayspaceControllerComponent_PlayerSpawning(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UPlayspaceControllerComponent_PlayerSpawning::ClientReplicatedSpawnInfo_Implementation(const FReplicatedSpawnInfo& InReplicatedSpawnInfo)
{
}

const FReplicatedSpawnInfo& UPlayspaceControllerComponent_PlayerSpawning::GetSpawnInfo() const
{
	static FReplicatedSpawnInfo Dummy;
	return Dummy;
}

void UPlayspaceControllerComponent_PlayerSpawning::OnRep_ReplicatedSpawnInfo()
{
}

void UPlayspaceControllerComponent_PlayerSpawning::ServerMarkReadyForSpawning_Implementation()
{
}
bool UPlayspaceControllerComponent_PlayerSpawning::ServerMarkReadyForSpawning_Validate()
{
	return true;
}

void UPlayspaceControllerComponent_PlayerSpawning::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UPlayspaceControllerComponent_PlayerSpawning, ReplicatedSpawnInfo);
}
