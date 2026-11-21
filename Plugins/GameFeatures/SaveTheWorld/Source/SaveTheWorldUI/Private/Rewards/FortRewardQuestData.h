// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Rewards/FortRewardNotificationData.h"
#include "FortRewardQuestData.generated.h"

class UFortQuestItem;

UCLASS(BlueprintType)
class UFortRewardQuestData : public UFortRewardNotificationData
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, Category="FortRewardQuestData")
	TObjectPtr<UFortQuestItem> Quest;

};

