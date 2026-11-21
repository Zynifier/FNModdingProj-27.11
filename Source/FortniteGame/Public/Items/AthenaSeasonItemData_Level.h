// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Athena/AthenaRewardSchedule.h"
#include "Items/AthenaSeasonItemData.h"
#include "Items/AthenaSeasonItemDefinitionTypes.h"
#include "AthenaSeasonItemData_Level.generated.h"

class UDataTable;

UCLASS(MinimalAPI, meta=(DisplayName="Battle Pass Level Data"))
class UAthenaSeasonItemData_Level : public UAthenaSeasonItemData
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, Category="SeasonLevelConfig", meta=(ClampMax="100", ClampMin="1"))
	int32 NumBattlePassLevels;

	UPROPERTY(EditAnywhere, Category="SeasonLevelConfig", meta=(ClampMax="100", ClampMin="1"))
	int32 NumAdditionalBattlePassLevels;

	UPROPERTY(EditAnywhere, Category="SeasonLevelConfig", meta=(DisplayThumbnail="false"))
	TObjectPtr<UDataTable> BattlePassXpCurve;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="SeasonLevelConfig")
	TArray<int32> FreeLevelsThatNavigateToBattlePass;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="SeasonLevelConfig")
	TArray<FTrackCategory> TrackCategories;

	UPROPERTY(EditAnywhere, Category="SeasonLevelConfig", meta=(Categories="Cosmetics.Source"))
	FGameplayTag BattlePassFreeItemContentTag;

	UPROPERTY(EditAnywhere, Category="SeasonLevelConfig", meta=(Categories="Cosmetics.Source"))
	FGameplayTag BattlePassPaidItemContentTag;

	UPROPERTY(EditAnywhere, Category="SeasonLevelConfig", meta=(Categories="Cosmetics.Source"))
	FGameplayTag BattlePassAdditionalItemContentTag;

	UPROPERTY(EditAnywhere, Category="RewardSchedule")
	FAthenaRewardSchedule BattlePassXpScheduleFree;

	UPROPERTY(EditAnywhere, Category="RewardSchedule")
	FAthenaRewardSchedule BattlePassXpSchedulePaid;

	UPROPERTY(EditAnywhere, Category="RewardSchedule")
	FAthenaRewardSchedule AdditionalBattlePassSchedule;

};

