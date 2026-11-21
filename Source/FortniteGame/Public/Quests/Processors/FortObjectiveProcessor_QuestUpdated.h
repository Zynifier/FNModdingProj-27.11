// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Quests/FortQuestItemDefinitionEnums.h"
#include "Quests/FortQuestItemDefinition_AthenaEnums.h"
#include "Quests/FortQuestTypes.h"
#include "Quests/Processors/EventProcessorTypes.h"
#include "Quests/Processors/FortObjectiveProcessor.h"
#include "Quests/Processors/Helpers/FortQueryHelpers.h"
#include "FortObjectiveProcessor_QuestUpdated.generated.h"

USTRUCT(meta=(DisplayName="Quest Updated"))
struct FFortObjectiveFilter_QuestUpdated : public FObjectiveFilter
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="FortObjectiveFilter_QuestUpdated")
	FObjectiveSubjectTags QuestTags;

	UPROPERTY(EditAnywhere, Category="FortObjectiveFilter_QuestUpdated")
	EFortQuestType QuestType;

	UPROPERTY(EditAnywhere, Category="FortObjectiveFilter_QuestUpdated")
	EFortQuestSubtype QuestSubtype;

	UPROPERTY(EditAnywhere, Category="FortObjectiveFilter_QuestUpdated", meta=(EditCondition="bUseQuestDefinitionsFilter"))
	FAdvancedQuestDefinitionFilter QuestDefinitions;

	UPROPERTY(EditAnywhere, Category="FortObjectiveFilter_QuestUpdated")
	EFortQuestState QuestState;

	UPROPERTY(EditAnywhere, Category="FortObjectiveFilter_QuestUpdated", meta=(InlineEditConditionToggle))
	uint8 bUseQuestDefinitionsFilter : 1;

};

UCLASS()
class UFortObjectiveProcessor_QuestUpdated : public UFortObjectiveProcessor
{
	GENERATED_BODY()

};

