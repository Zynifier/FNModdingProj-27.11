// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/AI/FortAthenaAIBotEvaluator_Movement.h"
#include "FortAthenaAIBotEvaluator_Retreat.generated.h"

class UFortAthenaAIBotAttackingDigestedSkillSet;
class UFortAthenaAICoverComponent;

UCLASS(BlueprintType, Blueprintable)
class UFortAthenaAIBotEvaluator_Retreat : public UFortAthenaAIBotEvaluator_Movement
{
	GENERATED_BODY()

protected:
	UFUNCTION()
	void HandlePlayerHealthOrShieldChanged();

private:
	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	FName RetreatDestinationName;

	UPROPERTY(Transient)
	TObjectPtr<UFortAthenaAIBotAttackingDigestedSkillSet> CacheAttackingDigestedSkillSet;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UFortAthenaAICoverComponent> CachedCoverComponent;

};

