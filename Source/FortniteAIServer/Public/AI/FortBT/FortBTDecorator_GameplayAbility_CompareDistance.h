// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AI/FortAITypes.h"
#include "AI/FortBT/FortBTDecorator_QueryGameplayAbility.h"
#include "FortBTDecorator_GameplayAbility_CompareDistance.generated.h"

UCLASS()
class UFortBTDecorator_GameplayAbility_CompareDistance : public UFortBTDecorator_QueryGameplayAbility
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Condition")
	TArray<FDistanceToTargetComparison> DistanceComparisons;

};

