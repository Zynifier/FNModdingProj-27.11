// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Quests/Processors/EventProcessorTypes.h"
#include "Quests/Processors/FortObjectiveProcessor.h"
#include "FortObjectiveProcessor_ConversationChoiceMade.generated.h"

USTRUCT(meta=(DisplayName="Conversation Choice Made"))
struct FFortObjectiveFilter_ConversationChoiceMade : public FObjectiveFilter
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="FortObjectiveFilter_ConversationChoiceMade")
	FObjectiveSubjectTags_Progressible NPC;

	UPROPERTY(EditAnywhere, Category="FortObjectiveFilter_ConversationChoiceMade")
	FObjectiveSubjectTags ConversationChoice;

};

UCLASS()
class FORTNITEGAME_API UFortObjectiveProcessor_ConversationChoiceMade : public UFortObjectiveProcessor
{
	GENERATED_BODY()

};

