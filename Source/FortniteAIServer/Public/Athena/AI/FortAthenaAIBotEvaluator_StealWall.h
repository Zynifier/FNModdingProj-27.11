// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/AI/FortAthenaAIBotEvaluator.h"
#include "FortAthenaAIBotEvaluator_StealWall.generated.h"

class ABuildingActor;
class UFortAthenaAIBotBuildingDigestedSkillSet;

UCLASS(BlueprintType, Blueprintable)
class UFortAthenaAIBotEvaluator_StealWall : public UFortAthenaAIBotEvaluator
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	FName StealWallBuildTypeName;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	FName StealWallBuildGridCoordName;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	FName TargetActorName;

	UPROPERTY(Transient)
	TObjectPtr<UFortAthenaAIBotBuildingDigestedSkillSet> CacheBuildingDigestedSkillSet;

	UPROPERTY(Transient)
	TObjectPtr<ABuildingActor> CurrentBuildingTarget;

};

