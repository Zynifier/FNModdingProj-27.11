// Copyright Epic Games, Inc. All Rights Reserved.

#include "CreativeRoyalePlayspaceComponent_LevelReset.h"

void UCreativeRoyalePlayspaceComponent_LevelReset::AddActorToTrack(AActor* ActorToTrack)
{
}

void UCreativeRoyalePlayspaceComponent_LevelReset::BindActorToCallbacks(AActor* Actor)
{
}

void UCreativeRoyalePlayspaceComponent_LevelReset::CachePoiSwapManager()
{
}

void UCreativeRoyalePlayspaceComponent_LevelReset::ClearFoundActors()
{
}

void UCreativeRoyalePlayspaceComponent_LevelReset::DestroyDamagedActors()
{
}

ULevelSaveRecord* UCreativeRoyalePlayspaceComponent_LevelReset::GetLevelSaveRecord()
{
	return nullptr;
}

UFortPoiSwapManager* UCreativeRoyalePlayspaceComponent_LevelReset::GetPoiSwapManager()
{
	return nullptr;
}

void UCreativeRoyalePlayspaceComponent_LevelReset::HandleBuildingDamaged(AActor* DamagedActor, float Damage, AController* InstigatedBy, AActor* DamageCauser, FVector HitLocation, UPrimitiveComponent* FHitComponent, FName BoneName, FVector Momentum)
{
}

void UCreativeRoyalePlayspaceComponent_LevelReset::HandleBuildingDestroyed(const TWeakObjectPtr<ABuildingActor> DestroyedBuilding)
{
}

void UCreativeRoyalePlayspaceComponent_LevelReset::HandleBuildingDied(AActor* DamagedActor, float Damage, AController* InstigatedBy, AActor* DamageCauser, FVector HitLocation, UPrimitiveComponent* FHitComponent, FName BoneName, FVector Momentum)
{
}

void UCreativeRoyalePlayspaceComponent_LevelReset::HandleMinigameStateChanged(AFortMinigame* Minigame, EFortMinigameState NewMinigameState)
{
}

void UCreativeRoyalePlayspaceComponent_LevelReset::OnPlotLoadComplete()
{
}

void UCreativeRoyalePlayspaceComponent_LevelReset::OnSpawningFromSaveFinish()
{
}

void UCreativeRoyalePlayspaceComponent_LevelReset::RespawnDeadActors()
{
}

void UCreativeRoyalePlayspaceComponent_LevelReset::RestoreAttachedBuildingActors(FGuid SpawnableActorGuid, AActor* Actor)
{
}

void UCreativeRoyalePlayspaceComponent_LevelReset::SaveActorToBeRespawned(AActor* ActorToBeRespawned, const bool bRemoveDamagedActor)
{
}

void UCreativeRoyalePlayspaceComponent_LevelReset::SaveDamagedActor(AActor* DamagedActor)
{
}

void UCreativeRoyalePlayspaceComponent_LevelReset::SaveParentToAttachToInformation(FGuid ActorToAttachGuid, AActor* ActorToAttach)
{
}
