// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Conversation/FortConversationControllerRequirement.h"
#include "FortControllerRequirement_HasVisitedPOI.generated.h"

UCLASS(AutoCollapseCategories=("Filtering"), meta=(DisplayName="Require: Has Visited POI"))
class UFortControllerRequirement_HasVisitedPOI : public UFortControllerRequirement
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="Filtering", meta=(Categories="Athena.Location"))
	FGameplayTag POITag;

};

