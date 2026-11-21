// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ConversationRequirementNode.h"
#include "GameplayTagContainer.h"
#include "FortConversationRequirement_ControllerRequirement.generated.h"

class UFortControllerRequirement;

UCLASS(meta=(DisplayName="Require: Participant Meets Controller Requirement"))
class UFortConversationRequirement_ControllerRequirement : public UConversationRequirementNode
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortConversationRequirement_ControllerRequirement", meta=(ExposeOnSpawn))
	FGameplayTag ParticipantID;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Instanced, Category="FortConversationRequirement_ControllerRequirement", meta=(ExposeOnSpawn))
	TObjectPtr<UFortControllerRequirement> Requirement;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortConversationRequirement_ControllerRequirement", meta=(HideInConversationNode="true"))
	bool bAutoUpdateNodeDisplayName;

};

