// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/CheatManager.h"
#include "InventoryCheatManager.generated.h"

/** Allows manipulation and debugging of VkInventory via console commands. */
UCLASS(MinimalAPI)
class UInventoryCheatManager : public UCheatManagerExtension
{
	GENERATED_BODY()

public:
	UFUNCTION(Exec)
	void InventoryAddToItem(int32 InventoryIndex, int32 ItemIndex, int32 AmountToAdd);

	UFUNCTION(Exec)
	void InventoryMoveItem(int32 SourceInventoryIndex, int32 ItemIndex, int32 TargetInventoryIndex);

	UFUNCTION(Exec)
	void InventoryRemoveFromItem(int32 InventoryIndex, int32 ItemIndex, int32 AmountToRemove);

};

