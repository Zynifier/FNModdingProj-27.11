// Copyright Epic Games, Inc. All Rights Reserved.

#include "Components/FortGameStateComponent_Reboot.h"
#include "Net/UnrealNetwork.h"

bool UFortGameStateComponent_Reboot::IsResurrectionEnabled(const AFortPlayerPawn* PlayerPawn) const
{
	return false;
}

void UFortGameStateComponent_Reboot::SetSpawnMachineEnabledConfig(const ABuildingGameplayActorSpawnMachine* RebootVan, const FSpawnMachineEnabledConfig& EnabledConfig)
{
}

void UFortGameStateComponent_Reboot::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UFortGameStateComponent_Reboot, SpawnMachineRepData);
}
