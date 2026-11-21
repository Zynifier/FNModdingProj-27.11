// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Conversation/FortConversationTaskNode_GrantQuest.h"
#include "FortConversationTaskNode_GrantSlottedQuest.generated.h"

UCLASS(Abstract, BlueprintType)
class UFortConversationTaskNode_GrantSlottedQuest : public UFortConversationTaskNode_GrantQuest
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Quest", meta=(ClampMax="5", ClampMin="1", ExposeOnSpawn, UIMax="5", UIMin="1"))
	int32 QuestSlot;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortConversationTaskNode_GrantSlottedQuest")
	FGameplayTag OptionalFilterCategoryTag;

	UPROPERTY(EditAnywhere, Category="Quest")
	bool bNotifyQuestProvider;

};

