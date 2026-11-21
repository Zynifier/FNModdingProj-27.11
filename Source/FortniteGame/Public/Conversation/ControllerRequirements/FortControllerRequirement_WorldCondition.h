// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "WorldConditionQuery.h"
#include "WorldConditionSchema.h"
#include "Conversation/FortConversationControllerRequirement.h"
#include "FortControllerRequirement_WorldCondition.generated.h"

UCLASS()
class UFortControllerRequirementWorldConditionSchema : public UWorldConditionSchema
{
	GENERATED_BODY()

};

UCLASS(AutoCollapseCategories=("Filtering"), meta=(DisplayName="Require: World Condition"))
class UFortControllerRequirement_WorldCondition : public UFortControllerRequirement
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="WC", meta=(HideInConversationNode="true"))
	FWorldConditionQueryDefinition Conditions;

};

