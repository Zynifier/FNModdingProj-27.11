// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "InventoryComponent.generated.h"

class AInventoryCollection;
class UInventoryDefinition;
class UItemDefinitionBase;

UCLASS(BlueprintType)
class ITEMIZATIONCORERUNTIME_API UInventoryComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	/** Adds an item to this inventory collection. Priority properties on the inventories within the collection decide which particular inventory it enters. */
	UFUNCTION(BlueprintCallable, Category="Inventory")
	void AddItem(UItemDefinitionBase* ItemDefinition, int32 Amount = 1);

	/** Adds an inventory of this type. If one already exists, it is reset to its starting state. */
	UFUNCTION(BlueprintCallable, Category="Inventory")
	void AddOrResetInventory(UInventoryDefinition* NewInventoryDefinition);

	/** Returns a VkInventoryCollection linked to this component, if one exists. */
	UFUNCTION(BlueprintPure, Category="Inventory")
	AInventoryCollection* GetInventoryCollection() const;

	/** All definitions in this list will be automatically created when the component is initialised. Only one inventory per definition is allowed. */
	UPROPERTY(EditAnywhere, Category="Inventory")
	TArray<TSoftObjectPtr<UInventoryDefinition>> InventoryDefinitions;

private:
	UPROPERTY(Replicated)
	TWeakObjectPtr<AInventoryCollection> InventoryCollection;

};

