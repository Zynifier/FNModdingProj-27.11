// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Rewards/FortRewardNotificationData.h"
#include "FortRewardItemCacheData.generated.h"

class UFortItem;

UCLASS(BlueprintType)
class UFortRewardItemCacheData : public UFortRewardNotificationData
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, Category="FortRewardItemCacheData")
	TObjectPtr<UFortItem> ItemCache;

};

