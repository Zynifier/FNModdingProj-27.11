// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ConversationRequirementNode.h"
#include "FortConversationRequirement_SlottedQuestNotCompletedThisMatch.generated.h"

UCLASS(meta=(DisplayName="Require: Slotted Quest Not Completed This Match"))
class UFortConversationRequirement_SlottedQuestNotCompletedThisMatch : public UConversationRequirementNode
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, Category="Quest", meta=(ClampMax="5", ClampMin="1", UIMax="5", UIMin="1"))
	int32 QuestSlot;

};

