// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AthenaSeasonItemRewardIcon.generated.h"

class UFortItem;
class UFortItemSeriesDefinition;
class UTexture2D;

UCLASS(BlueprintType, Blueprintable)
class UAthenaSeasonItemRewardIcon : public UUserWidget
{
	GENERATED_BODY()

public:
	UAthenaSeasonItemRewardIcon(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

public:
	UFUNCTION(BlueprintCallable)
	void InitializeReward(const UFortItem* RewardItem, const TSoftObjectPtr<UTexture2D>& RewardTexture, bool bHasAdditionalStylesToDisplay, int32 RewardLevel, bool bRequiresBattlePass);

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnInitializeReward(const UFortItem* RewardItem, const TSoftObjectPtr<UTexture2D>& RewardTexture, bool bHasAdditionalStylesToDisplay, int32 RewardLevel, bool bRequiresBattlePass);

	UFUNCTION(BlueprintImplementableEvent)
	void OnInitializeSeriesReward(const UFortItemSeriesDefinition* SeriesData);

};

