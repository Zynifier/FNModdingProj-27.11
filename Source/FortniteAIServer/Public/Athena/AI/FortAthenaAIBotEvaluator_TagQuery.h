// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Athena/AI/FortAthenaAIBotEvaluator.h"
#include "FortAthenaAIBotEvaluator_TagQuery.generated.h"

class UAbilitySystemComponent;

UCLASS(Abstract)
class UFortAthenaAIBotEvaluator_TagQuery : public UFortAthenaAIBotEvaluator
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, Category="Tag Query", meta=(AllowPrivateAccess="true"))
	FGameplayTagQuery TagQuery;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UAbilitySystemComponent> CachedAbilitySystemComponent;

};

