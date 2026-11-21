// Copyright Epic Games, Inc. All Rights Reserved.

#include "GameplayVolume.h"
#include "Net/UnrealNetwork.h"

APlayspace* AGameplayVolume::GetPlayspace() const
{
	return nullptr;
}

void AGameplayVolume::InitializeBoundsComponent(UOverlapComponent* NewBoundsComponent)
{
}

void AGameplayVolume::OnOverlappedPawnControllerChanged(APawn* Pawn, AController* OldController, AController* NewController)
{
}

void AGameplayVolume::UpdateSize(const FVector& NewScale)
{
}

void AGameplayVolume::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AGameplayVolume, Playspace);
	DOREPLIFETIME(AGameplayVolume, VolumeTags);
}
