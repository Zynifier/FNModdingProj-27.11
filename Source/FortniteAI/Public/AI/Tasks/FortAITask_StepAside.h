// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AI/Tasks/FortAITask_Move.h"
#include "FortAITask_StepAside.generated.h"

class AActor;

UCLASS()
class UFortAITask_StepAside : public UFortAITask_Move
{
	GENERATED_BODY()

protected:
	UPROPERTY(Transient)
	TObjectPtr<AActor> GoalActor;

};

