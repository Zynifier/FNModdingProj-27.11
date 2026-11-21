// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "GameplayEffectCalculations/Executions/FortGameplayEffectExecutionCalculation.h"
#include "FortCurieElementExecution.generated.h"

UCLASS(Abstract)
class UFortCurieElementExecution : public UFortGameplayEffectExecutionCalculation
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Curie", meta=(Categories="Curie.Element"))
	FGameplayTag ElementToApply;

};

