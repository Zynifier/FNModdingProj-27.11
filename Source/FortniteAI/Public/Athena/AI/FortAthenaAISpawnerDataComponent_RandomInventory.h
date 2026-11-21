// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ScalableFloat.h"
#include "Athena/AI/FortAthenaAISpawnerDataComponent_InventoryBase.h"
#include "FortItemAndCount.h"
#include "FortAthenaAISpawnerDataComponent_RandomInventory.generated.h"

USTRUCT()
struct FWeightedAIInventoryLoadout
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="WeightedAIInventoryLoadout")
	FScalableFloat Weight;

	UPROPERTY(EditDefaultsOnly, Category="WeightedAIInventoryLoadout")
	TArray<FItemAndCount> Items;

};

UCLASS()
class UFortAthenaAISpawnerDataComponent_RandomInventory : public UFortAthenaAISpawnerDataComponent_InventoryBase
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly, Category="Inventory", meta=(AllowPrivateAccess="true"))
	TArray<FWeightedAIInventoryLoadout> Loadouts;

};

