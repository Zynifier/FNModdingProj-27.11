// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Athena/AI/FortAthenaAIBotEvaluator.h"
#include "FortAthenaAIBotEvaluator_Heal.generated.h"

class UFortAthenaAIBotHealingDigestedSkillSet;

UCLASS(BlueprintType, Blueprintable)
class UFortAthenaAIBotEvaluator_Heal : public UFortAthenaAIBotEvaluator
{
	GENERATED_BODY()

private:
	UFUNCTION()
	void HandlePlayerHealthOrShieldChanged();

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	FName HealingObjectKeyName;

	UPROPERTY(EditAnywhere, Category="Tag Query", meta=(AllowPrivateAccess="true"))
	FGameplayTagQuery RequiredTagQuery;

	UPROPERTY(EditAnywhere, Category="Healing", meta=(AllowPrivateAccess="true"))
	bool bAllowEvaluationRetry;

	UPROPERTY(Transient)
	TObjectPtr<UFortAthenaAIBotHealingDigestedSkillSet> HealingSkillSet;

};

