// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/AI/FortAthenaAIBotEvaluator_Movement.h"
#include "FortAthenaAIBotEvaluator_Flee.generated.h"

class AActor;

UCLASS(BlueprintType, Blueprintable)
class UFortAthenaAIBotEvaluator_Flee : public UFortAthenaAIBotEvaluator_Movement
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Configuration", meta=(AllowPrivateAccess="true"))
	float MinDistanceFromTarget;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Configuration", meta=(AllowPrivateAccess="true"))
	float MinValidDistanceForFleeLocation;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Configuration", meta=(AllowPrivateAccess="true"))
	float FleeDistance;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Configuration", meta=(AllowPrivateAccess="true"))
	float MaxDistanceFromTargetWhenFleeing;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Configuration", meta=(AllowPrivateAccess="true"))
	float MinDistanceHysteresisWhenChangingTarget;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	FName FleeKeyName;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	FName FleeMovementStateKeyName;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	FName FleeDestinationKeyName;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	FName FleeActorKeyName;

	UPROPERTY(Transient)
	TObjectPtr<AActor> CurrentActorFleeingFrom;

};

