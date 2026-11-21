// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Rewards/FortRewardNotificationData.h"
#include "FortRewardEpicQuestData.generated.h"

class UFortQuestItem;

UCLASS(BlueprintType)
class UFortRewardEpicQuestData : public UFortRewardNotificationData
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, Category="FortRewardEpicQuestData")
	TObjectPtr<UFortQuestItem> Quest;

};

