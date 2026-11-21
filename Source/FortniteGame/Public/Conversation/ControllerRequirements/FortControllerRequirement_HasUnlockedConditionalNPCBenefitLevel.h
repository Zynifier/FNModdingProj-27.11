// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Conversation/FortConversationControllerRequirement.h"
#include "Conversation/FortThresholdTestConfig.h"
#include "FortControllerRequirement_HasUnlockedConditionalNPCBenefitLevel.generated.h"

class UFortConditionalBenefitsConfigCollection;

UCLASS(AutoCollapseCategories=("Filtering"), meta=(DisplayName="Require: Has Unlocked Conditional NPC Benefit Level"))
class UFortControllerRequirement_HasUnlockedConditionalNPCBenefitLevel : public UFortControllerRequirement
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="Filtering")
	bool bDetermineConditionalBenefitsConfigFromServiceProvider;

	UPROPERTY(EditAnywhere, Category="Filtering", meta=(editCondition="!bDetermineConditionalBenefitsConfigFromServiceProvider", EditConditionHides))
	TObjectPtr<UFortConditionalBenefitsConfigCollection> ConditionalBenefitsConfigCollection;

	UPROPERTY(EditAnywhere, Category="Filtering", meta=(editCondition="!bDetermineConditionalBenefitsConfigFromServiceProvider", EditConditionHides))
	FGameplayTag ConditionalBenefitsConfigToCheck;

	UPROPERTY(EditAnywhere, Category="Filtering")
	FThresholdTestConfig AllowedLevelThreshold;

};

