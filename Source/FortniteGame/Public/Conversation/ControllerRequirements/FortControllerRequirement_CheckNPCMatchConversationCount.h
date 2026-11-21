// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Conversation/FortConversationControllerRequirement.h"
#include "Conversation/FortThresholdTestConfig.h"
#include "FortControllerRequirement_CheckNPCMatchConversationCount.generated.h"

UCLASS(AutoCollapseCategories=("Filtering"), meta=(DisplayName="Require: Check NPC Match Conversation Count"))
class UFortControllerRequirement_CheckNPCMatchConversationCount : public UFortControllerRequirement
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, Category="Filtering")
	FThresholdTestConfig RequiredConversationCountConfig;

	UPROPERTY(EditAnywhere, Category="Filtering")
	FGameplayTag NPCUniqueIDTag;

};

