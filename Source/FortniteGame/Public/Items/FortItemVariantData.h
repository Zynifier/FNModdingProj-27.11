// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "GameplayTagContainer.h"
#include "ScalableFloat.h"
#include "FortItemVariantData.generated.h"

class UFortItemVariantData;
class UMaterialInterface;

USTRUCT()
struct FFortVariantData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="FortVariantData")
	FText VariantName;

	UPROPERTY(EditDefaultsOnly, Category="FortVariantData")
	TArray<TSoftObjectPtr<UMaterialInterface>> OverrideMaterials;

	UPROPERTY(EditDefaultsOnly, Category="FortVariantData")
	FScalableFloat Weight;

	UPROPERTY(EditDefaultsOnly, Category="FortVariantData", meta=(Categories="Item"))
	FGameplayTag ItemFilterTag;

	UPROPERTY(EditDefaultsOnly, Category="FortVariantData")
	FGameplayTag CollectionTag;

	UPROPERTY(EditDefaultsOnly, Category="FortVariantData", meta=(Categories="Analytics"))
	FGameplayTag AnalyticsTag;

	UPROPERTY(EditDefaultsOnly, Category="FortVariantData", meta=(Categories="Athena.Location"))
	FGameplayTagContainer POITags;

	UPROPERTY(EditDefaultsOnly, Category="FortVariantData", meta=(Categories="TimeOfDay"))
	FGameplayTagContainer TODTags;

	UPROPERTY(EditDefaultsOnly, Category="FortVariantData")
	FGameplayTagContainer RequiredTags;

};

USTRUCT()
struct FItemDefToItemVariantDataMapping
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Category="ItemDefToItemVariantDataMapping")
	FGameplayTagContainer ItemDefinitionTags;

	UPROPERTY(EditDefaultsOnly, Category="ItemDefToItemVariantDataMapping")
	TObjectPtr<UFortItemVariantData> ItemVariantData;

	UPROPERTY(EditDefaultsOnly, Category="ItemDefToItemVariantDataMapping")
	FGameplayTag ItemVariantTag;

};

UCLASS()
class UFortItemDefToItemVariantDataMapping : public UDataAsset
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly, Category="Pickup Visuals")
	TArray<FItemDefToItemVariantDataMapping> ItemDefToItemVariantDataMappings;

};

UCLASS()
class UFortItemVariantData : public UDataAsset
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Category="Variant Data", meta=(TitleProperty="VariantName"))
	TArray<FFortVariantData> Variants;

};

