// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "FortRarityEnum.h"
#include "FortReleaseVersion.h"
#include "FortQaConvertCsvToDataTable_Structs.generated.h"

USTRUCT(BlueprintType)
struct FCcaCsvCosmeticPropertiesData : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="CosmeticPropertiesData")
	FString ReleaseVersion;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="CosmeticPropertiesData", meta=(DataTableImportOptional))
	FFortReleaseVersion FortReleaseVersion;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="CosmeticPropertiesData")
	FString AssetType;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="CosmeticPropertiesData")
	FString PlayerFacingDisplayName;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="CosmeticPropertiesData")
	FString PlayerFacingDescription;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="CosmeticPropertiesData")
	FString PlayerFacingSetName;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="CosmeticPropertiesData")
	FString CosmeticSeries;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="CosmeticPropertiesData")
	FString CosmeticAgeRating;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="CosmeticPropertiesData")
	FString RarityLevel;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="CosmeticPropertiesData", meta=(DataTableImportOptional))
	EFortRarity RarityLevelEnum;

};

