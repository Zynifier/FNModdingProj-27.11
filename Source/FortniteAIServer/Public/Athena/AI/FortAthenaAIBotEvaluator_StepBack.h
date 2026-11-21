// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/AI/FortAthenaAIBotEvaluator_Movement.h"
#include "FortAthenaAIBotEvaluator_StepBack.generated.h"

class UAthenaAIServiceCover;
class UFortAthenaAIBotRangeAttackDigestedSkillSet;

UCLASS(BlueprintType, Blueprintable)
class UFortAthenaAIBotEvaluator_StepBack : public UFortAthenaAIBotEvaluator_Movement
{
	GENERATED_BODY()

private:
	UPROPERTY(Transient)
	UFortAthenaAIBotRangeAttackDigestedSkillSet* CachedRangeAttackDigestedSkillSet;

	UPROPERTY(Transient)
	UAthenaAIServiceCover* CachedAIServiceCover;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	FName StepBackExecutionStatusKeyName;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	FName StepBackMovementStateKeyName;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	FName StepBackDestinationKeyName;

};

