// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Misc/Guid.h"
#include "FortItemAndCount.h"
#include "FortItemVariantHandle.h"
#include "Items/FortItemEntry.h"
#include "FortCreativeItemLibrary.generated.h"

class UFortItemDefinition;
class UObject;
enum class EFortRarity : uint8;

UCLASS(BlueprintType, Blueprintable)
class UFortCreativeItemLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="Creative|Item Variant", meta=(BlueprintAutocast, CompactNodeTitle="->", DisplayName="ToItemVariantHandle (ItemAndCount)"))
	static FItemVariantHandle Conv_ItemAndCountToItemVariantHandle(const FItemAndCount& ItemAndCount);

	UFUNCTION(BlueprintPure, Category="Creative|Item Variant", meta=(BlueprintAutocast, CompactNodeTitle="->", DisplayName="ToItemVariantHandle (FortItemDefinition)"))
	static FItemVariantHandle Conv_ItemDefToItemVariantHandle(UFortItemDefinition* ItemDefinition);

	UFUNCTION(BlueprintPure, Category="Creative|Item Variant", meta=(BlueprintAutocast, CompactNodeTitle="->", DisplayName="ToItemVariantHandle (ItemEntry)"))
	static FItemVariantHandle Conv_ItemEntryToItemVariantHandle(const FFortItemEntry& ItemEntry);

	UFUNCTION(BlueprintPure, Category="Creative|Item Data", meta=(CPP_Default_InCount="1", CPP_Default_InLevel="0", CPP_Default_ItemVariantGuid="()"))
	static FFortItemEntry CreateItemVariantEntry(const UFortItemDefinition* InItemDefinition, const int32 InCount, const int32 InLevel, const FGuid& ItemVariantGuid, const int32 PickupInstigatorHandle = -1);

	UFUNCTION(BlueprintPure, Category="Creative|Item Variant", meta=(CompactNodeTitle="==", DisplayName="Equal (ItemVariantHandle)", Keywords="== equal"))
	static bool EqualEqual_ItemVariantHandle(const FItemVariantHandle& A, const FItemVariantHandle& B);

	UFUNCTION(BlueprintPure, Category="Creative|Item Data", meta=(WorldContext="SpatialContextObj"))
	static bool GetDisplayName(UObject* SpatialContextObj, const FItemVariantHandle& ItemHandle, FText& DisplayName, bool bBaseName = false, bool bOnlyOverridden = false);

	UFUNCTION(BlueprintPure, Category="Creative|Item Data", meta=(DeterminesOutputType="ClassType", DynamicOutputParam="ItemDefintion"))
	static bool GetItemDefinition(const FItemVariantHandle& ItemHandle, TSubclassOf<UFortItemDefinition> ClassType, UFortItemDefinition*& ItemDefintion);

	UFUNCTION(BlueprintPure, Category="Creative|Item Data")
	static void GetItemVariantHandle(const FFortItemEntry& ItemEntry, FItemVariantHandle& ItemHandle);

	UFUNCTION(BlueprintPure, Category="Creative|Item Data", meta=(WorldContext="SpatialContextObj"))
	static bool GetRarity(UObject* SpatialContextObj, const FItemVariantHandle& ItemHandle, EFortRarity& Rarity, bool bOnlyOverridden = false);

	UFUNCTION(BlueprintPure, Category="Creative|Item Variant", meta=(CompactNodeTitle="isValid?", DisplayName="Is Valid (ItemVariantHandle)"))
	static bool IsValid_ItemVariantHandle(const FItemVariantHandle& ItemHandle);

	UFUNCTION(BlueprintPure, Category="Creative|Item Variant", meta=(CompactNodeTitle="!=", DisplayName="NotEqual (ItemVariantHandle)", Keywords="!= not equal"))
	static bool NotEqual_ItemVariantHandle(const FItemVariantHandle& A, const FItemVariantHandle& B);

};

