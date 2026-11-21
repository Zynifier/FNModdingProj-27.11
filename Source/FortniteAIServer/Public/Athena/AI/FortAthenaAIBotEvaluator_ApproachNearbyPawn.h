// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ScalableFloat.h"
#include "Athena/AI/FortAthenaAIBotEvaluator_Movement.h"
#include "FortNearbyActorsPerceptionComponent.h"
#include "FortAthenaAIBotEvaluator_ApproachNearbyPawn.generated.h"

UCLASS(MinimalAPI, BlueprintType, Blueprintable)
class UFortAthenaAIBotEvaluator_ApproachNearbyPawns : public UFortAthenaAIBotEvaluator_Movement
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Category="FortAthenaAIBotEvaluator_ApproachNearbyPawns", meta=(AllowPrivateAccess="true"))
	FScalableFloat MaxApproaches;

	UPROPERTY(EditDefaultsOnly, Category="FortAthenaAIBotEvaluator_ApproachNearbyPawns", meta=(AllowPrivateAccess="true"))
	FFortNearbyActorsPerceptionConfiguration PerceptionConfiguration;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	FName EnableKeyName;

};

