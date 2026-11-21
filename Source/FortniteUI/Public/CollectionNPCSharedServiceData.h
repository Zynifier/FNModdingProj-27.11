// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Engine/DataTable.h"
#include "GameplayTagContainer.h"
#include "CollectionNPCSharedServiceData.generated.h"

class UCurveTable;
class UDataTable;
class UObject;

USTRUCT(BlueprintType)
struct FNPCServiceData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="NPCServiceData")
	FText Name;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="NPCServiceData")
	TSoftObjectPtr<UObject> Icon;

};

USTRUCT(BlueprintType)
struct FNPCServiceDataRow : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="NPCServiceDataRow")
	FGameplayTagContainer ServiceTags;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="NPCServiceDataRow")
	FName PricingKey;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="NPCServiceDataRow")
	FNPCServiceData ServiceData;

};

USTRUCT(BlueprintType)
struct FNPCSpecializationDataRow : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="NPCSpecializationDataRow")
	FName PricingKey;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="NPCSpecializationDataRow")
	FNPCServiceData ServiceData;

};

UCLASS(BlueprintType)
class UCollectionScreenServiceVisualData : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="CollectionScreenServiceVisualData")
	TObjectPtr<UDataTable> ServiceDataTable;

	UPROPERTY(EditDefaultsOnly, Category="CollectionScreenServiceVisualData")
	TObjectPtr<UDataTable> SpecializationDataTable;

	UPROPERTY(EditDefaultsOnly, Category="CollectionScreenServiceVisualData")
	FGameplayTag SeasonDataTableServicesTag;

	UPROPERTY(EditDefaultsOnly, Category="CollectionScreenServiceVisualData")
	FGameplayTag SeasonDataTableSalesTag;

	UPROPERTY(EditDefaultsOnly, Category="CollectionScreenServiceVisualData")
	FGameplayTag NpcPricingKeyRemapsTag;

	UPROPERTY(EditDefaultsOnly, Category="CollectionScreenServiceVisualData")
	TObjectPtr<UCurveTable> ItemCostTable;

	UPROPERTY(EditDefaultsOnly, Category="CollectionScreenServiceVisualData")
	TObjectPtr<UCurveTable> ServiceCostTable;

	UPROPERTY(EditDefaultsOnly, Category="CollectionScreenServiceVisualData")
	FGameplayTagContainer AllowedServiceTagsForIcon;

	UPROPERTY(EditDefaultsOnly, Category="CollectionScreenServiceVisualData")
	FGameplayTag SpecializationTagRoot;

	UPROPERTY(EditDefaultsOnly, Category="CollectionScreenServiceVisualData")
	FText ItemNameAndCountFmt;

	UPROPERTY(EditDefaultsOnly, Category="CollectionScreenServiceVisualData")
	TArray<FGameplayTag> SellServiceTagOrdered;

};

