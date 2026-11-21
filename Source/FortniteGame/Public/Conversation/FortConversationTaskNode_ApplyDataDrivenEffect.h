// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Conversation/FortConversationTaskNode.h"
#include "FortConversationTaskNode_ApplyDataDrivenEffect.generated.h"

class UFortControllerEffect;

UCLASS()
class UFortConversationTaskNode_ApplyDataDrivenEffect : public UFortConversationTaskNode
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Filtering", meta=(Categories="Conversation.Participant"))
	FGameplayTag ParticipantID;

	UPROPERTY(EditAnywhere, Instanced, Category="Effects")
	TArray<TObjectPtr<UFortControllerEffect>> EffectsToApply;

};

