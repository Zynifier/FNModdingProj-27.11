// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "Engine/DataAsset.h"
#include "GameplayTagContainer.h"
#include "FortAttributeCategory.generated.h"

USTRUCT(BlueprintType)
struct FMyFortCategoryData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AttributeData")
	FText CategoryName;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AttributeData", meta=(Categories="Tooltip.PlayerInfo"))
	FGameplayTag TooltipTag;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AttributeData")
	FGameplayTagContainer ModifiedTagContainer;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AttributeData")
	bool bIsCore;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AttributeData")
	TArray<FGameplayAttribute> Attributes;

};

UCLASS()
class UFortAttributeCategory : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AttributeData")
	TArray<FMyFortCategoryData> Categories;

};

