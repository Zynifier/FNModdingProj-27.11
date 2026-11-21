// Copyright Epic Games, Inc. All Rights Reserved.

#include "Athena/Creative/ItemTileView/AthenaCreativeItemTileButton.h"

bool UAthenaCreativeItemTileButton::CompareToItemEntry(const FFortItemEntry& InItemEntry)
{
	return false;
}

int32 UAthenaCreativeItemTileButton::GetItemTypeCount()
{
	return int32();
}

UAthenaCreativeItemEntryObjectWrapper* UAthenaCreativeItemTileButton::MakeFortItemEntryObjectWrapper(UObject* Target, FFortItemEntry& InItemEntry)
{
	return nullptr;
}
