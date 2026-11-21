// Copyright Epic Games, Inc. All Rights Reserved.

#include "Creative/FortCreativeItemLibrary.h"

FItemVariantHandle UFortCreativeItemLibrary::Conv_ItemAndCountToItemVariantHandle(const FItemAndCount& ItemAndCount)
{
	return FItemVariantHandle();
}

FItemVariantHandle UFortCreativeItemLibrary::Conv_ItemDefToItemVariantHandle(UFortItemDefinition* ItemDefinition)
{
	return FItemVariantHandle();
}

FItemVariantHandle UFortCreativeItemLibrary::Conv_ItemEntryToItemVariantHandle(const FFortItemEntry& ItemEntry)
{
	return FItemVariantHandle();
}

FFortItemEntry UFortCreativeItemLibrary::CreateItemVariantEntry(const UFortItemDefinition* InItemDefinition, const int32 InCount, const int32 InLevel, const FGuid& ItemVariantGuid, const int32 PickupInstigatorHandle)
{
	return FFortItemEntry();
}

bool UFortCreativeItemLibrary::EqualEqual_ItemVariantHandle(const FItemVariantHandle& A, const FItemVariantHandle& B)
{
	return false;
}

bool UFortCreativeItemLibrary::GetDisplayName(UObject* SpatialContextObj, const FItemVariantHandle& ItemHandle, FText& DisplayName, bool bBaseName, bool bOnlyOverridden)
{
	return false;
}

bool UFortCreativeItemLibrary::GetItemDefinition(const FItemVariantHandle& ItemHandle, TSubclassOf<UFortItemDefinition> ClassType, UFortItemDefinition*& ItemDefintion)
{
	return false;
}

void UFortCreativeItemLibrary::GetItemVariantHandle(const FFortItemEntry& ItemEntry, FItemVariantHandle& ItemHandle)
{
}

bool UFortCreativeItemLibrary::GetRarity(UObject* SpatialContextObj, const FItemVariantHandle& ItemHandle, EFortRarity& Rarity, bool bOnlyOverridden)
{
	return false;
}

bool UFortCreativeItemLibrary::IsValid_ItemVariantHandle(const FItemVariantHandle& ItemHandle)
{
	return false;
}

bool UFortCreativeItemLibrary::NotEqual_ItemVariantHandle(const FItemVariantHandle& A, const FItemVariantHandle& B)
{
	return false;
}
