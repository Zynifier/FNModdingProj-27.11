// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "FortBTTask_TriggerVOEvent.generated.h"

class UFortFeedbackBank;

UCLASS(MinimalAPI)
class UFortBTTask_TriggerVOEvent : public UBTTaskNode
{
	GENERATED_BODY()

public:
	UPROPERTY()
	uint8 bUseFeedbackBank : 1;

	UPROPERTY(EditAnywhere, Category="Node", meta=(EditCondition="!bUseFeedbackBank"))
	FString CustomEventName;

	UPROPERTY(EditAnywhere, Category="Node", meta=(EditCondition="bUseFeedbackBank"))
	FString SelectedEvent;

	UPROPERTY(EditAnywhere, Category="Node", meta=(EditCondition="bUseFeedbackBank"))
	TObjectPtr<UFortFeedbackBank> FeedbackBank;

};

