// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/AI/FortAthenaAIBotEvaluator_Movement.h"
#include "FortAthenaNpcEvaluator_FollowPatrolPath.generated.h"

UCLASS(BlueprintType, Blueprintable)
class UFortAthenaNpcEvaluator_FollowPatrolPath : public UFortAthenaAIBotEvaluator_Movement
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	FName FollowPatrolPathKeyName;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	FName FollowPatrolPathMovementStateKeyName;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	FName FollowPatrolPathDestinationKeyName;

	UPROPERTY(EditAnywhere, Category="Patrolling", meta=(AllowPrivateAccess="true", UIMax="1.0", UIMin="0.0"))
	float ChanceToTakeABreak;

	UPROPERTY(EditAnywhere, Category="Patrolling", meta=(AllowPrivateAccess="true", UIMin="0.0"))
	float BreakDurationMin;

	UPROPERTY(EditAnywhere, Category="Patrolling", meta=(AllowPrivateAccess="true", UIMin="0.0"))
	float BreakDurationMax;

};

