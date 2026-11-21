// Copyright Epic Games, Inc. All Rights Reserved.

#include "Components/FortWeaponFxComponent.h"

UFortWeaponFxComponent::UFortWeaponFxComponent(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UFortWeaponFxComponent::OnBeamFired(AFortWeapon* Weapon, bool bUsePersistentBeam, UFXSystemComponent* PSC, const FVector& BeamOrigin, const FVector& HitLocation)
{
}
