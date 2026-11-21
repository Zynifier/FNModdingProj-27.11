// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Rewards/FortRewardNotificationData.h"
#include "STW/CollectionBook/FortCollectionBookTypes.h"
#include "FortRewardCollectionBookData.generated.h"

UCLASS(BlueprintType)
class UFortRewardCollectionBookData : public UFortRewardNotificationData
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, Category="FortRewardCollectionBookData")
	FFortCollectionBookRewards CollectionBookRewards;

};

