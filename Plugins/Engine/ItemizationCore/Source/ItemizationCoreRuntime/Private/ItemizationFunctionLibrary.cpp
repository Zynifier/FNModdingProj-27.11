// Copyright Epic Games, Inc. All Rights Reserved.

#include "ItemizationFunctionLibrary.h"

FString UItemizationFunctionLibrary::DescribeInventoryID(const FGuid& InventoryID)
{
	return FString();
}

FString UItemizationFunctionLibrary::DescribeItemEntryID(const FGuid& ItemEntryID)
{
	return FString();
}

TArray<TSubclassOf<UItemAttribute>> UItemizationFunctionLibrary::GetItemDataAttributeList(const FItemAggregatedData& ItemData)
{
	return TArray<TSubclassOf<UItemAttribute>>();
}

bool UItemizationFunctionLibrary::GetItemDataBoolAttributeValue(const FItemAggregatedData& ItemData, const TSubclassOf<UItemAttribute_Bool> AttributeClass)
{
	return false;
}

double UItemizationFunctionLibrary::GetItemDataDecimalAttributeValue(const FItemAggregatedData& ItemData, const TSubclassOf<UItemAttribute_Decimal> AttributeClass)
{
	return double();
}

const UItemDefinitionBase* UItemizationFunctionLibrary::GetItemDataDefinition(const FItemAggregatedData& ItemData)
{
	return nullptr;
}

int64 UItemizationFunctionLibrary::GetItemDataIntAttributeValue(const FItemAggregatedData& ItemData, const TSubclassOf<UItemAttribute_Int> AttributeClass)
{
	return int64();
}

FGuid UItemizationFunctionLibrary::GetItemDataItemEntryID(const FItemAggregatedData& ItemData)
{
	return FGuid();
}

int32 UItemizationFunctionLibrary::GetItemDataSlot(const FItemAggregatedData& ItemData)
{
	return int32();
}

FString UItemizationFunctionLibrary::GetItemDataStringAttributeValue(const FItemAggregatedData& ItemData, const TSubclassOf<UItemAttribute_String> AttributeClass)
{
	return FString();
}
