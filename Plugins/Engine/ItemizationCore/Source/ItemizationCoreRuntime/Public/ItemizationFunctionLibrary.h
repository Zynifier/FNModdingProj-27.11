// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Misc/Guid.h"
#include "InventoryEventTypes.h"
#include "ItemizationFunctionLibrary.generated.h"

class UItemAttribute;
class UItemAttribute_Bool;
class UItemAttribute_Decimal;
class UItemAttribute_Int;
class UItemAttribute_String;
class UItemDefinitionBase;

/**
 * 
 */
UCLASS()
class ITEMIZATIONCORERUNTIME_API UItemizationFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="Itemization")
	static FString DescribeInventoryID(const FGuid& InventoryID);

	UFUNCTION(BlueprintPure, Category="Itemization")
	static FString DescribeItemEntryID(const FGuid& ItemEntryID);

	UFUNCTION(BlueprintPure, Category="Itemization")
	static TArray<TSubclassOf<UItemAttribute>> GetItemDataAttributeList(const FItemAggregatedData& ItemData);

	UFUNCTION(BlueprintPure, Category="Itemization")
	static bool GetItemDataBoolAttributeValue(const FItemAggregatedData& ItemData, const TSubclassOf<UItemAttribute_Bool> AttributeClass);

	UFUNCTION(BlueprintPure, Category="Itemization")
	static double GetItemDataDecimalAttributeValue(const FItemAggregatedData& ItemData, const TSubclassOf<UItemAttribute_Decimal> AttributeClass);

	UFUNCTION(BlueprintPure, Category="Itemization")
	static const UItemDefinitionBase* GetItemDataDefinition(const FItemAggregatedData& ItemData);

	UFUNCTION(BlueprintPure, Category="Itemization")
	static int64 GetItemDataIntAttributeValue(const FItemAggregatedData& ItemData, const TSubclassOf<UItemAttribute_Int> AttributeClass);

	UFUNCTION(BlueprintPure, Category="Itemization")
	static FGuid GetItemDataItemEntryID(const FItemAggregatedData& ItemData);

	UFUNCTION(BlueprintPure, Category="Itemization")
	static int32 GetItemDataSlot(const FItemAggregatedData& ItemData);

	UFUNCTION(BlueprintPure, Category="Itemization")
	static FString GetItemDataStringAttributeValue(const FItemAggregatedData& ItemData, const TSubclassOf<UItemAttribute_String> AttributeClass);

};

