// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Conversation/FortConversationControllerRequirement.h"
#include "Conversation/FortThresholdTestConfig.h"
#include "FortControllerRequirement_HasResource.generated.h"

class UFortResourceItemDefinition;

UCLASS(AutoCollapseCategories=("Filtering"), meta=(DisplayName="Require: Has Resource"))
class UFortControllerRequirement_HasResource : public UFortControllerRequirement
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="Filtering")
	FThresholdTestConfig ThresholdTestConfig;

	UPROPERTY(EditAnywhere, Category="Filtering")
	TObjectPtr<UFortResourceItemDefinition> ResourceItemDefinition;

};

