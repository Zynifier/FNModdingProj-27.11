// Copyright Epic Games, Inc. All Rights Reserved.

#include "CharacterDefinition/NPCCharacterModifier_Inventory.h"

#if WITH_EDITOR
bool UNPCCharacterModifier_Inventory::ShouldFilterAsset(const FAssetData& AssetData) const
{
	return false;
}
#endif
