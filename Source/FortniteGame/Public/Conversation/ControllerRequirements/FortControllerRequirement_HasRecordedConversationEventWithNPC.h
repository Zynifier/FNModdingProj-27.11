// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Conversation/FortConversationControllerRequirement.h"
#include "FortControllerRequirement_HasRecordedConversationEventWithNPC.generated.h"

UENUM(BlueprintType)
enum class EConversationEventQueryMethod : uint8
{
	CheckAgainstCurrentConversationParticipant = 0,
	CheckAgainstConversationEntryTag = 1,
};

UCLASS(AutoCollapseCategories=("Filtering"), meta=(DisplayName="Require: Has Recorded Conversation Event With NPC"))
class UFortControllerRequirement_HasRecordedConversationEventWithNPC : public UFortControllerRequirement
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="Filtering", meta=(Categories="Conversation.Event"))
	FGameplayTag QueryEventTag;

	UPROPERTY(EditAnywhere, Category="Filtering")
	bool bRequireExactEventTagMatch;

	UPROPERTY(EditAnywhere, Category="Filtering", meta=(Categories="Conversation.Event"))
	EConversationEventQueryMethod QueryMethod;

	UPROPERTY(EditAnywhere, Category="Filtering", meta=(Categories="Conversation.Entry"))
	FGameplayTag ConversationEntryTag;

};

