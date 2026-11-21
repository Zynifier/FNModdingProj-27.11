// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "GameplayTagContainer.h"
#include "FortAIGoalSelectionCriteria.generated.h"

class UEnvQuery;

UENUM(BlueprintType)
namespace ETagGoalScoringCategory
{
	enum Type
	{
		Ignore = 0,
		// 		LowInterest,
// 		MediumInterest,

		HighInterest = 1,
		NumCategories = 2 UMETA(Hidden),
	};
}

USTRUCT()
struct FGoalSelectionCriteria
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="GoalSelection", meta=(AssetBundles="Server", ShowOnlyInnerProperties))
	TSoftObjectPtr<UEnvQuery> GoalSelectionQuery;

};

USTRUCT()
struct FEncounterGoalSelectionTableEntry
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="GoalSelection")
	FGameplayTagContainer RequiredGameplayTags;

	UPROPERTY(EditAnywhere, Category="GoalSelection", meta=(ShowOnlyInnerProperties))
	FGoalSelectionCriteria GoalSelectionCriteria;

};

USTRUCT()
struct FPawnGoalSelectionCriteria
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="GoalSelection")
	FGameplayTagContainer IncludeEnemiesWithTags;

	UPROPERTY(EditAnywhere, Category="GoalSelection")
	FGameplayTagContainer ExcludeEnemiesWithTags;

	UPROPERTY(EditAnywhere, Category="GoalSelection", meta=(ShowOnlyInnerProperties))
	TArray<FGoalSelectionCriteria> GoalSelectionCriteria;

};

USTRUCT()
struct FPawnGoalSelectionTableEntry
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="GoalSelection")
	FGameplayTagContainer RequiredGameplayTags;

	UPROPERTY(EditAnywhere, Category="GoalSelection", meta=(ShowOnlyInnerProperties))
	FPawnGoalSelectionCriteria PawnGoalSelectionCriteria;

};

UCLASS(BlueprintType)
class UFortAIEncounterGoalSelectionTable : public UDataAsset
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, Category="GoalSelection", meta=(ShowOnlyInnerProperties))
	TArray<FEncounterGoalSelectionTableEntry> EncounterGoalSelectionCriteria;

};

