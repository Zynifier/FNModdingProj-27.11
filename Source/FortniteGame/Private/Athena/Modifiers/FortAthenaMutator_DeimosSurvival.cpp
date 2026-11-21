// Copyright Epic Games, Inc. All Rights Reserved.

#include "Athena/Modifiers/FortAthenaMutator_DeimosSurvival.h"

void AFortAthenaMutator_DeimosSurvival::OnBuildingActorDestroyed(AActor* DamagedActor, float Damage, AController* InstigatedBy, AActor* DamageCauser, FVector HitLocation, UPrimitiveComponent* FHitComponent, FName BoneName, FVector Momentum)
{
}

void AFortAthenaMutator_DeimosSurvival::OnPlaylistDataLoaded(FName PlaylistName, const FGameplayTagContainer& PlaylistContainerTag)
{
}

void AFortAthenaMutator_DeimosSurvival::OnSafezoneChanged(const FFortSafeZonePhaseUpdatedEvent& Event)
{
}
