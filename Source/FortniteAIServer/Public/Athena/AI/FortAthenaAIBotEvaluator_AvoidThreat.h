// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/AI/FortAthenaAIBotEvaluator_Movement.h"
#include "FortAthenaAIBotEvaluator_AvoidThreat.generated.h"

class AActor;
class UFortAthenaAIBotEvasiveManeuversDigestedSkillSet;

UCLASS(BlueprintType, Blueprintable)
class UFortAthenaAIBotEvaluator_AvoidThreat : public UFortAthenaAIBotEvaluator_Movement
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	FName AvoidThreatKeyName;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	FName AvoidThreatMovementStateKeyName;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	FName AvoidThreatDestinationKeyName;

	UPROPERTY(Transient)
	TObjectPtr<AActor> CurrentThreatActorAvoiding;

	UPROPERTY(Transient)
	TObjectPtr<UFortAthenaAIBotEvasiveManeuversDigestedSkillSet> CacheEMDigestedSkillSet;

};

