// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/AI/FortAthenaAIBotEvaluator_Movement.h"
#include "FortAthenaNpcEvaluator_Patrolling.generated.h"

class UFortAthenaNpcPatrollingComponent;

UCLASS(BlueprintType, Blueprintable)
class FORTNITEAISERVER_API UFortAthenaNpcEvaluator_Patrolling : public UFortAthenaAIBotEvaluator_Movement
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	FName PatrollingKeyName;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	FName PatrollingMovementStateKeyName;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	FName PatrollingDestinationKeyName;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	FName DynamicBlueprintStatusKeyName;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	FName DynamicBlueprintActorKeyName;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	FName PatrollingShouldMoveKeyName;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	FName PatrollingAppendDestinationKeyName;

	UPROPERTY(EditAnywhere, Category="Patrolling", meta=(AllowPrivateAccess="true", UIMin="0.0"))
	float DistanceToTestPoint;

	UPROPERTY(EditDefaultsOnly, Category="Patrolling")
	bool bCanDisablePatrolling;

	UPROPERTY(EditDefaultsOnly, Category="Patrolling")
	bool bCanReenablePatrolling;

	UPROPERTY(EditDefaultsOnly, Category="Patrolling", meta=(EditCondition="bCanReenablePatrolling"))
	float ReenableTimer;

	UPROPERTY(EditDefaultsOnly, Category="Patrolling")
	bool bCanSelectNearestPatrolPointAtStart;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UFortAthenaNpcPatrollingComponent> CachedNpcPatrollingComponent;

};

