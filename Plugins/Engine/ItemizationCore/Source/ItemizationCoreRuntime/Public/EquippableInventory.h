// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Misc/Guid.h"
#include "Inventory.h"
#include "EquippableInventory.generated.h"

/*
 * Actor component which implements an inventory where the items inside may be equipped.
 */
UCLASS()
class ITEMIZATIONCORERUNTIME_API UEquippableInventory : public UInventory
{
	GENERATED_BODY()

private:
	UFUNCTION()
	void OnRep_EquippedItems();

	UPROPERTY(ReplicatedUsing=OnRep_EquippedItems)
	TArray<FGuid> EquippedItems;

	UPROPERTY(Transient)
	TArray<FGuid> PreviouslyEquippedItems;

};

