// Copyright Epic Games, Inc. All Rights Reserved.

#include "Items/FortPickupEffect.h"

UMaterialInstanceDynamic* AFortPickupEffect::ApplyCosmeticOverridesToMaterial(UMeshComponent* MeshComponent, int32 MatIndex)
{
	return nullptr;
}

UFortItem* AFortPickupEffect::GetPickupDummyItem() const
{
	return nullptr;
}

void AFortPickupEffect::OnAboutToEnterBackpack_Implementation(AFortPawn* PickupTarget)
{
}

void AFortPickupEffect::OnTossed_Implementation()
{
}
