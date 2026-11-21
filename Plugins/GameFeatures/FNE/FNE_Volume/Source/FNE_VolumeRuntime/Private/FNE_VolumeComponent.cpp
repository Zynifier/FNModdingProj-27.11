// Copyright Epic Games, Inc. All Rights Reserved.

#include "FNE_VolumeComponent.h"

bool UFNE_VolumeComponent::BindToOnOtherActorBeginOverlap(const FOnActorOverlapEvent& InEvent)
{
	return false;
}

bool UFNE_VolumeComponent::BindToOnOtherActorEndOverlap(const FOnActorOverlapEvent& InEvent)
{
	return false;
}

TArray<APawn*> UFNE_VolumeComponent::GetAllPlayerPawns() const
{
	return TArray<APawn*>();
}

TArray<APlayerState*> UFNE_VolumeComponent::GetAllPlayerStates() const
{
	return TArray<APlayerState*>();
}

TArray<AActor*> UFNE_VolumeComponent::GetAllTrackedActors() const
{
	return TArray<AActor*>();
}

bool UFNE_VolumeComponent::GetEnableOverlap() const
{
	return false;
}

AFNE_Volume* UFNE_VolumeComponent::GetSpawnedVolume() const
{
	return nullptr;
}

UOverlapComponent* UFNE_VolumeComponent::GetSpawnedVolumeBoundsComponent()
{
	return nullptr;
}

void UFNE_VolumeComponent::HandleNotifyActorBeginOverlap(AActor* OverlappedActor, AActor* OtherActor)
{
}

void UFNE_VolumeComponent::HandleNotifyActorEndOverlap(AActor* OverlappedActor, AActor* OtherActor)
{
}

void UFNE_VolumeComponent::HandleNotifyPlayerStateBeginOverlap(APlayerState* TouchingPlayerState, AGameplayVolume* Volume)
{
}

void UFNE_VolumeComponent::HandleNotifyPlayerStateEndOverlap(APlayerState* TouchingPlayerState, AGameplayVolume* Volume)
{
}

void UFNE_VolumeComponent::SetEnableOverlap(const bool bEnable)
{
}

void UFNE_VolumeComponent::SetRelativeScale3DForBoundsComponent(const FVector& Scale3D)
{
}

bool UFNE_VolumeComponent::SetStaticMeshForBoundsComponent(UStaticMesh* NewMesh)
{
	return false;
}

void UFNE_VolumeComponent::UnBindFromOnOtherActorBeginOverlap(const FOnActorOverlapEvent& InEvent)
{
}

void UFNE_VolumeComponent::UnBindFromOnOtherActorEndOverlap(const FOnActorOverlapEvent& InEvent)
{
}

void UFNE_VolumeComponent::UpdateOverLapShape(EFNEVolumeShapeTypeEnum EShape, const bool bUseCustomShape, UStaticMesh* CustomShape)
{
}
