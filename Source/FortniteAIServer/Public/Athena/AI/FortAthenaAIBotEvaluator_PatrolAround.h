// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "EnvironmentQuery/EnvQueryTypes.h"
#include "Athena/AI/FortAthenaAIBotEvaluator_Movement.h"
#include "FortAthenaAIBotEvaluator_PatrolAround.generated.h"

class AFortGameModeAthena;
class UNavigationQueryFilter;

UCLASS(BlueprintType, Blueprintable)
class UFortAthenaAIBotEvaluator_PatrolAround : public UFortAthenaAIBotEvaluator_Movement
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="EQS", meta=(AllowPrivateAccess="true"))
	FEQSParametrizedQueryExecutionRequest EQSRequest;

	UPROPERTY(EditDefaultsOnly, Category="FortAthenaAIBotEvaluator_PatrolAround", meta=(AllowPrivateAccess="true"))
	TSubclassOf<UNavigationQueryFilter> NavigationQueryFilterClass;

	UPROPERTY(EditDefaultsOnly, Category="FortAthenaAIBotEvaluator_PatrolAround", meta=(AllowPrivateAccess="true"))
	bool bFallbackToPointWithNoCustomNavigationQueryFilter;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	FName PatrolDestinationName;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	FName PatrolExecutionStatusName;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	FName PatrolMovementStateName;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	FName BestTargetActorName;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	FName EnableKeyName;

	UPROPERTY(Transient)
	TObjectPtr<AFortGameModeAthena> CacheAthenaGameMode;

};

