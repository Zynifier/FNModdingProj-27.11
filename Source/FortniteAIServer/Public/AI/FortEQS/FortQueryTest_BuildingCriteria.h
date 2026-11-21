// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "DataProviders/AIDataProvider.h"
#include "AI/FortAITypes.h"
#include "AI/FortEQS/FortQueryTest_GoalBase.h"
#include "FortQueryTest_BuildingCriteria.generated.h"

UCLASS(meta=(DisplayName="Goal: Building Criteria"))
class UFortQueryTest_BuildingCriteria : public UFortQueryTest_GoalBase
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="Building")
	FAIDataProviderFloatValue ScoreForGroundSupportedFloor;

	UPROPERTY(EditAnywhere, Category="Building", meta=(DisplayName="Score For Ground Supported NON-Floor"))
	FAIDataProviderFloatValue ScoreForBeingGroundSupported;

	UPROPERTY(EditAnywhere, Category="Building")
	FAIDataProviderFloatValue ScoreForTraps;

	UPROPERTY(EditAnywhere, Category="Building")
	FAIDataProviderFloatValue ScoreForWalls;

	UPROPERTY(EditAnywhere, Category="Building")
	FAIDataProviderFloatValue ScoreForNavigableOpening;

	UPROPERTY(EditAnywhere, Category="Building")
	FFortAIAssignmentIdentifier RootAssignmentID;

	UPROPERTY(EditAnywhere, Category="Building")
	FAIDataProviderBoolValue bPreferCloserToRootAssignment;

	UPROPERTY(EditAnywhere, Category="Building")
	FAIDataProviderFloatValue ScoreForDistanceFromClosestRootAssignmentGoal;

	UPROPERTY(EditAnywhere, Category="Building")
	FAIDataProviderFloatValue MinDistanceForDistanceScoring;

	UPROPERTY(EditAnywhere, Category="Building")
	FAIDataProviderFloatValue MaxDistanceForDistanceScoring;

	UPROPERTY(EditAnywhere, Category="Building")
	FAIDataProviderFloatValue MaxHealthScore;

	UPROPERTY(EditAnywhere, Category="Building")
	FAIDataProviderBoolValue bPreferHigherHealth;

	UPROPERTY(EditAnywhere, Category="Building")
	FAIDataProviderFloatValue ClampMaxHealthValue;

	UPROPERTY(EditAnywhere, Category="Building")
	FAIDataProviderFloatValue ClampMinHealthValue;

	UPROPERTY(EditAnywhere, Category="Building")
	FAIDataProviderBoolValue bPreferHigherHealthPercentage;

	UPROPERTY(EditAnywhere, Category="Building")
	FAIDataProviderFloatValue MaxHealthPercentageScore;

	UPROPERTY(EditAnywhere, Category="Building")
	FAIDataProviderBoolValue bWantsBuildingRepairableByOwner;

	UPROPERTY(EditAnywhere, Category="Building")
	FAIDataProviderFloatValue RepairableBuildingScore;

	UPROPERTY(EditAnywhere, Category="Building")
	FAIDataProviderFloatValue NotRepairableBuildingScore;

	UPROPERTY(EditAnywhere, Category="Building")
	FAIDataProviderFloatValue NeedsRepairBuildingScore;

	UPROPERTY(EditAnywhere, Category="Building")
	FAIDataProviderFloatValue DoesntNeedsRepairBuildingScore;

	UPROPERTY(EditAnywhere, Category="Building")
	FAIDataProviderBoolValue bWantsDamagedByFriendly;

	UPROPERTY(EditAnywhere, Category="Building")
	FAIDataProviderFloatValue DamagedByFriendlyMaxLifespan;

	UPROPERTY(EditAnywhere, Category="Building")
	FAIDataProviderFloatValue DamagedByFriendlyMinDamage;

	UPROPERTY(EditAnywhere, Category="Building")
	FAIDataProviderFloatValue DamagedByFriendlyScore;

	UPROPERTY(EditAnywhere, Category="Building")
	FAIDataProviderBoolValue bWantsDamagedByEnemy;

	UPROPERTY(EditAnywhere, Category="Building")
	FAIDataProviderFloatValue DamagedByEnemyMaxLifespan;

	UPROPERTY(EditAnywhere, Category="Building")
	FAIDataProviderFloatValue DamagedByEnemyMinDamage;

	UPROPERTY(EditAnywhere, Category="Building")
	FAIDataProviderFloatValue DamagedByEnemyScore;

};

