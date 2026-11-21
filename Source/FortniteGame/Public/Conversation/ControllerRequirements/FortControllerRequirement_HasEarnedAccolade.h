// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Conversation/FortConversationControllerRequirement.h"
#include "FortControllerRequirement_HasEarnedAccolade.generated.h"

class UFortAccoladeItemDefinition;

UCLASS(AutoCollapseCategories=("Filtering"), meta=(DisplayName="Require: Has Earned Accolade"))
class UFortControllerRequirement_HasEarnedAccolade : public UFortControllerRequirement
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="Filtering")
	TSoftObjectPtr<UFortAccoladeItemDefinition> AccoladeDefinition;

};

