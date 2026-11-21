// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Conversation/FortConversationControllerRequirement.h"
#include "FortControllerRequirement_HasUrgentQuest.generated.h"

UCLASS(AutoCollapseCategories=("Filtering"), meta=(DisplayName="Require: Has Urgent Quest"))
class UFortControllerRequirement_HasUrgentQuest : public UFortControllerRequirement
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortControllerRequirement_HasUrgentQuest")
	FGameplayTagContainer AcceptedUrgentEventTags;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortControllerRequirement_HasUrgentQuest")
	bool bRequireExactMatch;

};

