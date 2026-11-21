// Copyright Epic Games, Inc. All Rights Reserved.

#include "MultiProductItemShop/FortMPItemShopRow.h"

UFortMPItemShopRow::UFortMPItemShopRow(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

const UCommonButtonBase* UFortMPItemShopRow::CreateEntryTile(UFortItemShopOfferVM* OfferVM, const TSubclassOf<UCommonButtonBase> TileEntryWidgetClass)
{
	return nullptr;
}
