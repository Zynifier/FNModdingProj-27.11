// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/AI/FortAthenaAIBotEvaluator.h"
#include "FortAthenaAIBotEvaluator_Observe.generated.h"

UCLASS(BlueprintType, Blueprintable)
class UFortAthenaAIBotEvaluator_Observe : public UFortAthenaAIBotEvaluator
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	FName AggressivenessName;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	FName ObserveDestinationKeyName;

	UPROPERTY(EditAnywhere, Category="FortAthenaAIBotEvaluator_Observe")
	bool bContinueMovementOnStart;

	UPROPERTY(EditAnywhere, Category="FortAthenaAIBotEvaluator_Observe")
	float MaxMovementDuration;

};

