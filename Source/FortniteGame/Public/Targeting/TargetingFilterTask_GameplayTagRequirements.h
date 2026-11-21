// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayEffectTypes.h"
#include "Tasks/TargetingFilterTask_BasicFilterTemplate.h"
#include "TargetingFilterTask_GameplayTagRequirements.generated.h"

UCLASS(BlueprintType, Blueprintable)
class UTargetingFilterTask_GameplayTagRequirements : public UTargetingFilterTask_BasicFilterTemplate
{
	GENERATED_BODY()

public:
	UTargetingFilterTask_GameplayTagRequirements(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

protected:
	UPROPERTY(EditAnywhere, Category="Targeting Filter | Tags")
	FGameplayTagRequirements GameplayTagReqs;

};

