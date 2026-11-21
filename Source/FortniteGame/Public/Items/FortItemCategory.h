// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "GameplayTagContainer.h"
#include "FortMultiSize.h"
#include "Items/FortItemTypeEnum.h"
#include "FortItemCategory.generated.h"

USTRUCT()
struct FItemCategory
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="ItemCategory")
	FGameplayTagContainer TagContainer;

	UPROPERTY(EditAnywhere, Category="ItemCategory")
	FText CategoryName;

	UPROPERTY(EditAnywhere, Category="ItemCategory")
	FFortMultiSizeBrush CategoryBrush;

};

USTRUCT()
struct FItemCategoryMappingData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="ItemCategory")
	EFortItemType CategoryType;

	UPROPERTY(EditAnywhere, Category="ItemCategory")
	FText CategoryName;

};

UCLASS()
class UFortItemCategory : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="ItemCategory", meta=(TitleProperty="CategoryName"))
	TArray<FItemCategoryMappingData> PrimaryCategories;

	UPROPERTY(EditAnywhere, Category="ItemCategory", meta=(TitleProperty="CategoryName"))
	TArray<FItemCategory> SecondaryCategories;

	UPROPERTY(EditAnywhere, Category="ItemCategory", meta=(TitleProperty="CategoryName"))
	TArray<FItemCategory> TertiaryCategories;

};

