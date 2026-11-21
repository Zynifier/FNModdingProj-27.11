// Copyright Epic Games, Inc. All Rights Reserved.

#include "Athena/ItemShop/AthenaItemShopTile.h"

UFortMtxOfferData* UAthenaItemShopTile::GetLegacyDisplayAsset() const
{
	return nullptr;
}

void UAthenaItemShopTile::HandleLocalAccountInfoChanged(FFortPrivateAccountInfo NewInfo)
{
}

bool UAthenaItemShopTile::IsUsingLargeLayout() const
{
	return false;
}

void UAthenaItemShopTile::ShowNextPresentation()
{
}
