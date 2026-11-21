// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "PrototypeRecipeDataAsset.generated.h"

class UFortWorldItemDefinition;

USTRUCT(BlueprintType)
struct FPrototypeCraftingIngredient
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="PrototypeCraftingIngredient")
	TObjectPtr<UFortWorldItemDefinition> Ingredient;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="PrototypeCraftingIngredient")
	int32 Quantity;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="PrototypeCraftingIngredient")
	float ConsumptionChance;

};

USTRUCT(BlueprintType)
struct FPrototypeCraftingOutput
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="PrototypeCraftingOutput")
	TObjectPtr<UFortWorldItemDefinition> Item;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="PrototypeCraftingOutput")
	int32 Quantity;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="PrototypeCraftingOutput")
	float CreationChance;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="PrototypeCraftingOutput")
	bool bIsUnique;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="PrototypeCraftingOutput")
	bool bIsFailure;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="PrototypeCraftingOutput")
	float UtilityFloat;

};

UCLASS(BlueprintType, Blueprintable)
class FORTNITEGAME_API UPrototypeRecipeDataAsset : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	int32 GetCraftingDuration();

	UFUNCTION(BlueprintCallable)
	bool GetHiddenByDefault();

	UFUNCTION(BlueprintCallable)
	TArray<FPrototypeCraftingIngredient> GetInputs();

	UFUNCTION(BlueprintCallable)
	int32 GetMaxNumberOfOutputs();

	UFUNCTION(BlueprintCallable)
	TArray<FPrototypeCraftingOutput> GetOutputs();

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="PrototypeRecipeDataAsset")
	float CraftingDuration;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="PrototypeRecipeDataAsset")
	int32 NumberOfOutputs;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="PrototypeRecipeDataAsset")
	bool bHiddenByDefault;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="PrototypeRecipeDataAsset")
	TArray<FPrototypeCraftingIngredient> Inputs;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="PrototypeRecipeDataAsset")
	TArray<FPrototypeCraftingOutput> Outputs;

};

