// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Misc/Guid.h"
#include "Net/Serialization/FastArraySerializer.h"
#include "ItemEntry.generated.h"

class UItemDefinitionBase;

USTRUCT(BlueprintType)
struct ITEMIZATIONCORERUNTIME_API FItemEntry : public FFastArraySerializerItem
{
	GENERATED_BODY()

protected:
	UPROPERTY(BlueprintReadOnly, Category="Item Definition")
	TObjectPtr<UItemDefinitionBase> ItemDefinition;

	//Unique item ID for a given item entry.
//This should never change for the duration of an item's existence in an inventory.

	UPROPERTY()
	FGuid ItemEntryID;

	UPROPERTY()
	int32 SlotNumber;

};

USTRUCT()
struct FItemEntryList : public FFastArraySerializer
{
	GENERATED_BODY()

private:
	UPROPERTY()
	TArray<FItemEntry> ItemList;

};

