// Copyright Epic Games, Inc. All Rights Reserved.

#include "Building/LevelInstance/BuildingLevelInstance.h"
#include "Net/UnrealNetwork.h"

void ABuildingLevelInstance::OnRep_LevelInstanceSpawnGuid()
{
}

void ABuildingLevelInstance::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(ABuildingLevelInstance, LevelInstanceSpawnGuid);
}

const FLevelInstanceID& ABuildingLevelInstance::GetLevelInstanceID() const
{
	static FLevelInstanceID Dummy;
	return Dummy;
}

bool ABuildingLevelInstance::HasValidLevelInstanceID() const
{
	return false;
}

const FGuid& ABuildingLevelInstance::GetLevelInstanceGuid() const
{
	static FGuid Dummy;
	return Dummy;
}

const TSoftObjectPtr<UWorld>& ABuildingLevelInstance::GetWorldAsset() const
{
	static TSoftObjectPtr<UWorld> Dummy;
	return Dummy;
}

bool ABuildingLevelInstance::IsLoadingEnabled() const
{
	return false;
}

ULevelInstanceComponent* ABuildingLevelInstance::GetLevelInstanceComponent() const
{
	return nullptr;
}

ELevelInstanceRuntimeBehavior ABuildingLevelInstance::GetDesiredRuntimeBehavior() const
{
	return ELevelInstanceRuntimeBehavior();
}

ELevelInstanceRuntimeBehavior ABuildingLevelInstance::GetDefaultRuntimeBehavior() const
{
	return ELevelInstanceRuntimeBehavior();
}
