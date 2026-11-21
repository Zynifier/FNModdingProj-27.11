// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Athena/AI/FortAthenaAIBotEvaluator_Movement.h"
#include "FortAthenaAIBotEvaluator_Bunker.generated.h"

UCLASS(MinimalAPI, BlueprintType, Blueprintable)
class UFortAthenaAIBotEvaluator_Bunker : public UFortAthenaAIBotEvaluator_Movement
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	FName BuildExecutionStatusKeyName;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	FName HealingStatusKeyName;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Danger", meta=(AllowPrivateAccess="true"))
	FGameplayTagContainer DangerTags;

};

