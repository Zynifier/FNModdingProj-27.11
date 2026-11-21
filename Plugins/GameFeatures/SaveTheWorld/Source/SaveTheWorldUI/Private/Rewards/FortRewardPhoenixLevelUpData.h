// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortItemQuantityPair.h"
#include "Rewards/FortRewardNotificationData.h"
#include "FortRewardPhoenixLevelUpData.generated.h"

UCLASS(BlueprintType)
class UFortRewardPhoenixLevelUpData : public UFortRewardNotificationData
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, Category="FortRewardPhoenixLevelUpData")
	int32 PhoenixLevel;

	UPROPERTY(BlueprintReadWrite, Category="FortRewardPhoenixLevelUpData")
	TArray<FFortItemInstanceQuantityPair> Rewards;

};

