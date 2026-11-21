// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Quests/QuestDefinitionComponents/FortQuestDefinitionComponent_CustomRewardWidget.h"
#include "FortQuestDefinitionComponent_SurvivorTierBadgeRewardWidget.generated.h"

UCLASS(BlueprintType, meta=(DisplayName="Survivor Badge As A Reward"))
class FORTNITEGAME_API UFortQuestDefinitionComponent_SurvivorTierBadgeRewardWidget : public UFortQuestDefinitionComponent_CustomRewardWidget
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="FortQuestDefinitionComponent_SurvivorTierBadgeRewardWidget")
	int32 SurvivorTier;

	UPROPERTY(EditAnywhere, Category="FortQuestDefinitionComponent_SurvivorTierBadgeRewardWidget")
	int32 PrestigeLevel;

};

