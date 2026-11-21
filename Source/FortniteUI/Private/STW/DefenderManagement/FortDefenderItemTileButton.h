// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ItemTiles/FortItemTileButton.h"
#include "FortDefenderItemTileButton.generated.h"

UCLASS(Abstract, BlueprintType, Blueprintable)
class UFortDefenderItemTileButton : public UFortItemTileButton
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent, Category="Defenders|Item Tile")
	void HandleEquipSlotChanged(int32 EquipSlot);

};

