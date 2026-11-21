// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Rewards/FortRewardNotificationData.h"
#include "FortRewardExpeditionData.generated.h"

class UFortExpeditionItem;

UCLASS(BlueprintType)
class UFortRewardExpeditionData : public UFortRewardNotificationData
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, Category="FortRewardExpeditionData")
	TObjectPtr<UFortExpeditionItem> Expedition;

};

