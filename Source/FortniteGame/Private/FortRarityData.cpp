// Copyright Epic Games, Inc. All Rights Reserved.

#include "FortRarityData.h"

FFortColorPalette UFortRarityData::BPGetRarityColorPalette(EFortRarity Rarity)
{
	return FFortColorPalette();
}

FFortRarityItemData UFortRarityData::BPGetRarityData(EFortRarity Rarity)
{
	return FFortRarityItemData();
}

FFortRarityItemData UFortRarityData::BPGetRarityDataForItemDef(const UFortItemDefinition* ItemDef)
{
	return FFortRarityItemData();
}

EFortRarity UFortRarityData::GetRarityCosmeticForItem(const UObject* WorldContextObject, const UFortItem* Item)
{
	return EFortRarity();
}
