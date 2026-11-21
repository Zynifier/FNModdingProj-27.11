// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "DataProviders/AIDataProvider.h"
#include "GameplayTagContainer.h"
#include "FortAIDataProvider_Ability.generated.h"

UCLASS(AutoExpandCategories=("Provider"), meta=(DisplayName="Fort Ability"))
class UFortAIDataProvider_Ability : public UAIDataProvider
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Provider")
	FGameplayTagContainer AbilityTag;

	UPROPERTY(EditAnywhere, Category="Provider")
	FGameplayTagContainer AbilityBehaviorDistanceTag;

	UPROPERTY()
	float BehaviorDistance;

	UPROPERTY()
	float MaxTargetSelectionRange;

};

