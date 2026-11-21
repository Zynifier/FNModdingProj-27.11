// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Quests/Processors/EventProcessorTypes.h"
#include "Quests/Processors/FortObjectiveProcessor.h"
#include "FortObjectiveProcessor_CurrencySpent.generated.h"

USTRUCT(meta=(DisplayName="Currency Spent"))
struct FFortObjectiveFilter_CurrencySpent : public FObjectiveFilter
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="FortObjectiveFilter_CurrencySpent", meta=(DisplayAfter="Author"))
	FObjectiveSubjectTags PurchaseTags;

	UPROPERTY(EditAnywhere, Category="FortObjectiveFilter_CurrencySpent", meta=(DisplayPriority="-1"))
	uint8 bIncrementByAmountSpent : 1;

	UPROPERTY(EditAnywhere, Category="FortObjectiveFilter_CurrencySpent", meta=(InlineEditConditionToggle))
	uint8 bUseSpentAmount : 1;

	UPROPERTY(EditAnywhere, Category="FortObjectiveFilter_CurrencySpent", meta=(DisplayAfter="bIncrementByAmountSpent", EditCondition="bUseSpentAmount", UIMin="0"))
	FInt32Range SpentAmountToCountForProgress;

};

UCLASS()
class UFortObjectiveProcessor_CurrencySpent : public UFortObjectiveProcessor
{
	GENERATED_BODY()

};

