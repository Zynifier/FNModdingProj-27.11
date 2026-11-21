// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Rewards/FortRewardNotificationData.h"
#include "FortRewardGiftBoxData.generated.h"

class UFortGiftBoxItem;

UCLASS(BlueprintType)
class UFortRewardGiftBoxData : public UFortRewardNotificationData
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, Category="FortRewardGiftBoxData")
	TObjectPtr<UFortGiftBoxItem> GiftBox;

};

