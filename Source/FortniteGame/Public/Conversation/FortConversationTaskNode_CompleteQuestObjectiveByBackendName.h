// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/SoftObjectPath.h"
#include "Conversation/FortConversationTaskNode.h"
#include "FortConversationTaskNode_CompleteQuestObjectiveByBackendName.generated.h"

UCLASS(BlueprintType, meta=(DisplayName="(QS1 Only) Fort Conversation Task Node Complete Quest Objective By BackendName"))
class UFortConversationTaskNode_CompleteQuestObjectiveByBackendName : public UFortConversationTaskNode
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, Category="Filtering")
	bool bResolveQuestDetailsFromServiceProvider;

	UPROPERTY(EditAnywhere, Category="Filtering", meta=(AllowedClasses="/Script/FortniteGame.FortQuestItemDefinition", EditCondition="!bResolveQuestDetailsFromServiceProvider"))
	FSoftObjectPath QuestDefinition;

	UPROPERTY(EditAnywhere, Category="Filtering", meta=(EditCondition="!bResolveQuestDetailsFromServiceProvider", GetOptions="Editor_GetValidObjectives"))
	FName ObjectiveBackendName;

private:
	UFUNCTION()
	TArray<FName> Editor_GetValidObjectives() const;

};

