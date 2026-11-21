// Copyright Epic Games, Inc. All Rights Reserved.

#include "FortDagwoodVehicleManager.h"

UFortDagwoodVehicleManager::UFortDagwoodVehicleManager(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UFortDagwoodVehicleManager::CustomHandleActorStreamedInEditor(AActor* SourceActor)
{
}

void UFortDagwoodVehicleManager::OnVehicleSpawned(AFortAthenaVehicle* Vehicle)
{
}

void UFortDagwoodVehicleManager::OnVehicleSpawnsUpdated(UFortVehicleItemDefinition* VehicleItemDef, TArray<AActor*>& SpawnedVehicles, int32 NewVehicleCount)
{
}

void UFortDagwoodVehicleManager::UpdatePropReplacement()
{
}
