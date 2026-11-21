// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/AI/FortAthenaAISpawnerDataComponent_InventoryBase.h"
#include "FortItemAndCount.h"
#include "FortAthenaAISpawnerDataComponent_AIBotInventory.generated.h"

UCLASS()
class UFortAthenaAISpawnerDataComponent_AIBotInventory : public UFortAthenaAISpawnerDataComponent_InventoryBase
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly, Category="Inventory")
	uint8 bItemsToGiveInEditorWhenCustomizationIsEnabled : 1;

	UPROPERTY(EditDefaultsOnly, Category="Inventory", meta=(AllowPrivateAccess="true"))
	TArray<FItemAndCount> EditorOnlyItems;

};

