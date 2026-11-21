// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Verbs/VerbMessage.h"
#include "FortVerbMessage_ConversationChoiceMade.generated.h"

USTRUCT()
struct FFortVerbMessage_ConversationChoiceMade : public FVerbMessage
{
	GENERATED_BODY()

private:
	UPROPERTY(VisibleAnywhere, Category="FortVerbMessage_ConversationChoiceMade")
	FSubjectTagsPair NPC;

	UPROPERTY(VisibleAnywhere, Category="FortVerbMessage_ConversationChoiceMade")
	FGameplayTagContainer ConversationChoice;

};

