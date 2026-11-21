// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFeatureAction.h"
#include "GameplayTagContainer.h"
#include "Quests/QuestProductGroup.h"
#include "FortGameFeatureAction_QuestProductGroup.generated.h"

UCLASS(MinimalAPI, meta=(DisplayName="Quest Product Group"))
class UFortGameFeatureAction_QuestProductGroup : public UGameFeatureAction
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly, Category="Quest Product Group")
	FGameplayTag ProductGroupTag;

	UPROPERTY(EditDefaultsOnly, Category="Quest Product Group")
	FQuestProductData Data;

};

