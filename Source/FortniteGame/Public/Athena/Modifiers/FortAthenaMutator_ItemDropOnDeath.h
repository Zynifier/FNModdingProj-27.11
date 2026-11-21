// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ScalableFloat.h"
#include "Athena/Modifiers/FortAthenaMutator.h"
#include "FortAthenaMutator_ItemDropOnDeath.generated.h"

class UFortWorldItemDefinition;

UENUM(BlueprintType)
enum class ERespawnRequirements : uint8
{
	RespawnOnly = 0,
	NoRespawnOnly = 1,
	Both = 2,
};

USTRUCT()
struct FItemsToDropOnDeath
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="ItemsToDropOnDeath")
	TObjectPtr<UFortWorldItemDefinition> ItemToDrop;

	UPROPERTY(EditAnywhere, Category="ItemsToDropOnDeath")
	FScalableFloat NumberToDrop;

};

UCLASS(HideCategories=("Tick", "Replication", "Actor", "LOD", "Cooking", "Mutator", "Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AFortAthenaMutator_ItemDropOnDeath : public AFortAthenaMutator
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Category="Behavior")
	ERespawnRequirements RespawnRequirements;

	UPROPERTY(EditDefaultsOnly, Category="Item Data")
	FScalableFloat PercentAmmoToDrop;

	UPROPERTY(EditDefaultsOnly, Category="Item Data")
	FScalableFloat AmmoDespawnTime;

	UPROPERTY(EditDefaultsOnly, Category="Item Data")
	FScalableFloat AmmoStormDespawnTime;

	UPROPERTY(EditDefaultsOnly, Category="Item Data")
	FScalableFloat MaxAmmoTypeDrops;

	UPROPERTY(EditDefaultsOnly, Category="Item Data")
	FScalableFloat MaxResourceTypeDrops;

	UPROPERTY(EditDefaultsOnly, Category="Item Data")
	TArray<FItemsToDropOnDeath> ItemsToDrop;

	UPROPERTY(EditDefaultsOnly, Category="Bots")
	FScalableFloat ShouldNonParticipantAIAlsoDropItems;

	UPROPERTY(EditDefaultsOnly, Category="Playlist Loot Tier Groups")
	TArray<FName> LootTierGroupsToDrop;

};

