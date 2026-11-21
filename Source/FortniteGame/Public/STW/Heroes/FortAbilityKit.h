// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Styling/SlateBrush.h"
#include "Abilities/FortAbilitySet.h"
#include "Items/FortReplenishmentType.h"
#include "UI/FortTooltipInterface.h"
#include "FortAbilityKit.generated.h"

class UFortGadgetItemDefinition;
class UFortItemDefinition;
class UFortSchematicItemDefinition;
class UFortTooltip;
class UFortTooltipDisplayStatsList;
class UObject;

USTRUCT(BlueprintType)
struct FAbilityKitItem
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Items")
	TObjectPtr<UFortItemDefinition> Item;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Items")
	int32 Quantity;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Items")
	TEnumAsByte<EFortReplenishmentType::Type> Replenishment;

};

UCLASS(MinimalAPI, BlueprintType)
class UFortAbilityKit : public UFortAbilitySet, public IFortTooltipInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="Gadgets", meta=(DisplayName="Get Gadgets"))
	void BP_GetGadgets(TArray<UFortGadgetItemDefinition*>& GadgetItemDefinitions);

	UFUNCTION(BlueprintPure, Category="Tooltip", meta=(WorldContext="WorldContextObject"))
	TArray<FText> GetDescription(const UObject* WorldContextObject, bool bFindSummaryTooltip = false) const;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, AssetRegistrySearchable, Category="Display")
	FText DisplayName;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, AssetRegistrySearchable, Category="Display")
	TArray<FText> Description;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, AssetRegistrySearchable, Category="Display")
	FText TooltipDescription;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Display")
	FSlateBrush IconBrush;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Display")
	FSlateBrush PrimaryTraitIconBrushOverride;

	UPROPERTY(EditDefaultsOnly, Category="Gadgets", meta=(AssetBundles="ItemDetails"))
	TArray<TSoftObjectPtr<UFortGadgetItemDefinition>> Gadgets;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Items")
	TArray<FAbilityKitItem> Items;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Schematics")
	TArray<TObjectPtr<UFortSchematicItemDefinition>> AddedSchematics;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Schematics")
	TArray<TObjectPtr<UFortSchematicItemDefinition>> RemovedSchematics;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Tooltip")
	TSubclassOf<UFortTooltip> Tooltip;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Tooltip")
	TSubclassOf<UFortTooltip> SummaryTooltip;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Tooltips")
	TObjectPtr<UFortTooltipDisplayStatsList> StatList;

};

