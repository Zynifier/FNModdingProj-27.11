// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Quests/FortQuestItemDefinitionEnums.h"
#include "Quests/FortQuestItemDefinition_AthenaEnums.h"
#include "Quests/FortQuestTypes.h"
#include "Verbs/VerbMessage.h"
#include "FortVerbMessage_QuestUpdated.generated.h"

class UFortQuestItemDefinition;

USTRUCT(meta=(DisplayName="Quest Updated"))
struct FFortVerbMessage_QuestUpdated : public FVerbMessage
{
	GENERATED_BODY()

private:
	UPROPERTY(VisibleAnywhere, Category="FortVerbMessage_QuestUpdated", meta=(DisplayName="Quest Definition"))
	TWeakObjectPtr<UFortQuestItemDefinition> QuestDefinitions;

	UPROPERTY(VisibleAnywhere, Category="FortVerbMessage_QuestUpdated")
	FGameplayTagContainer QuestTags;

	UPROPERTY(VisibleAnywhere, Category="FortVerbMessage_QuestUpdated")
	EFortQuestType QuestType;

	UPROPERTY(VisibleAnywhere, Category="FortVerbMessage_QuestUpdated")
	EFortQuestSubtype QuestSubtype;

	UPROPERTY(VisibleAnywhere, Category="FortVerbMessage_QuestUpdated")
	EFortQuestState QuestState;

};

