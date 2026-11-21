// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "GameplayTagContainer.h"
#include "Items/FortLootQuotaData.h"
#include "FortLootTier.generated.h"

USTRUCT(BlueprintType)
struct FFortLootTierData : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="LootTier")
	FName TierGroup;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="LootTier")
	TEnumAsByte<ELootQuotaLevel::Type> QuotaLevel;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="LootTier")
	int32 LootTier;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="LootTier")
	int32 MinWorldLevel;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="LootTier")
	int32 MaxWorldLevel;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="LootTier")
	FString StreakBreakerCurrency;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="LootTier")
	int32 StreakBreakerPointsMin;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="LootTier")
	int32 StreakBreakerPointsMax;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="LootTier")
	int32 StreakBreakerPointsSpend;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="LootTier")
	FName LootPackage;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="LootTier")
	FName LootPreviewPackage;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="LootTier")
	float NumLootPackageDrops;

#if WITH_EDITORONLY_DATA
	UPROPERTY(VisibleDefaultsOnly, Category="LootTier")
	FString LootPackageCategoryWeight;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(VisibleDefaultsOnly, Category="LootTier")
	FString LootPackageCategoryMin;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(VisibleDefaultsOnly, Category="LootTier")
	FString LootPackageCategoryMax;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="LootTier")
	FName RequiredTag;
#endif

	UPROPERTY(EditAnywhere, BlueprintReadOnly, EditFixedSize, Category="LootTier", meta=(DataTableImportOptional))
	TArray<int32> LootPackageCategoryWeightArray;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, EditFixedSize, Category="LootTier", meta=(DataTableImportOptional))
	TArray<int32> LootPackageCategoryMinArray;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, EditFixedSize, Category="LootTier", meta=(DataTableImportOptional))
	TArray<int32> LootPackageCategoryMaxArray;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="LootPackage", meta=(DataTableImportOptional))
	FGameplayTagContainer GameplayTags;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="LootTier", meta=(DataTableImportOptional))
	FGameplayTagContainer RequiredGameplayTags;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="LootTier")
	bool bAllowBonusLootDrops;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="LootTier")
	FString Annotation;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="LootTier")
	float Weight;

};

