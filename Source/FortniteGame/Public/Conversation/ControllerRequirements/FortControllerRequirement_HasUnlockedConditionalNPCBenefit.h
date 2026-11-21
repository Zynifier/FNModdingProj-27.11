// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Conversation/FortConversationControllerRequirement.h"
#include "FortControllerRequirement_HasUnlockedConditionalNPCBenefit.generated.h"

class UFortConditionalBenefitsConfigCollection;

UCLASS(AutoCollapseCategories=("Filtering"), meta=(DisplayName="Require: Has Unlocked Conditional NPC Benefit"))
class UFortControllerRequirement_HasUnlockedConditionalNPCBenefit : public UFortControllerRequirement
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="Filtering")
	FGameplayTag BenefitIDTag;

	UPROPERTY(EditAnywhere, Category="Filtering")
	bool bDetermineConditionalBenefitsConfigFromServiceProvider;

	UPROPERTY(EditAnywhere, Category="Filtering", meta=(editCondition="!bDetermineConditionalBenefitsConfigFromServiceProvider", EditConditionHides))
	TObjectPtr<UFortConditionalBenefitsConfigCollection> ConditionalBenefitsConfigCollection;

	UPROPERTY(EditAnywhere, Category="Filtering", meta=(editCondition="!bDetermineConditionalBenefitsConfigFromServiceProvider", EditConditionHides))
	FGameplayTag ConditionalBenefitsConfigToCheck;

	UPROPERTY(EditAnywhere, Category="Filtering")
	bool bConsiderGeneralBenefits;

};

