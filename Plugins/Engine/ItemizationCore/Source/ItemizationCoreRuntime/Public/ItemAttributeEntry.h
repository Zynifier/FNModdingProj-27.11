// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Misc/Guid.h"
#include "Net/Serialization/FastArraySerializer.h"
#include "ItemAttributeEntry.generated.h"

class AInventoryCollection;
class UInventory;
class UItemAttribute;

USTRUCT()
struct FVkAttributeValue
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TSubclassOf<UItemAttribute> Attribute;

	UPROPERTY()
	TArray<uint8> Data;

};

//An arbitrary attribute with a value for a given item ID.
//Should never be queried directly as it's not guaranteed to be present as attributes whose values do not differ from their default value will not be present in the FVkAttributeList.

USTRUCT()
struct FVkAttributeEntry : public FFastArraySerializerItem
{
	GENERATED_BODY()

protected:
	UPROPERTY()
	FGuid ItemEntryID;

	UPROPERTY()
	FVkAttributeValue AttributeValue;

};

USTRUCT()
struct FVkAttributeList : public FFastArraySerializer
{
	GENERATED_BODY()

private:
	UPROPERTY()
	TArray<FVkAttributeEntry> AttributeList;

	//OwningInventory is mainly used for debugging. We should be always relying on OwningInventory for events.

	UPROPERTY(Transient, NotReplicated)
	TWeakObjectPtr<AInventoryCollection> OwningInventoryCollection;

	UPROPERTY(Transient, NotReplicated, Export)
	TWeakObjectPtr<UInventory> OwningInventory;

};

