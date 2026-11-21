// Copyright Epic Games, Inc. All Rights Reserved.

#include "FortAthenaLivingWorldManager.h"
#include "Net/UnrealNetwork.h"

UFortAthenaLivingWorldManager::UFortAthenaLivingWorldManager(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

bool UFortAthenaLivingWorldManager::BuildDataRegistryResolverScope_Implementation(TArray<FName>& InOutResolverScopes, int32& InOutPriority) const
{
	return false;
}

void UFortAthenaLivingWorldManager::CancelSpawnRequest(const int32 RequestId)
{
}

void UFortAthenaLivingWorldManager::EndEncounter(UFortAthenaLivingWorldEncounterInstance* EncounterInstance)
{
}

UFortAthenaLivingWorldManager* UFortAthenaLivingWorldManager::GetLivingWorldManager(const UObject* WorldContextObject)
{
	return nullptr;
}

UFortAthenaLivingWorldEncounterInstance* UFortAthenaLivingWorldManager::GetOwningEncounter(AActor* Actor) const
{
	return nullptr;
}

bool UFortAthenaLivingWorldManager::HasPendingSpawnRequestForEncounter(const UFortAthenaLivingWorldEncounterInstance* EncounterInstance) const
{
	return false;
}

bool UFortAthenaLivingWorldManager::IsEncounterCategoryActive(const TSoftObjectPtr<UFortAthenaLivingWorldEncounter> EncounterType) const
{
	return false;
}

void UFortAthenaLivingWorldManager::LivingWorldManagerDebugEvent(const FString& EventName, int32 DebugIndex, const FString& RuntimeSpawnDataName, const FString& EncounterName)
{
}

void UFortAthenaLivingWorldManager::LivingWorldManagerDisablePointProvider(AActor* PointProvider)
{
}

void UFortAthenaLivingWorldManager::LivingWorldManagerDumpEventInstances()
{
}

void UFortAthenaLivingWorldManager::LivingWorldManagerDumpPrefabLevelBounds()
{
}

void UFortAthenaLivingWorldManager::LivingWorldManagerDumpSpawnCount()
{
}

void UFortAthenaLivingWorldManager::LivingWorldManagerEnablePointProvider(AActor* PointProvider)
{
}

void UFortAthenaLivingWorldManager::LivingWorldManagerFlush()
{
}

void UFortAthenaLivingWorldManager::LivingWorldManagerGenerateEvents()
{
}

void UFortAthenaLivingWorldManager::LivingWorldManagerProviderDebugActor(int32 ProviderIndex)
{
}

void UFortAthenaLivingWorldManager::LivingWorldManagerRegisterPointProvider(AActor* PointProvider)
{
}

void UFortAthenaLivingWorldManager::LivingWorldManagerSetEventGenerationEnabled(const bool bInGenerateEvents)
{
}

void UFortAthenaLivingWorldManager::LivingWorldManagerSwitchDensityDisplay(int32 DensityMapIndex)
{
}

void UFortAthenaLivingWorldManager::LivingWorldManagerToggleActorMinimap(const FString& Name)
{
}

void UFortAthenaLivingWorldManager::LivingWorldManagerToggleDensityDisplay()
{
}

void UFortAthenaLivingWorldManager::LivingWorldManagerToggleGenerateEvents()
{
}

void UFortAthenaLivingWorldManager::LivingWorldManagerToggleVerboseLogging()
{
}

void UFortAthenaLivingWorldManager::LivingWorldManagerUnregisterPointProvider(AActor* PointProvider)
{
}

void UFortAthenaLivingWorldManager::LWMF()
{
}

void UFortAthenaLivingWorldManager::LWMTAM(const FString& Name)
{
}

void UFortAthenaLivingWorldManager::OnActorSpawned(AActor* Actor, int32 RequestId)
{
}

void UFortAthenaLivingWorldManager::OnCurrentPlaylistLoaded(FName PlaylistName, const FGameplayTagContainer& PlaylistContextTags)
{
}

void UFortAthenaLivingWorldManager::OnDebugSpawnEventSpawned(const TArray<AActor*>& SpawnedActors, bool bSuccess)
{
}

void UFortAthenaLivingWorldManager::OnPatrolPathAdded(AFortAthenaPatrolPath* PatrolPath)
{
}

void UFortAthenaLivingWorldManager::OnRep_ActorClassToPreloadOnClient()
{
}

void UFortAthenaLivingWorldManager::OnRep_DebugDensityMinimapIndicator(UFortAthenaLivingWorldDebugDensityMiniMapIndicator* OldMapIndicator)
{
}

void UFortAthenaLivingWorldManager::OnSpawnedActorDestroy(AActor* DestroyedActor)
{
}

void UFortAthenaLivingWorldManager::OnUnmanagedDensityReservoirActorDestroy(AActor* DestroyedActor)
{
}

void UFortAthenaLivingWorldManager::OnWorldFinishedInitialization(const FGameplayTagContainer& ContextTags)
{
}

float UFortAthenaLivingWorldManager::QueryActorDensityBudget(AActor* ReferenceActor, float Range) const
{
	return float();
}

int32 UFortAthenaLivingWorldManager::QueryEventBudget(FDataTableRowHandle EventEntry, const AActor* SpawnLocation) const
{
	return int32();
}

bool UFortAthenaLivingWorldManager::RegisterDensityReservoir(AActor* ActorDensityReservoir, float Density, float Range)
{
	return false;
}

bool UFortAthenaLivingWorldManager::RegisterTagDensityReservoir(AActor* ActorDensityReservoir, const TArray<FFortAthenaLivingWorldEventTagDensityRegistration>& TagsDensity)
{
	return false;
}

void UFortAthenaLivingWorldManager::RequestEventGeneration()
{
}

void UFortAthenaLivingWorldManager::ResetEncounter(UFortAthenaLivingWorldEncounterInstance* EncounterInstance)
{
}

UFortAthenaLivingWorldEncounterInstance* UFortAthenaLivingWorldManager::StartEncounter(const TSoftObjectPtr<UFortAthenaLivingWorldEncounter> EncounterType, const TArray<TScriptInterface<IFortAthenaLivingWorldPointProviderInterface>>& EncounterPointProviders, AActor* ActorDensityReservoir)
{
	return nullptr;
}

bool UFortAthenaLivingWorldManager::TrySpawnEvent(FDataTableRowHandle EventEntry, const FTransform SpawnLocation, const FOnLivingWorldRequestFinished& OnRequestFinished, int32& RequestId)
{
	return false;
}

void UFortAthenaLivingWorldManager::UnregisterDensityReservoir(AActor* ActorDensityReservoir)
{
}

void UFortAthenaLivingWorldManager::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UFortAthenaLivingWorldManager, ActorClassToPreloadOnClient);
	DOREPLIFETIME(UFortAthenaLivingWorldManager, DebugDensityMinimapIndicator);
}
