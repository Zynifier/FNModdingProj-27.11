// Copyright Epic Games, Inc. All Rights Reserved.

#include "Building/FortVolumeManager.h"
#include "Net/UnrealNetwork.h"

bool AFortVolumeManager::ActorsAreInSameVolume(const AActor* Left, const AActor* Right) const
{
	return false;
}

void AFortVolumeManager::AddOrRemovePawn(AFortPawn* FortPawn)
{
}

void AFortVolumeManager::AddOrRemovePawnAfterVehicleChange(AFortPlayerPawn* FortPawn, AActor* NewVehicle, AActor* OldVehicle)
{
}

bool AFortVolumeManager::AreIslandsLoading() const
{
	return false;
}

void AFortVolumeManager::AttemptAddToVolumeAfterDelay(AActor* Actor)
{
}

bool AFortVolumeManager::CanCreatePlayset(AFortPlayerPawn* Thrower, const FVector& StartLocation, const FRotator& PlaysetRotation, UFortPlaysetItemDefinition* NewPlayset)
{
	return false;
}

void AFortVolumeManager::DecrementUserIslandLoading()
{
}

void AFortVolumeManager::DestroyBuildingWhenNotInSameVolumeAsPlayerController(AFortPlayerController* PlayerController, ABuildingActor* TestBuildingActor)
{
}

FEvaluationResult AFortVolumeManager::DoesThermometerHaveBudgetForActor(const AActor* InstigatorActor, AActor* TestActor, const FVector& Location, const FRotator& Rotation) const
{
	return FEvaluationResult();
}

void AFortVolumeManager::EnterReadOnlyForVolume(AFortVolume* Volume)
{
}

TArray<AController*> AFortVolumeManager::GetAllPlayersInVolume(AFortVolume* Volume) const
{
	return TArray<AController*>();
}

TArray<APlayerState*> AFortVolumeManager::GetAllPlayerStatesInVolume(const AFortVolume* Volume) const
{
	return TArray<APlayerState*>();
}

AFortMinigame* AFortVolumeManager::GetMinigameForPlayerState(const APlayerState* PlayerState)
{
	return nullptr;
}

AFortMinigame* AFortVolumeManager::GetMinigameForVolume(const AActor* Volume)
{
	return nullptr;
}

AFortMinigame* AFortVolumeManager::GetMinigameFromVolume(const AActor* Actor) const
{
	return nullptr;
}

AFortVolume* AFortVolumeManager::GetNearestIslandVolumeForLocation(const FVector Location, FVector& OutNearestPoint, const float Padding) const
{
	return nullptr;
}

const AFortPlayerState* AFortVolumeManager::GetPlayerStateFromNetID(const FUniqueNetIdRepl& UniqueNetId) const
{
	return nullptr;
}

AFortVolume* AFortVolumeManager::GetVolumeForActor(const AActor* Actor) const
{
	return nullptr;
}

AFortVolume* AFortVolumeManager::GetVolumeForActorWithComponent(const AActor* Actor, const TSubclassOf<UActorComponent>& ComponentType, TArray<UActorComponent*>& OutComponents, const bool bUseActorBounds)
{
	return nullptr;
}

AFortVolume* AFortVolumeManager::GetVolumeForLocation(FVector Location) const
{
	return nullptr;
}

AFortVolume* AFortVolumeManager::GetVolumeForLocationWithComponent(FVector Location, const TSubclassOf<UActorComponent>& ComponentType, TArray<UActorComponent*>& OutComponents)
{
	return nullptr;
}

AFortVolume* AFortVolumeManager::GetVolumeForPlayerState(const APlayerState* PlayerState) const
{
	return nullptr;
}

void AFortVolumeManager::GetVolumeManager(const UObject* WorldContextObject, AFortVolumeManager*& OutVolumeManager, EVolumeValidityResult& OutIsValid)
{
}

int32 AFortVolumeManager::GetVolumePlayerCount(const AFortVolume* Volume) const
{
	return int32();
}

bool AFortVolumeManager::GetVolumesForActor(const AActor* Actor, TArray<AFortVolume*>& Volumes, const bool bUseActorBounds) const
{
	return false;
}

bool AFortVolumeManager::GetVolumesForLocation(FVector Location, TArray<AFortVolume*>& Volumes) const
{
	return false;
}

void AFortVolumeManager::HandleActorHealthChanged(AActor* Actor, float NewHealth)
{
}

void AFortVolumeManager::HandlePlayerPawnPossessed(APawn* Pawn)
{
}

void AFortVolumeManager::HandleSpatialLoadingStateChanged(ESpatialLoadingState NewState, AFortVolume* Volume)
{
}

void AFortVolumeManager::HandleVolumeReset(AFortVolume* VolumeResetting)
{
}

void AFortVolumeManager::IncrementUserIslandLoading()
{
}

void AFortVolumeManager::RemovePawnNotRespawningInsideVolume(AActor* DamagedActor, float Damage, AController* InstigatedBy, AActor* DamageCauser, FVector HitLocation, UPrimitiveComponent* FHitComponent, FName BoneName, FVector Momentum)
{
}

void AFortVolumeManager::ResetVolumeAndLevelRecord(AFortVolume* Volume, AFortPlayerController* RequestingFortPC)
{
}

AFortVolume* AFortVolumeManager::SpawnVolume(const TSubclassOf<AFortVolume>& VolumeActor, AActor* VolumeOwner, const UFortPlaysetItemDefinition* Playset, const FVector& Location, const FRotator& Rotation)
{
	return nullptr;
}

bool AFortVolumeManager::VolumeContainsUser(const APlayerState* PlayerState, const AFortVolume* Volume) const
{
	return false;
}

bool AFortVolumeManager::WillVolumeDeleteAfterActorSpawn(AFortVolume* Volume) const
{
	return false;
}

void AFortVolumeManager::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AFortVolumeManager, VolumeActivePlayers);
	DOREPLIFETIME(AFortVolumeManager, bInSpawningStartup);
}
