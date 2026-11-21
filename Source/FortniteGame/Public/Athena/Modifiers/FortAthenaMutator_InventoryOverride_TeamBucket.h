// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "ScalableFloat.h"
#include "Athena/Modifiers/FortAthenaMutator_InventoryOverride.h"
#include "FortCustomBodyTypeEnum.h"
#include "FortGender.h"
#include "FortAthenaMutator_InventoryOverride_TeamBucket.generated.h"

class UCustomCharacterPart;

USTRUCT(BlueprintType)
struct FTeamBucketPartOverrideData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="TeamBucketPartOverrideData")
	TEnumAsByte<EFortCustomGender::Type> Gender;

	UPROPERTY(EditDefaultsOnly, Category="TeamBucketPartOverrideData")
	TEnumAsByte<EFortCustomBodyType::Type> BodyType;

	UPROPERTY(EditDefaultsOnly, Category="TeamBucketPartOverrideData")
	TArray<TObjectPtr<UCustomCharacterPart>> PartsToSwapIn;

	UPROPERTY(EditDefaultsOnly, Category="TeamBucketPartOverrideData")
	bool bShouldRemoveExtras;

	UPROPERTY(EditDefaultsOnly, Category="TeamBucketPartOverrideData")
	TArray<TObjectPtr<UCustomCharacterPart>> PartsToAddIfSpecialTags;

	UPROPERTY(EditDefaultsOnly, Category="TeamBucketPartOverrideData")
	FGameplayTag CosmeticSwapTag;

};

USTRUCT(BlueprintType)
struct FTeamBucketCosmeticLoadoutContainer
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="TeamBucketCosmeticLoadoutContainer")
	FScalableFloat bEnabled;

	UPROPERTY(EditDefaultsOnly, Category="TeamBucketCosmeticLoadoutContainer")
	FGameplayTagContainer SkinMetaTagsToSkip;

	UPROPERTY(EditDefaultsOnly, Category="TeamBucketCosmeticLoadoutContainer")
	TArray<TObjectPtr<UCustomCharacterPart>> PartsToSwapInToRemoveExtras;

	UPROPERTY(EditDefaultsOnly, Category="TeamBucketCosmeticLoadoutContainer")
	FGameplayTagContainer SpecialTags;

	UPROPERTY(EditDefaultsOnly, Category="TeamBucketCosmeticLoadoutContainer")
	FGameplayTagContainer ExtraSpecialTags;

	UPROPERTY(EditDefaultsOnly, Category="TeamBucketCosmeticLoadoutContainer")
	TArray<FTeamBucketPartOverrideData> PartOverrides;

};

USTRUCT(BlueprintType)
struct FTeamBucketLoadout
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="TeamBucketLoadout")
	FTeamBucketCosmeticLoadoutContainer CosmeticLoadout;

	UPROPERTY(EditDefaultsOnly, Category="TeamBucketLoadout")
	FItemLoadoutContainer ItemLoadout;

};

USTRUCT(BlueprintType)
struct FTeamBucketDefinition
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="TeamBucketDefinition")
	FScalableFloat bEnabled;

	UPROPERTY(EditDefaultsOnly, Category="TeamBucketDefinition")
	TArray<FTeamBucketLoadout> Loadouts;

};

UCLASS(BlueprintType, HideCategories=("Tick", "Replication", "Actor", "LOD", "Cooking", "Mutator", "Inventory", "FortAthenaMutator", "Activation", "Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AFortAthenaMutator_InventoryOverride_TeamBucket : public AFortAthenaMutator_InventoryOverride
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Category="Team Buckets")
	TArray<FTeamBucketDefinition> TeamBuckets;

};

