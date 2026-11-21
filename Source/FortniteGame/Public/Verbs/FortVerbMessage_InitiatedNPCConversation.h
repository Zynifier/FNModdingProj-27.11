// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Verbs/VerbMessage.h"
#include "FortVerbMessage_InitiatedNPCConversation.generated.h"

USTRUCT()
struct FFortVerbMessage_InitiatedNPCConversation : public FVerbMessage
{
	GENERATED_BODY()

private:
	UPROPERTY(VisibleAnywhere, Category="FortVerbMessage_InitiatedNPCConversation")
	FSubjectTagsPair ConversingNPC;

	UPROPERTY(VisibleAnywhere, Category="FortVerbMessage_InitiatedNPCConversation")
	FGameplayTagContainer ServiceProviderTags;

	UPROPERTY(VisibleAnywhere, Category="FortVerbMessage_InitiatedNPCConversation")
	bool bFirstConversationBetweenParticipants;

};

