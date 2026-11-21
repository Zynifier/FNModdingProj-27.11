// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "FortControllerEffectUtilities.generated.h"

UCLASS(MinimalAPI)
class UFortControllerEffectUtils : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	static FGameplayTag GetOppositeParticipantTag(const FGameplayTag& MainParticipantID);

};

