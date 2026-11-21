// Copyright Epic Games, Inc. All Rights Reserved.

#include "Components/FortPawnComponent_Disguise.h"

bool UFortPawnComponent_Disguise::CanBeRevealed() const
{
	return false;
}

void UFortPawnComponent_Disguise::OnOwnerPawnDamaged(AActor* DamageOnOwnerPawnDamagedActor, float Damage, AController* InstigatedBy, AActor* DamageCauser, FVector HitLocation, UPrimitiveComponent* FHitComponent, FName BoneName, FVector Momentum)
{
}

void UFortPawnComponent_Disguise::RevealDisguise(const AActor* RevealInstigator, EFortPawnComponent_DisguiseRevealReason RevealReason)
{
}
