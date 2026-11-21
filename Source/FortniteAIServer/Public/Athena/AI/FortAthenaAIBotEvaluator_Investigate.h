// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/AI/FortAthenaAIBotEvaluator_Movement.h"
#include "FortAthenaAIBotEvaluator_Investigate.generated.h"

class AActor;
class ABuildingSMActor;
class UFortAthenaAIBotAimingDigestedSkillSet;
class UFortAthenaAIBotAttackingDigestedSkillSet;
class UFortAthenaAIBotUnstuckDigestedSkillSet;
class UNavigationQueryFilter;

UCLASS(BlueprintType, Blueprintable)
class UFortAthenaAIBotEvaluator_Investigate : public UFortAthenaAIBotEvaluator_Movement
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	FName LastKnownPositionName;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	FName DestinationKeyName;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	FName MoveToDestinationKeyName;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	FName AggressivenessName;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	FName CautiousKeyName;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	FName AlertLevelName;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Search")
	TSubclassOf<UNavigationQueryFilter> SearchQueryFilterClass;

	UPROPERTY(Transient)
	UFortAthenaAIBotAimingDigestedSkillSet* CacheAimingDigestedSkillSet;

	UPROPERTY(Transient)
	UFortAthenaAIBotAttackingDigestedSkillSet* CacheAttackingDigestedSkillSet;

	UPROPERTY(Transient)
	UFortAthenaAIBotUnstuckDigestedSkillSet* CachedUnstuckSkillSet;

	UPROPERTY(Transient)
	AActor* InvestigatingSupportingActor;

	UPROPERTY(Transient)
	ABuildingSMActor* UnderminingBuildingActor;

	UPROPERTY(Transient)
	AActor* ExcludeReachingTarget;

};

