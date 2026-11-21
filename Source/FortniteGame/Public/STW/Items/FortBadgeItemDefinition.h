// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "Math/Color.h"
#include "FortItemQuantityPair.h"
#include "Items/FortStatCategoryEnum.h"
#include "Items/FortWorldItemDefinition.h"
#include "FortBadgeItemDefinition.generated.h"

class APlayerController;
class UFortCardPackItemDefinition;
enum class EStatCategory : uint8;

USTRUCT(BlueprintType)
struct FFortBadgeScoringData : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="FortAIPawnVariant")
	int32 ScoreAwarded;

	UPROPERTY(EditDefaultsOnly, Category="Scoring")
	int32 MissionPoints;

	UPROPERTY(EditDefaultsOnly, Category="Scoring")
	EStatCategory ScoreCategory;

	UPROPERTY(EditDefaultsOnly, Category="Scoring")
	int32 ScoreThreshold;

};

UCLASS(MinimalAPI, BlueprintType, HideCategories=("Functionality", "QuickbarDisplay", "Stats", "OwnedTags", "Attributes", "LootLevel"))
class UFortBadgeItemDefinition : public UFortWorldItemDefinition
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="Badge")
	EStatCategory GetBadgeScoreCategory() const;

	UFUNCTION(BlueprintPure, Category="Badge")
	int32 GetBadgeScoreThreshold() const;

	UFUNCTION(BlueprintPure, Category="BadgeDisplay")
	int32 GetMissionPoints() const;

	UFUNCTION(BlueprintPure, Category="BadgeDisplay")
	int32 GetScoreAwarded(const APlayerController* PlayerController) const;

	UFUNCTION(BlueprintPure, Category="BadgeDisplay")
	int32 GetUIMissionPointsOffset() const;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="BadgeDisplay")
	FText DisplayText;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="BadgeDisplay")
	FText FailedDisplayText;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="BadgeDisplay")
	FLinearColor BadgeColor;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Badge", meta=(ClampMin="0"))
	int32 UIMissionPointsOffset;

private:
	UPROPERTY(EditDefaultsOnly, Category="Scoring")
	FDataTableRowHandle BadgeScoringValuesHandle;

	UPROPERTY(EditDefaultsOnly, Category="Scoring")
	TSoftObjectPtr<UFortCardPackItemDefinition> BadgeCardPackReward;

	UPROPERTY(EditDefaultsOnly, Category="Items")
	TArray<FFortItemQuantityPair> ItemRewards;

};

