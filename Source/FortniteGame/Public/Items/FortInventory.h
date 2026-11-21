// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Net/Serialization/FastArraySerializer.h"
#include "FortInventoryType.h"
#include "Items/FortInventoryInterface.h"
#include "Items/FortItemEntry.h"
#include "FortInventory.generated.h"

class AFortPawn;
class UFortItem;
class UFortWorldItem;

USTRUCT()
struct FFortItemList : public FFastArraySerializer
{
	GENERATED_BODY()

public:
	UPROPERTY(SaveGame)
	TArray<FFortItemEntry> ReplicatedEntries;

	UPROPERTY(NotReplicated)
	TArray<TObjectPtr<UFortWorldItem>> ItemInstances;

};

UCLASS(MinimalAPI)
class AFortInventory : public AActor, public IFortInventoryInterface
{
	GENERATED_BODY()

public:
	UFUNCTION()
	void HandleInventoryLocalUpdate();

protected:
	UPROPERTY()
	TArray<TObjectPtr<UFortItem>> RecentlyAdded;

	UPROPERTY()
	TArray<TObjectPtr<UFortItem>> RecentlyRemoved;

	UPROPERTY()
	TArray<TObjectPtr<UFortItem>> RecentlyChanged;

private:
	UPROPERTY(Replicated)
	TEnumAsByte<EFortInventoryType::Type> InventoryType;

	UPROPERTY(SaveGame, ReplicatedUsing=HandleInventoryLocalUpdate)
	FFortItemList Inventory;

	UPROPERTY()
	TArray<TObjectPtr<UFortWorldItem>> PendingExistingItems;

	UPROPERTY(Replicated)
	TWeakObjectPtr<AFortPawn> ReplayPawn;

	UPROPERTY()
	bool bRequiresLocalUpdate;

	UPROPERTY()
	bool bRequiresSaving;

	UPROPERTY()
	bool bIsShuttingDown;

	UPROPERTY()
	TArray<TObjectPtr<UFortWorldItem>> PendingInstances;

};

