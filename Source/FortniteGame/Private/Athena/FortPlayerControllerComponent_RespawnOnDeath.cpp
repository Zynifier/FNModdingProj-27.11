// Copyright Epic Games, Inc. All Rights Reserved.

#include "Athena/FortPlayerControllerComponent_RespawnOnDeath.h"
#include "Net/UnrealNetwork.h"

FVector UFortPlayerControllerComponent_RespawnOnDeath::BP_CalculateRespawnLocation_Implementation(const FVector& InRespawnLocation) const
{
	return FVector();
}

void UFortPlayerControllerComponent_RespawnOnDeath::OnDroneManagerFinished(AFortRespawnDroneManager* DroneManager)
{
}

void UFortPlayerControllerComponent_RespawnOnDeath::OnRep_DroneManager()
{
}

void UFortPlayerControllerComponent_RespawnOnDeath::ServerClientIsReadyToRespawn_Implementation()
{
}

void UFortPlayerControllerComponent_RespawnOnDeath::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UFortPlayerControllerComponent_RespawnOnDeath, DroneManager);
	DOREPLIFETIME(UFortPlayerControllerComponent_RespawnOnDeath, RespawnLocation);
}
