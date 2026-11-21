// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "FortConversationRequirementUtilities.generated.h"

UCLASS(MinimalAPI)
class UFortConversationRequirementUtils : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	static FGameplayTag GetOppositeParticipantTag(const FGameplayTag& MainParticipantID);

};

