// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/AI/FortAthenaAIBotEvaluator_Movement.h"
#include "FortAthenaAIBotEvaluator_Flanking.generated.h"

class AActor;
class AFortAIDirector;
class UFortAthenaAIBotRangeAttackDigestedSkillSet;

USTRUCT()
struct FFlankingLocationInfo
{
	GENERATED_BODY()

};

UCLASS(BlueprintType, Blueprintable)
class UFortAthenaAIBotEvaluator_Flanking : public UFortAthenaAIBotEvaluator_Movement
{
	GENERATED_BODY()

private:
	UPROPERTY(Transient)
	TObjectPtr<AFortAIDirector> CachedAIDirector;

	UPROPERTY(Transient)
	TObjectPtr<UFortAthenaAIBotRangeAttackDigestedSkillSet> CachedRangeAttackDigestedSkillSet;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	FName FlankingExecutionStatusKeyName;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	FName FlankingMovementStateKeyName;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	FName FlankingDestinationKeyName;

	UPROPERTY(Transient)
	TArray<FFlankingLocationInfo> LocationsToEvaluate;

	UPROPERTY(Transient)
	TArray<FFlankingLocationInfo> BestLocations;

	UPROPERTY(Transient)
	TArray<TWeakObjectPtr<AActor>> ActorsInArea;

};

