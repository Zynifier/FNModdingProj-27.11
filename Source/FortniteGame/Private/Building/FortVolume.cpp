// Copyright Epic Games, Inc. All Rights Reserved.

#include "Building/FortVolume.h"
#include "Net/UnrealNetwork.h"

void AFortVolume::AddActor(AActor* ActorToAdd)
{
}

void AFortVolume::AddOrRemovePawnAfterVehicleChange(AFortPlayerPawn* FortPawn, AActor* NewVehicle, AActor* OldVehicle)
{
}

void AFortVolume::AddSelfToVolumeManager()
{
}

void AFortVolume::DestroyVolume()
{
}

FString AFortVolume::GetAccountIdOwnerOfIsland() const
{
	return FString();
}

TArray<AActor*> AFortVolume::GetActorsWithinVolumeByClass(TSubclassOf<AActor> ActorClass) const
{
	return TArray<AActor*>();
}

const UFortPlaysetItemDefinition* AFortVolume::GetCurrentPlayset() const
{
	return nullptr;
}

UFortVolumePersistenceOptions* AFortVolume::GetFortVolumePersistenceOptions() const
{
	return nullptr;
}

EFortVolumeType AFortVolume::GetFortVolumeType() const
{
	return EFortVolumeType();
}

AFortMinigame* AFortVolume::GetMinigame() const
{
	return nullptr;
}

int32 AFortVolume::GetNumPlayersInVolume() const
{
	return int32();
}

UFortVolumeObjectTrackingComponent* AFortVolume::GetObjectTrackingComponent() const
{
	return nullptr;
}

UStaticMeshComponent* AFortVolume::GetStaticMesh() const
{
	return nullptr;
}

bool AFortVolume::GetUserGeneratedContentRestricted() const
{
	return false;
}

bool AFortVolume::HasVolumeBoundsBlocked() const
{
	return false;
}

bool AFortVolume::IsPlayerAllowedInVolume(AFortPlayerController* NewUser)
{
	return false;
}

bool AFortVolume::IsReadOnly() const
{
	return false;
}

bool AFortVolume::IsReady() const
{
	return false;
}

void AFortVolume::OnRep_CurrentPlayset()
{
}

void AFortVolume::OnRep_ObjectTrackingComponent()
{
}

void AFortVolume::OnRep_UserGeneratedContentRestrictions()
{
}

void AFortVolume::OnRep_VolumeState()
{
}

void AFortVolume::RemoveActorWhenDied(AActor* DamagedActor, float Damage, AController* InstigatedBy, AActor* DamageCauser, FVector HitLocation, UPrimitiveComponent* FHitComponent, FName BoneName, FVector Momentum)
{
}

void AFortVolume::RemoveActorWhenEndPlay(AActor* Actor, const EEndPlayReason::Type EndPlayReason)
{
}

void AFortVolume::RemoveAthenaPawnWhenDied(AFortPlayerPawnAthena* FortPlayerPawnAthena)
{
}

void AFortVolume::ServerClearVolume_Implementation()
{
}

void AFortVolume::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AFortVolume, ObjectTrackingComponent);
	DOREPLIFETIME(AFortVolume, bNeverAllowSaving);
	DOREPLIFETIME(AFortVolume, CurrentPlayset);
	DOREPLIFETIME(AFortVolume, VolumeState);
	DOREPLIFETIME(AFortVolume, bUserGeneratedContentRestricted);
	DOREPLIFETIME(AFortVolume, IslandResourceManagerComponent);
	DOREPLIFETIME(AFortVolume, FortVolumePersistenceOptions);
}
