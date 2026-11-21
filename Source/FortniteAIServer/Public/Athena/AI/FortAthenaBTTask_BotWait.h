// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BehaviorTreeTypes.h"
#include "BehaviorTree/Tasks/BTTask_Wait.h"
#include "FortAthenaBTTask_BotWait.generated.h"

UCLASS()
class UFortAthenaBTTask_BotWait : public UBTTask_Wait
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="Blackboard")
	FBlackboardKeySelector WaitCompleteKeySelector;

};

