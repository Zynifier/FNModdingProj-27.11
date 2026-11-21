// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ConversationRequirementNode.h"
#include "GameplayTagContainer.h"
#include "FortConversationRequirement_HasService.generated.h"

UCLASS(meta=(DisplayName="Require: NPC Has Service"))
class UFortConversationRequirement_HasService : public UConversationRequirementNode
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortConversationRequirement_HasService", meta=(ExposeOnSpawn))
	FGameplayTag ServiceTag;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortConversationRequirement_HasService", meta=(ExposeOnSpawn))
	bool bRequireExactMatch;

};

