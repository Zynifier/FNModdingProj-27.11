// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Building/BuildingItemCollectorActor.h"
#include "FortTypes.h"
#include "BuildingPhoenixItemCollectorActor.generated.h"

class UFortItemDefinition;
enum class EFortRarity : uint8;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOutputItemChanged);

UCLASS(BlueprintType, Blueprintable, HideCategories=("Game|Damage"), SparseClassDataType=BuildingGameplayActorClassData)
class ABuildingPhoenixItemCollectorActor : public ABuildingItemCollectorActor
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	bool GetActiveOutputRecipe(FRecipe& OutRecipe) const;

	UFUNCTION(BlueprintPure)
	int32 GetOutputRewardLevel() const;

	UFUNCTION(BlueprintPure)
	EFortRarity GetOutputRewardRarity() const;

	UPROPERTY(EditDefaultsOnly, Category="Phoenix Collector")
	TArray<TObjectPtr<UFortItemDefinition>> ResourceWhitelist;

	UPROPERTY(EditAnywhere, Category="Phoenix Collector")
	int32 VendingTier;

	UPROPERTY(BlueprintAssignable)
	FOutputItemChanged OnOutputItemChanged;

private:
	UPROPERTY(Replicated)
	TArray<FRecipe> OutputItemRecipes;

};

