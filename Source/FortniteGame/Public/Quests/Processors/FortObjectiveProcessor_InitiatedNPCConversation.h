// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Quests/Processors/EventProcessorTypes.h"
#include "Quests/Processors/FortObjectiveProcessor.h"
#include "FortObjectiveProcessor_InitiatedNPCConversation.generated.h"

USTRUCT(meta=(DisplayName="Initiated NPC Conversation"))
struct FFortObjectiveFilter_InitiatedNPCConversation : public FObjectiveFilter
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="FortObjectiveFilter_InitiatedNPCConversation")
	FObjectiveSubjectTags_Progressible ConversingNPC;

	UPROPERTY(EditAnywhere, Category="FortObjectiveFilter_InitiatedNPCConversation")
	uint8 bRequireFirstConversationBetweenParticipants : 1;

	UPROPERTY(EditAnywhere, Category="FortObjectiveFilter_InitiatedNPCConversation")
	FGameplayTagQuery ServiceProviderIDTag;

};

UCLASS()
class UFortObjectiveProcessor_InitiatedNPCConversation : public UFortObjectiveProcessor
{
	GENERATED_BODY()

};

