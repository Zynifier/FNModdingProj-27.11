// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "GameplayTagContainer.h"
#include "GameDataCosmeticGating.generated.h"

class UCosmeticsGatingRule;
class UFortCosmeticRestrictionData;

USTRUCT(BlueprintType)
struct FAgeRatingIdsToGatingRuleGameplayTags
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="AgeRatingIdsToGatingRuleGameplayTags")
	TSet<FString> AgeRatingIds;

	UPROPERTY(EditDefaultsOnly, Category="AgeRatingIdsToGatingRuleGameplayTags")
	FGameplayTagContainer GatingRuleGameplayTags;

};

USTRUCT()
struct FCosmeticGatingCondition
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="Cosmetic Gating")
	FGameplayTagQuery AgeRatingQuery;

};

USTRUCT()
struct FCosmeticGatingRuleData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="Cosmetic Gating")
	FCosmeticGatingCondition GatingCondition;

	UPROPERTY(EditDefaultsOnly, Category="Cosmetic Gating", meta=(AssetBundles="Client,Server"))
	TSoftObjectPtr<UCosmeticsGatingRule> GatingRule;

};

USTRUCT(BlueprintType)
struct FExperiencesRatingsIdsList
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="ExperiencesRatingsIdsList")
	TArray<FString> Data;

};

USTRUCT(BlueprintType)
struct FGameplayTagToAgeRatingId
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="GameplayTagToAgeRatingId")
	TMap<FGameplayTag, FString> Data;

};

UCLASS(MinimalAPI)
class UGameDataCosmeticGating : public UPrimaryDataAsset
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="CharacterCustomization")
	TObjectPtr<UFortCosmeticRestrictionData> CosmeticRestrictionData;

	UPROPERTY(EditAnywhere, Category="AgeRating")
	FGameplayTagQuery CosmeticAgeRestrictedQuery;

	UPROPERTY(EditDefaultsOnly, Category="AgeRating")
	FGameplayTagContainer CosmeticsGatingRatingMinTags;

	UPROPERTY(EditDefaultsOnly, Category="AgeRating")
	TMap<FString, FGameplayTagToAgeRatingId> RatingBoardToGameplayTagTable;

	UPROPERTY(EditDefaultsOnly, Category="AgeRating")
	TArray<FAgeRatingIdsToGatingRuleGameplayTags> AgeRatingIDsToRuleGameplayTagsTable;

	UPROPERTY(EditAnywhere, Category="AgeRating")
	TArray<FCosmeticGatingRuleData> CosmeticGatingRuleDataTable;

	UPROPERTY(EditDefaultsOnly, Category="AgeRating")
	TMap<FString, FExperiencesRatingsIdsList> RatingBoardToExperiencesRatingsTable;

	UPROPERTY(EditDefaultsOnly, Category="GameDataCosmeticGating")
	TSet<FString> AgeRatingIDs;

};

