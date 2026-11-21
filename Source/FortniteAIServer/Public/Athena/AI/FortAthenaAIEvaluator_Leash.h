// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/AI/FortAthenaAIEvaluator.h"
#include "FortAthenaAIEvaluator_Leash.generated.h"

class UFortAIGoalComponent;
class UFortAthenaLeashComponent;

UCLASS(BlueprintType, Blueprintable)
class UFortAthenaAIEvaluator_Leash : public UFortAthenaAIEvaluator
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	FName GoalIsInsideLeashKeyName;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	FName AIIsInsideLeashKeyName;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UFortAthenaLeashComponent> CachedLeashComponent;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UFortAIGoalComponent> CachedAIGoalComponent;

};

