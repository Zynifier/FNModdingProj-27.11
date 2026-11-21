// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Conversation/FortConversationTaskNode.h"
#include "FortCompleteQuestConversationTaskNode.generated.h"

class UFortQuestItemDefinition_Athena;

UCLASS(BlueprintType)
class UFortCompleteQuestConversationTaskNode : public UFortConversationTaskNode
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortCompleteQuestConversationTaskNode")
	bool bResolveQuestDetailsFromServiceProvider;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortCompleteQuestConversationTaskNode", meta=(AssetBundles="Equipped", EditCondition="!bResolveQuestDetailsFromServiceProvider"))
	TSoftObjectPtr<UFortQuestItemDefinition_Athena> SoftQuestToGrant;

};

