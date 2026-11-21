// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/AI/FortAthenaAIBotEvaluator_Movement.h"
#include "FortAthenaAIBotEvaluator_TakeCover.generated.h"

class ABuildingActor;
class UAthenaAIServiceCover;
class UFortAthenaAIBotAimingDigestedSkillSet;
class UFortAthenaAIBotRangeAttackDigestedSkillSet;

UCLASS(BlueprintType, Blueprintable)
class UFortAthenaAIBotEvaluator_TakeCover : public UFortAthenaAIBotEvaluator_Movement
{
	GENERATED_BODY()

private:
	UPROPERTY(Transient)
	UFortAthenaAIBotRangeAttackDigestedSkillSet* CacheRangeAttackDigestedSkillSet;

	UPROPERTY(Transient)
	UFortAthenaAIBotAimingDigestedSkillSet* CacheAimingDigestedSkillSet;

	UPROPERTY(Transient)
	UAthenaAIServiceCover* CachedAIServiceCover;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	FName DestinationKeyName;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	FName MoveToDestinationKeyName;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	FName HealingStatusKeyName;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	FName WeaponFireName;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	FName TargetActorName;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	FName BunkerStatusKeyName;

	UPROPERTY(Transient)
	ABuildingActor* CachedCoverBuildingActor;

	UPROPERTY(Transient)
	TArray<ABuildingActor*> ExcludedBuildingActors;

};

