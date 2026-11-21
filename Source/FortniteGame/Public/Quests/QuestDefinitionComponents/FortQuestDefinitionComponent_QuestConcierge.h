// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Quests/QuestDefinitionComponents/FortQuestDefinitionComponent.h"
#include "FortQuestDefinitionComponent_QuestConcierge.generated.h"

USTRUCT(BlueprintType)
struct FObjectiveExtensionQuestConcierge : public FObjectiveExtensionData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="ObjectiveExtensionQuestConcierge")
	FGameplayTagQuery ObjectivePlayerRequirement;

};

UCLASS(MinimalAPI, BlueprintType, meta=(DisplayName="Quest Concierge"))
class UFortQuestDefinitionComponent_QuestConcierge : public UFortQuestDefinitionComponent
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="FortQuestDefinitionComponent_QuestConcierge")
	FGameplayTagQuery QuestPlayerRequirement;

};

