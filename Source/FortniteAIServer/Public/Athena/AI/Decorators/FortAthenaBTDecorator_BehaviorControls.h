// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTDecorator.h"
#include "Athena/AI/FortAthenaAISpawnerDataComponent_AIBotBehavior.h"
#include "FortAthenaBTDecorator_BehaviorControls.generated.h"

UCLASS(HideCategories=("Condition"))
class UFortAthenaBTDecorator_BehaviorControls : public UBTDecorator
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="FortAthenaBTDecorator_BehaviorControls")
	EBehaviorTreeBranches BehaviorTreeBranch;

};

