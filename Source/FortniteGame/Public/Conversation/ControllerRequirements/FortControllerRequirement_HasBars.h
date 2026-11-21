// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Conversation/FortConversationControllerRequirement.h"
#include "Conversation/FortThresholdTestConfig.h"
#include "FortControllerRequirement_HasBars.generated.h"

UCLASS(AutoCollapseCategories=("Filtering"), meta=(DisplayName="Require: Has Gold Bars"))
class UFortControllerRequirement_HasBars : public UFortControllerRequirement
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="Filtering")
	FThresholdTestConfig ThresholdTestConfig;

};

