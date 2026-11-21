// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Conversation/FortConversationControllerRequirement.h"
#include "FortControllerRequirement_CheckTimeSinceLastPlayedMatch.generated.h"

UCLASS(AutoCollapseCategories=("Filtering"), meta=(DisplayName="Require: Check Time Since Last Played Match"))
class UFortControllerRequirement_CheckTimeSinceLastPlayedMatch : public UFortControllerRequirement
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="FortControllerRequirement_CheckTimeSinceLastPlayedMatch")
	int32 Days;

	UPROPERTY(EditAnywhere, Category="FortControllerRequirement_CheckTimeSinceLastPlayedMatch")
	int32 Hours;

	UPROPERTY(EditAnywhere, Category="FortControllerRequirement_CheckTimeSinceLastPlayedMatch")
	int32 Minutes;

	UPROPERTY(EditAnywhere, Category="FortControllerRequirement_CheckTimeSinceLastPlayedMatch")
	int32 Seconds;

};

