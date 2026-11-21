// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "FortItemQuantityPair.h"
#include "FortPhoenixLevelProgressionWidget.generated.h"

USTRUCT(BlueprintType)
struct FFortPhoenixLevelProgressionRewards
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="Phoenix Level Progression")
	int32 NextRewardLevel;

	UPROPERTY(BlueprintReadOnly, Category="Phoenix Level Progression")
	FFortItemQuantityPair NextReward;

	UPROPERTY(BlueprintReadOnly, Category="Phoenix Level Progression")
	int32 NextMajorRewardLevel;

	UPROPERTY(BlueprintReadOnly, Category="Phoenix Level Progression")
	FFortItemQuantityPair NextMajorReward;

};

UCLASS(meta=(DisableNativeTick))
class UFortPhoenixLevelProgressionWidget : public UCommonUserWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintCallable, Category="Phoenix Level Progression", meta=(BlueprintProtected="TRUE"))
	FFortPhoenixLevelProgressionRewards GetNextPhoenixLevelUpRewards(int32 StartingLevel);

};

