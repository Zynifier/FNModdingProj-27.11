// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Verbs/VerbMessage.h"
#include "FortVerbMessage_Craft.generated.h"

USTRUCT()
struct FFortIngredientCountPair
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FGameplayTagContainer IngredientTags;

	UPROPERTY()
	int32 IngredientCount;

};

USTRUCT(BlueprintType)
struct FFortVerbMessage_Craft : public FVerbMessage
{
	GENERATED_BODY()

private:
	UPROPERTY(VisibleAnywhere, Category="FortVerbMessage_Craft")
	FSubjectTagsPair ItemCrafted;

	UPROPERTY(VisibleAnywhere, Category="FortVerbMessage_Craft")
	FGameplayTagContainer CraftingFormula;

	UPROPERTY(VisibleAnywhere, Category="FortVerbMessage_Craft")
	TArray<FFortIngredientCountPair> CraftingIngredients;

	UPROPERTY(VisibleAnywhere, Category="FortVerbMessage_Craft")
	int32 ItemCount;

};

