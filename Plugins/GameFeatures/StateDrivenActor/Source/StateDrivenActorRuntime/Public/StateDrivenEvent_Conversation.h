// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "StateDrivenEvent_InteractionBase.h"
#include "StateDrivenEvent_Conversation.generated.h"

class UFortNonPlayerConversationParticipantComponent;

USTRUCT(meta=(DisplayName="Conversation"))
struct FStateDrivenEvent_Conversation : public FStateDrivenEvent_InteractionBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="StateDrivenEvent_Conversation")
	FGameplayTag ConversationEntryTag;

	UPROPERTY(BlueprintReadOnly, Export, Category="StateDrivenEvent_Conversation", meta=(AllowPrivateAccess))
	TWeakObjectPtr<UFortNonPlayerConversationParticipantComponent> ConversationComponentPtr;

};

