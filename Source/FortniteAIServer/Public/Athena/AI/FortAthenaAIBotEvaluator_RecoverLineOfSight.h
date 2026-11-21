// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ScalableFloat.h"
#include "Athena/AI/FortAthenaAIBotEvaluator_Movement.h"
#include "FortAthenaAIBotEvaluator_RecoverLineOfSight.generated.h"

UCLASS(BlueprintType, Blueprintable)
class UFortAthenaAIBotEvaluator_RecoverLineOfSight : public UFortAthenaAIBotEvaluator_Movement
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="RecoverLineOfSight", meta=(AllowPrivateAccess="true"))
	FScalableFloat RecoveringLineOfSightMaxDuration;

	UPROPERTY(EditAnywhere, Category="RecoverLineOfSight")
	TArray<FName> ExecutionStatusToListenKeyNames;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	FName RecoverLineOfSightExecutionStatusKeyName;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	FName RecoverLineOfSightMovementStateKeyName;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	FName RecoverLineOfSightDestinationKeyName;

};

