// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Conversation/FortConversationTaskNode_GrantQuest.h"
#include "FortConversationTaskNode_GrantStaticQuest.generated.h"

class UFortQuestItemDefinition_Athena;

UCLASS(Abstract, BlueprintType)
class UFortConversationTaskNode_GrantStaticQuest : public UFortConversationTaskNode_GrantQuest
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Quest", meta=(AssetBundles="Equipped", DisplayName="Quest To Grant", ExposeOnSpawn))
	TSoftObjectPtr<UFortQuestItemDefinition_Athena> QuestToGrantPtr;

};

