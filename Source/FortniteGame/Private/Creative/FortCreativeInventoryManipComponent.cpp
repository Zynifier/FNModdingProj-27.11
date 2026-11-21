// Copyright Epic Games, Inc. All Rights Reserved.

#include "Creative/FortCreativeInventoryManipComponent.h"

void UFortCreativeInventoryManipComponent::DropAllItems(AController* Controller, const FFortCreativeItemDropParams& DropParams, int32& ItemRemovedCount, int32& SpawnedPickupCount)
{
}

void UFortCreativeInventoryManipComponent::DropItemsByItemType(AController* Controller, const TArray<FName>& MatchCreativeTags, const TArray<FName>& IgnoreCreativeTags, const FFortCreativeItemDropParams& DropParams, int32& ItemRemovedCount, int32& SpawnedPickupCount, EFortItemType ItemType)
{
}

void UFortCreativeInventoryManipComponent::DropSpecificItem(AController* Controller, const UFortWorldItemDefinition* ItemDefinition, FGuid ItemVariantGuid, const FFortCreativeItemDropParams& DropParams, int32& ItemRemovedCount, int32& SpawnedPickupCount)
{
}

void UFortCreativeInventoryManipComponent::DropSpecificItemVariant(AController* Controller, const FItemVariantHandle& VariantHandle, const FFortCreativeItemDropParams& DropParams, int32& ItemRemovedCount, int32& SpawnedPickupCount)
{
}

void UFortCreativeInventoryManipComponent::DropSpecificWeaponClass(AController* Controller, const UFortWorldItemDefinition* ItemDefinition, const FFortCreativeItemDropParams& DropParams, int32& ItemRemovedCount, int32& SpawnedPickupCount)
{
}
