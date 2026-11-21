// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/AI/FortAthenaAIBotEvaluator.h"
#include "FortAthenaAIBotEvaluator_DefensiveBuilding.generated.h"

class UFortAthenaAIBotBuildingComponent;
class UFortAthenaAIBotBuildingDigestedSkillSet;

UCLASS(BlueprintType, Blueprintable)
class UFortAthenaAIBotEvaluator_DefensiveBuilding : public UFortAthenaAIBotEvaluator
{
	GENERATED_BODY()

private:
	UPROPERTY(Transient)
	TObjectPtr<UFortAthenaAIBotBuildingDigestedSkillSet> CachedBuildingDigestedSkillSet;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UFortAthenaAIBotBuildingComponent> CachedBuildingComponent;

};

