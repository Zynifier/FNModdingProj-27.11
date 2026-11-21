// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/AI/FortAthenaAIBotEvaluator_Movement.h"
#include "FortAthenaNpcEvaluator_Leash.generated.h"

class UFortAthenaAIRuntimeParameters_Leash;
class UNavigationQueryFilter;

UCLASS(BlueprintType, Blueprintable)
class UFortAthenaNpcEvaluator_Leash : public UFortAthenaAIBotEvaluator_Movement
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	FName LeashKeyName;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	FName LeashMovementStateKeyName;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	FName LeashDestinationKeyName;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	FName LeashLocationKeyName;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	FName LeashOuterRadiusKeyName;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	FName ShouldTeleportInLeashKeyName;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="CustomConfig", meta=(AllowPrivateAccess="true"))
	bool bAlwaysForceMoveToLeashCenter;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="CustomConfig", meta=(AllowPrivateAccess="true"))
	TSubclassOf<UNavigationQueryFilter> AvoidObstaclesFilterClass;

	UPROPERTY(Transient)
	TObjectPtr<UFortAthenaAIRuntimeParameters_Leash> LeashRuntimeParameters;

};

