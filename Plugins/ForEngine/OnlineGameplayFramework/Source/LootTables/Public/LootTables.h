// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Engine/DataTable.h"
#include "ExcelImportUtil.h"
#include "LootTables.generated.h"

class UDataTable;
class ULootTables;

USTRUCT()
struct LOOTTABLES_API FLootPackageRow : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="LootPackage")
	FString LootPackageID;

	UPROPERTY(EditAnywhere, Category="LootPackage")
	float Weight;

	UPROPERTY(EditAnywhere, Category="LootPackage")
	FString NamedWeightMult;

	UPROPERTY(EditAnywhere, Category="LootPackage")
	int32 MinCount;

	UPROPERTY(EditAnywhere, Category="LootPackage")
	int32 MaxCount;

	UPROPERTY(EditAnywhere, Category="LootPackage")
	int32 LootPackageCategory;

	UPROPERTY(EditAnywhere, Category="LootPackage")
	FString LootPackageCall;

	UPROPERTY(EditAnywhere, Category="LootPackage")
	FString ItemDefinition;

	UPROPERTY(EditAnywhere, Category="LootPackage")
	FString ItemAttributesJson;

	UPROPERTY(EditAnywhere, Category="LootPackage")
	int32 MinWorldLevel;

	UPROPERTY(EditAnywhere, Category="LootPackage")
	int32 MaxWorldLevel;

	UPROPERTY(EditAnywhere, Category="LootPackage")
	FString RequiredTag;

	UPROPERTY(EditAnywhere, Category="LootPackage")
	FString Annotation;

	UPROPERTY(EditAnywhere, Category="LootPackage")
	bool bPreventDuplicateRowSelection;

};

USTRUCT()
struct LOOTTABLES_API FLootTierDataRow : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="LootTier")
	FString TierGroup;

	UPROPERTY(EditAnywhere, Category="LootTier")
	float Weight;

	UPROPERTY(EditAnywhere, Category="LootTier")
	int32 LootTier;

	UPROPERTY(EditAnywhere, Category="LootTier")
	int32 MinWorldLevel;

	UPROPERTY(EditAnywhere, Category="LootTier")
	int32 MaxWorldLevel;

	UPROPERTY(EditAnywhere, Category="LootPackage")
	FString RequiredTag;

	UPROPERTY(EditAnywhere, Category="LootTier")
	FString StreakBreakerCurrency;

	UPROPERTY(EditAnywhere, Category="LootTier")
	int32 StreakBreakerPointsMin;

	UPROPERTY(EditAnywhere, Category="LootTier")
	int32 StreakBreakerPointsMax;

	UPROPERTY(EditAnywhere, Category="LootTier")
	int32 StreakBreakerPointsSpend;

	UPROPERTY(EditAnywhere, Category="LootTier")
	FString LootPackage;

	UPROPERTY(EditAnywhere, Category="LootTier")
	float NumLootPackageDrops;

	UPROPERTY(EditAnywhere, Category="LootTier")
	FString LootPackageCategoryWeight;

	UPROPERTY(EditAnywhere, Category="LootTier")
	FString LootPackageCategoryMin;

	UPROPERTY(EditAnywhere, Category="LootTier")
	FString LootPackageCategoryMax;

	UPROPERTY(EditAnywhere, Category="LootTier")
	FString Annotation;

	UPROPERTY(EditAnywhere, Category="LootTier")
	FString GlobalNamedWeightCategory;

	UPROPERTY(EditAnywhere, Category="LootTier")
	bool bPreventDuplicateRowSelection;

};

USTRUCT()
struct LOOTTABLES_API FLootTableSource
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="LootTableSource")
	FString SourceName;

	UPROPERTY(EditAnywhere, Category="LootTableSource")
	FExcelImportUtil ExcelImport;

	UPROPERTY(EditAnywhere, Category="LootTableSource")
	TObjectPtr<UDataTable> LootTierData;

	UPROPERTY(EditAnywhere, Category="LootTableSource")
	TObjectPtr<UDataTable> LootPackages;

	UPROPERTY(VisibleAnywhere, Category="LootTableSource", meta=(TitleProperty="TierGroup"))
	TArray<FLootTierDataRow> LootTierRows;

	UPROPERTY(VisibleAnywhere, Category="LootTableSource", meta=(TitleProperty="LootPackageID"))
	TArray<FLootPackageRow> LootPackageRows;

	UPROPERTY(Transient)
	TObjectPtr<ULootTables> Parent;

};

UCLASS()
class LOOTTABLES_API ULootTables : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="LootTables", meta=(TitleProperty="SourceName"))
	TArray<FLootTableSource> Sources;

};

