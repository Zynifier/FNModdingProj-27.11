// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Items/AthenaSeasonItemData_BattlePass.h"
#include "Items/AthenaSeasonItemRewardEntry.h"
#include "AthenaSeasonItemData_BattleStar.generated.h"

UCLASS(MinimalAPI, meta=(DisplayName="Battle Pass Battle Star Data"))
class UAthenaSeasonItemData_BattleStar : public UAthenaSeasonItemData_BattlePass
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Category="PageData")
	FAthenaSeasonLandingPageData LandingPageData;

	UPROPERTY(EditDefaultsOnly, Category="PageData", meta=(DisplayName="Reward Page List"))
	TArray<FAthenaSeasonPageGrid> PageList;

	UPROPERTY(EditDefaultsOnly, Category="PageData")
	TArray<FAthenaSeasonPageGrid> QuestPageList;

	UPROPERTY(EditDefaultsOnly, Category="PageData")
	TArray<FAthenaSeasonPageGrid> BonusPageList;

	UPROPERTY(EditDefaultsOnly, Category="PageData")
	TArray<FAthenaSeasonPageGrid> CustomizationPageList;

	UPROPERTY(EditDefaultsOnly, Category="PageData")
	TArray<FAthenaSeasonPageGrid> WeeklyPageList;

};

