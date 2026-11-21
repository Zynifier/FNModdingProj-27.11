// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Misc/Guid.h"
#include "UObject/NoExportTypes.h"
#include "ItemComponentStorage.generated.h"

class UItemComponentLocalStorage;
class UObject;

/** Storage for one component class type. */
USTRUCT()
struct FItemEntryStorageMap
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	TMap<FGuid, UItemComponentLocalStorage*> ItemToStorageMap;

};

/** Use this as the base class for any item component-specific storage that is needed. **/
UCLASS(Abstract, Transient)
class ITEMIZATIONCORERUNTIME_API UItemComponentLocalStorage : public UObject
{
	GENERATED_BODY()

};

/** This class handles the lifetime management of any component-specific storage.
*	All storage is TRANSIENT and NOT REPLICATED. It is intended for storing runtime
*	handles, working data and other temporary state.
*
*	Example usage for a new component type ItemComponentType_Foo:
*	class UItemComponentStorage_Foo : public UItemComponentLocalStorage
*	{
*		// ... properties needed by Foo
*	}
* 
*	Inside ItemComponentyType_Foo:
*	UItemComponentStorage_Foo* FooStorage = FindOrCreateLocalStorage<UItemComponentStorage_Foo>(ItemEntryID, OwningInventory);
* 
*	Storage will be automatically freed up if the item leaves the inventory.
* 
**/
UCLASS(Transient)
class ITEMIZATIONCORERUNTIME_API UItemComponentStorageManager : public UObject
{
	GENERATED_BODY()

private:
	UPROPERTY(Transient)
	TMap<UClass*, FItemEntryStorageMap> ClassLookupMap;

};

