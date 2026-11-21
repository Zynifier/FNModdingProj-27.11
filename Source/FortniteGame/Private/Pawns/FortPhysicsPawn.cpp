// Copyright Epic Games, Inc. All Rights Reserved.

#include "Pawns/FortPhysicsPawn.h"
#include "Net/UnrealNetwork.h"

void AFortPhysicsPawn::ClientAckGoodMove_Implementation(uint32 MoveId)
{
}

void AFortPhysicsPawn::ClientBroadcastHitDetection_Implementation(APawn* ImpulseInstigator, float Radius, float Relevancy, const FVector HalfPoints, const FVector DoublePoints)
{
}

void AFortPhysicsPawn::OnRep_GravityMultiplier()
{
}

void AFortPhysicsPawn::OnRep_SafeTeleportInfo()
{
}

void AFortPhysicsPawn::ServerMove_Implementation(const FReplicatedPhysicsPawnState& InState)
{
}

void AFortPhysicsPawn::ServerMoveReliable_Implementation(const FReplicatedPhysicsPawnState& InState)
{
}

void AFortPhysicsPawn::ServerUpdateStateSync_Implementation(const TArray<uint8>& StateSyncData)
{
}

void AFortPhysicsPawn::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AFortPhysicsPawn, SafeTeleportInfo);
	DOREPLIFETIME(AFortPhysicsPawn, GravityMultiplier);
}
