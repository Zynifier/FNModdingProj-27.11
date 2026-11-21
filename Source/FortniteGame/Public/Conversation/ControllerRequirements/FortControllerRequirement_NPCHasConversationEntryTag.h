// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Conversation/FortConversationControllerRequirement.h"
#include "FortControllerRequirement_NPCHasConversationEntryTag.generated.h"

UCLASS(meta=(DisplayName="Require: NPC Has Conversation Tag"))
class UFortControllerRequirement_NPCHasConversationEntryTag : public UFortControllerRequirement
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="FortControllerRequirement_NPCHasConversationEntryTag", meta=(Categories="Conversation.Entry"))
	FGameplayTag QueryTag;

};

