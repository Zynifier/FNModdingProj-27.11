// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ConversationRequirementNode.h"
#include "FortConversationRequirement_AllSlottedQuestPrerequisitesCompleted.generated.h"

UCLASS(meta=(DisplayName="Require: All Slotted Quest Prerequisites Completed"))
class UFortConversationRequirement_AllSlottedQuestPrerequisitesCompleted : public UConversationRequirementNode
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, Category="Quest", meta=(ClampMax="5", ClampMin="1", UIMax="5", UIMin="1"))
	int32 QuestSlot;

};

