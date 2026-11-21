// Copyright Epic Games, Inc. All Rights Reserved.

#include "Customization/CustomCosmeticCharmModifier.h"

void ACustomCosmeticCharmModifier::ForceResetParticleSystems()
{
}

const EFortCustomCharmType::Type ACustomCosmeticCharmModifier::GetCharacterCharmType() const
{
	return EFortCustomCharmType::Type();
}

AFortPlayerCharm* ACustomCosmeticCharmModifier::GetCharmOwner() const
{
	return nullptr;
}

UMeshComponent* ACustomCosmeticCharmModifier::GetSkeletalMeshForAssociatedPlayerPawnCharmType() const
{
	return nullptr;
}
