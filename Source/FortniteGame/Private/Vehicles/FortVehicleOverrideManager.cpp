// Copyright Epic Games, Inc. All Rights Reserved.

#include "Vehicles/FortVehicleOverrideManager.h"
#include "Net/UnrealNetwork.h"

UFortVehicleOverrideManager::UFortVehicleOverrideManager(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UFortVehicleOverrideManager::HandleVehicleDeath(AFortAthenaVehicle* DeadVehicle, const FGameplayTagContainer& InTags, AController* EventInstigator, AActor* DamageCauser)
{
}

void UFortVehicleOverrideManager::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UFortVehicleOverrideManager, ReplicatedVehicleOverrides);
}
