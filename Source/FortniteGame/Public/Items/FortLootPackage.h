// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "GameplayTagContainer.h"
#include "FortLootPackage.generated.h"

class UFortItemDefinition;

USTRUCT(BlueprintType)
struct FFortLootPackageData : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="LootPackage")
	FName LootPackageID;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="LootPackage")
	int32 LootPackageCategory;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="LootPackage", meta=(DataTableImportOptional))
	FGameplayTagContainer GameplayTags;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="LootPackage")
	FName RequiredTag;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="LootPackage")
	FString LootPackageCall;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="LootPackage")
	TSoftObjectPtr<UFortItemDefinition> ItemDefinition;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="LootPackage")
	FString PersistentLevel;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="LootPackage")
	int32 MinWorldLevel;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="LootPackage")
	int32 MaxWorldLevel;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="LootPackage")
	bool bAllowBonusDrops;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="LootPackage")
	FString Annotation;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="LootPackage")
	float Weight;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="LootPackage")
	FName NamedWeightMult;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="LootPackage", meta=(DataTableImportOptional))
	TArray<FName> PotentialNamedWeights;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="LootPackage")
	int32 Count;

};

