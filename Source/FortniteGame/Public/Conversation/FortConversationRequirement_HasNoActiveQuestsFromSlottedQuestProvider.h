// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ConversationRequirementNode.h"
#include "FortConversationRequirement_HasNoActiveQuestsFromSlottedQuestProvider.generated.h"

UCLASS(meta=(DisplayName="Require: Has No Active Quests From Slotted Quest Provider"))
class UFortConversationRequirement_HasNoActiveQuestsFromSlottedQuestProvider : public UConversationRequirementNode
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, Category="Quest", meta=(ClampMax="5", ClampMin="1", UIMax="5", UIMin="1"))
	int32 QuestSlot;

};

