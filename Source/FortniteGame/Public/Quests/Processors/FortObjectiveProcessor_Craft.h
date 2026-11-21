// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Quests/Processors/EventProcessorTypes.h"
#include "Quests/Processors/ObjectiveProcessor.h"
#include "FortObjectiveProcessor_Craft.generated.h"

UENUM(BlueprintType)
enum class EFortCraftObjectiveIncrementType : uint8
{
	// Increment the objective by 1 every time this filter is matched

	Single = 0,
	/* Increment the objective by the number of matching ingredients used
	 * Note: If you have multiple ingredient filters it will add to the count for all matching ingredients used.
	 */
	MatchingIngredientCount = 1,
	// Increment the object by the stack size of the crafted item

	ItemCount = 2,
};

USTRUCT(BlueprintType)
struct FFortObjective_IngredientFilter
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="FortObjective_IngredientFilter")
	FGameplayTagQuery IngredientTags;

	UPROPERTY(EditAnywhere, Category="FortObjective_IngredientFilter", meta=(InlineEditConditionToggle))
	uint8 bUseIngredientCount : 1;

	UPROPERTY(EditAnywhere, Category="FortObjective_IngredientFilter", meta=(EditCondition="bUseIngredientCount", UIMin="0"))
	FInt32Range IngredientCount;

};

USTRUCT(meta=(DisplayName="Craft"))
struct FFortObjectiveFilter_Craft : public FObjectiveFilter
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="FortObjectiveFilter_Craft", meta=(DisplayPriority="-1"))
	EFortCraftObjectiveIncrementType IncrementBy;

	UPROPERTY(EditAnywhere, Category="FortObjectiveFilter_Craft")
	FObjectiveSubjectTags ItemCrafted;

	UPROPERTY(EditAnywhere, Category="FortObjectiveFilter_Craft")
	FObjectiveSubjectTags CraftedFormula;

	UPROPERTY(EditAnywhere, Category="FortObjectiveFilter_Craft")
	TArray<FFortObjective_IngredientFilter> CraftedIngredients;

	UPROPERTY(EditAnywhere, Category="FortObjectiveFilter_Craft")
	bool bUseItemCount;

	UPROPERTY(EditAnywhere, Category="FortObjectiveFilter_Craft", meta=(EditCondition="bUseItemCount", UIMin="0"))
	FInt32Range ItemCount;

};

UCLASS()
class UFortObjectiveProcessor_Craft : public UObjectiveProcessor
{
	GENERATED_BODY()

};

