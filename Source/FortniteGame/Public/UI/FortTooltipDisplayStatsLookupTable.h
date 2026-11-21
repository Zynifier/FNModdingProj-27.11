// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "Engine/DataAsset.h"
#include "GameplayTagContainer.h"
#include "FortTooltipDisplayStatsLookupTable.generated.h"

class UFortTooltipDisplayStatsList;
class UObject;

USTRUCT(BlueprintType)
struct FFortTooltipDisplayInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortTooltipDisplayInfo")
	TSubclassOf<UObject> PrimaryObjectClass;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortTooltipDisplayInfo")
	TSubclassOf<UObject> SecondaryObjectClass;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortTooltipDisplayInfo")
	FGameplayTagContainer DescriptionStatsTags;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortTooltipDisplayInfo")
	TObjectPtr<UFortTooltipDisplayStatsList> TooltipStatsList;

};

USTRUCT()
struct FFortTooltipDisplayStatInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="FortTooltipDisplayStatInfo", meta=(Categories="Tooltip.Token"))
	FGameplayTag Token;

	UPROPERTY(EditDefaultsOnly, Category="FortTooltipDisplayStatInfo")
	FGameplayAttribute Attribute;

	UPROPERTY(EditDefaultsOnly, Category="FortTooltipDisplayStatInfo")
	FGameplayTagContainer ContextTags;

	UPROPERTY(EditDefaultsOnly, Category="FortTooltipDisplayStatInfo")
	bool bLowerIsBetter;

};

USTRUCT(BlueprintType)
struct FFortTooltipDisplayStatsCategory
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortTooltipDisplayStatsCategory")
	FText CategoryName;

	UPROPERTY(EditDefaultsOnly, Category="FortTooltipDisplayStatsCategory")
	TArray<FFortTooltipDisplayStatInfo> TooltipStats;

};

UCLASS(BlueprintType)
class UFortTooltipDisplayStatsList : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortTooltipDisplayStatsList")
	TArray<FFortTooltipDisplayStatsCategory> TooltipCategories;

};

UCLASS(MinimalAPI)
class UFortTooltipDisplayStatsLookupTable : public UDataAsset
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Category="FortTooltipDisplayStatsLookupTable")
	TArray<FFortTooltipDisplayInfo> TooltipDisplayStats;

};

