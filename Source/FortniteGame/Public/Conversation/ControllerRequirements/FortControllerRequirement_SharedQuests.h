// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Conversation/FortConversationControllerRequirement.h"
#include "FortControllerRequirement_SharedQuests.generated.h"

UENUM(BlueprintType)
enum class EQuestSpecificationMethod : uint8
{
	/** Quest to be specified directly inline*/
	Static = 0,
	/** Quest can be resolved from service provider 'supported quests' array using the index provider */
	Slotted = 1,
	/** Quest can be resolved from the service provider's consolidated quest component */
	ServiceProvider = 2,
};

UCLASS(AutoCollapseCategories=("Filtering"), meta=(DisplayName="Require: Has Shared Quest Capacity"))
class UFortControllerRequirement_HasSharedQuestCapacity : public UFortControllerRequirement
{
	GENERATED_BODY()

};

