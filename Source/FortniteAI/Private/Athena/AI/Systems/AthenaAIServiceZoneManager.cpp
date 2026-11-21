// Copyright Epic Games, Inc. All Rights Reserved.

#include "Athena/AI/Systems/AthenaAIServiceZoneManager.h"

UAthenaAIServiceZoneManager* UAthenaAIServiceZoneManager::GetAthenaAIServiceZoneManager(const UObject* WorldContextObject)
{
	return nullptr;
}

bool UAthenaAIServiceZoneManager::IsInDangerZone(const FVector& Location) const
{
	return false;
}

bool UAthenaAIServiceZoneManager::IsLOFOccluded(const FVector& StartLocation, const FVector& EndLocation) const
{
	return false;
}

void UAthenaAIServiceZoneManager::OnZoneDestroyed(AActor* Actor)
{
}

void UAthenaAIServiceZoneManager::RegisterDangerZone(AActor* Actor, const float Radius)
{
}

void UAthenaAIServiceZoneManager::RegisterOccluder(AActor* OccluderActor, const float SphereRadius)
{
}

void UAthenaAIServiceZoneManager::UnregisterDangerZone(AActor* Actor)
{
}

void UAthenaAIServiceZoneManager::UnregisterOccluder(AActor* OccluderActor)
{
}
