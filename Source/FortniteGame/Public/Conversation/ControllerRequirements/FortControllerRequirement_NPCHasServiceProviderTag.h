// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Conversation/FortConversationControllerRequirement.h"
#include "FortControllerRequirement_NPCHasServiceProviderTag.generated.h"

UCLASS(meta=(DisplayName="Require: NPC Has Service Provider Tag"))
class UFortControllerRequirement_NPCHasServiceProviderTag : public UFortControllerRequirement
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="FortControllerRequirement_NPCHasServiceProviderTag", meta=(Categories="Conversation.Entry"))
	FGameplayTag QueryTag;

};

