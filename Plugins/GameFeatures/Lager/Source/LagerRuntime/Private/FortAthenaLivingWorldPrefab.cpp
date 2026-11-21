// Copyright Epic Games, Inc. All Rights Reserved.

#include "FortAthenaLivingWorldPrefab.h"
#include "Net/UnrealNetwork.h"

void AFortAthenaLivingWorldPrefab::AllowSpawnerToSpawn()
{
}

#if WITH_EDITOR
void AFortAthenaLivingWorldPrefab::ApplyTemplateToActorsWithoutComponent()
{
}
#endif

#if WITH_EDITOR
void AFortAthenaLivingWorldPrefab::ApplyTemplateToAllActors()
{
}
#endif

void AFortAthenaLivingWorldPrefab::CallWhenAllActorHaveSpawned(const FOnAllActorSpawnedDelegate& DelegateToCall)
{
}

void AFortAthenaLivingWorldPrefab::DestroyBuildingsInLevelBounds(const FOnBuildingInLevelBoundsDestroyed& FinishedDelegate)
{
}

FBox AFortAthenaLivingWorldPrefab::GetLevelBounds() const
{
	return FBox();
}

AFortAthenaLivingWorldPrefab* AFortAthenaLivingWorldPrefab::GetOwningLivingWorldPrefab(const UObject* WorldContextObject)
{
	return nullptr;
}

void AFortAthenaLivingWorldPrefab::MakeLevelVisible()
{
}

#if WITH_EDITOR
void AFortAthenaLivingWorldPrefab::OnActorSpawnedInWorldEditor(AActor* SpawnedActor)
{
}
#endif

void AFortAthenaLivingWorldPrefab::OnRep_ShouldLevelBeVisible()
{
}

void AFortAthenaLivingWorldPrefab::RemoveFoliageInsideLevelBound()
{
}

void AFortAthenaLivingWorldPrefab::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AFortAthenaLivingWorldPrefab, bShouldLevelBeVisible);
}
