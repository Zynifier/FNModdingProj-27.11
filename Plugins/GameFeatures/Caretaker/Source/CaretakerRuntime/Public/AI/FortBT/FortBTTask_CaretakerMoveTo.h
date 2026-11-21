// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BehaviorTreeTypes.h"
#include "BehaviorTree/Tasks/BTTask_MoveTo.h"
#include "AI/FortPathFollowingComponent.h"
#include "FortBTTask_CaretakerMoveTo.generated.h"

UCLASS()
class UFortBTTask_CaretakerMoveTo : public UBTTask_MoveTo
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Blackboard")
	FBlackboardKeySelector FocalPointWhileMoving;

	UPROPERTY(EditAnywhere, Category="Node")
	TEnumAsByte<EPathObstacleAction::Type> PathObstacleAction;

	UPROPERTY(EditAnywhere, Category="Node", meta=(DisplayName="Crowd Simulation Enable Slowdown At Goal"))
	uint8 bEnableSlowdownAtGoal : 1;

	UPROPERTY(EditAnywhere, Category="Node", meta=(DisplayName="Move Directly Towards Goal"))
	uint8 bMoveDirectlyTowards : 1;

	UPROPERTY(EditAnywhere, Category="Node")
	uint8 bStopAtGoal : 1;

	UPROPERTY(EditAnywhere, Config, Category="Node")
	uint8 bFinishMoveOnOverlap : 1;

};

