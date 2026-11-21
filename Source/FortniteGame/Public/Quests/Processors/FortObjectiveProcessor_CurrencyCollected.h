// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Quests/Processors/EventProcessorTypes.h"
#include "Quests/Processors/FortObjectiveProcessor.h"
#include "FortObjectiveProcessor_CurrencyCollected.generated.h"

USTRUCT(meta=(DisplayName="Currency Collected"))
struct FFortObjectiveFilter_CurrencyCollected : public FObjectiveFilter
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="FortObjectiveFilter_CurrencyCollected", meta=(DisplayAfter="Author"))
	FObjectiveSubjectTags CollectedItemSpawnSource;

	UPROPERTY(EditAnywhere, Category="FortObjectiveFilter_CurrencyCollected", meta=(DisplayPriority="-1"))
	uint8 bIncrementByAmountCollected : 1;

	UPROPERTY(EditAnywhere, Category="FortObjectiveFilter_CurrencyCollected", meta=(InlineEditConditionToggle))
	uint8 bUseCollectionSize : 1;

	UPROPERTY(EditAnywhere, Category="FortObjectiveFilter_CurrencyCollected", meta=(DisplayAfter="bIncrementByAmountCollected", EditCondition="bUseCollectionSize", UIMin="0"))
	FInt32Range CollectionSizeToCountForProgress;

};

UCLASS()
class UFortObjectiveProcessor_CurrencyCollected : public UFortObjectiveProcessor
{
	GENERATED_BODY()

};

