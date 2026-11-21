// Copyright Epic Games, Inc. All Rights Reserved.

#include "Items/FortPickupsParent.h"

EFortRarity AFortPickupsParent::GetClientCosmeticRarity(const UFortItem* Item) const
{
	return EFortRarity();
}

UFortItem* AFortPickupsParent::GetCosmeticPickupItem() const
{
	return nullptr;
}

void AFortPickupsParent::OnPickedUpMIDSetup()
{
}

void AFortPickupsParent::SetHologramPickedUpParamsInternal(bool bTierZero)
{
}

void AFortPickupsParent::SetRarityColor(const TArray<FLinearColor>& RarityColors)
{
}

void AFortPickupsParent::SetupPickupLight(UPrimitiveComponent* PrimitiveComponent, USpotLightComponent* SpotLightComponent, const FLinearColor& LightColor)
{
}

UPrimitiveComponent* AFortPickupsParent::SetupPickupMesh()
{
	return nullptr;
}

void AFortPickupsParent::SetupStretchMIDsInternal()
{
}
