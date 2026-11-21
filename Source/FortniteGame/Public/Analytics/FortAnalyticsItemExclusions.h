// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "GameplayTagContainer.h"
#include "FortRarityEnum.h"
#include "Items/FortItemTypeEnum.h"
#include "FortAnalyticsItemExclusions.generated.h"

UCLASS()
class UFortAnalyticsItemExclusions : public UDataAsset
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Category="FortAnalyticsItemExclusions")
	TSet<EFortRarity> ExcludedRarities;

	UPROPERTY(EditDefaultsOnly, Category="FortAnalyticsItemExclusions")
	TSet<EFortItemType> ExcludedItemTypes;

	UPROPERTY(EditDefaultsOnly, Category="FortAnalyticsItemExclusions")
	FGameplayTagContainer ExcludedItemTags;

};

