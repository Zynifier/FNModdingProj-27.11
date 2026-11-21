// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Conversation/FortConversationControllerRequirement.h"
#include "FortControllerRequirement_HasQuestToTurnIn.generated.h"

class UFortQuestItemDefinition_Athena;

UCLASS(AutoCollapseCategories=("Filtering"), meta=(DisplayName="Require: Has Quest To Turn In"))
class UFortControllerRequirement_HasQuestToTurnIn : public UFortControllerRequirement
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortControllerRequirement_HasQuestToTurnIn")
	bool bResolveQuestDetailsFromServiceProvider;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortControllerRequirement_HasQuestToTurnIn", meta=(AssetBundles="Equipped", DisplayName="Quest To Turn In", EditCondition="!bResolveQuestDetailsFromServiceProvider"))
	TSoftObjectPtr<UFortQuestItemDefinition_Athena> SoftQuestToTurnIn;

};

