// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Athena/AI/FortAthenaAIBotEvaluator_Movement.h"
#include "FortAthenaAIBotEvaluator_Escape.generated.h"

UCLASS(BlueprintType, Blueprintable)
class UFortAthenaAIBotEvaluator_Escape : public UFortAthenaAIBotEvaluator_Movement
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="Escape", meta=(AllowPrivateAccess="true"))
	FGameplayTagContainer EscapeTags;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	float CooldownBetweenAggressivenessChanges;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	FName AggressivenessName;

};

