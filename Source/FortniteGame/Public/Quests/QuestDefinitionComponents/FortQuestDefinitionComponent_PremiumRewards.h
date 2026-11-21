// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortItemQuantityPair.h"
#include "Quests/QuestDefinitionComponents/FortQuestDefinitionComponent.h"
#include "FortQuestDefinitionComponent_PremiumRewards.generated.h"

class UFortTokenType;

USTRUCT(BlueprintType)
struct FFortPremiumRewardDetails
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="QuestRewards")
	FFortItemQuantityPair ItemQuantityPair;

	UPROPERTY(EditAnywhere, Category="QuestRewards")
	bool bHiddenFromGiftbox;

};

UCLASS(MinimalAPI, BlueprintType, meta=(DisplayName="Premium Rewards Component"))
class UFortQuestDefinitionComponent_PremiumRewards : public UFortQuestDefinitionComponent
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, Category="QuestRewards")
	TArray<FFortPremiumRewardDetails> Rewards;

	UPROPERTY(EditAnywhere, Category="QuestRewards")
	TSoftObjectPtr<UFortTokenType> MustHaveTokenId;

};

