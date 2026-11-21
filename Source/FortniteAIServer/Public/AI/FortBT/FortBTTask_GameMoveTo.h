// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BehaviorTreeTypes.h"
#include "BehaviorTree/Tasks/BTTask_MoveTo.h"
#include "GameplayTagContainer.h"
#include "AI/FortPathFollowingComponent.h"
#include "FortBTTask_GameMoveTo.generated.h"

class AFortPawn;

UCLASS()
class UFortBTTask_GameMoveTo : public UBTTask_MoveTo
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Blackboard")
	FBlackboardKeySelector FocalPointWhileMoving;

	UPROPERTY(EditAnywhere, Category="Node")
	TEnumAsByte<EPathObstacleAction::Type> PathObstacleAction;

	UPROPERTY(EditAnywhere, Category="Node")
	TSubclassOf<AFortPawn> PushBumpedPawnClass;

	UPROPERTY(EditAnywhere, Category="Node")
	FGameplayTag NavFilterTag;

	UPROPERTY(EditAnywhere, Category="Node")
	uint8 bDetectUnexpectedPathBlockingObstacles : 1;

	UPROPERTY(EditAnywhere, Category="Node", meta=(DisplayName="Crowd Simulation Enable Slowdown At Goal"))
	uint8 bEnableSlowdownAtGoal : 1;

	UPROPERTY(EditAnywhere, Category="Node")
	uint8 bStopAtGoal : 1;

	UPROPERTY(EditAnywhere, Config, Category="Node")
	uint8 bFinishMoveOnOverlap : 1;

	UPROPERTY(EditAnywhere, Category="Node")
	FBlackboardKeySelector AcceptableRadiusKey;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Node")
	uint8 bDeimosFlavor : 1;

};

