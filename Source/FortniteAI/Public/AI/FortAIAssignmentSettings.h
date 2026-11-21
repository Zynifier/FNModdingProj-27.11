// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "GameplayTagContainer.h"
#include "FortAIAssignmentSettings.generated.h"

class UEnvQuery;

USTRUCT()
struct FGoalSelectionQueryInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="AssignmentSettings")
	TObjectPtr<UEnvQuery> GoalSelectionQuery;

	UPROPERTY(EditAnywhere, Category="AssignmentSettings")
	FGameplayTagContainer RequiredGameplayTags;

};

UCLASS(BlueprintType)
class UFortAIAssignmentSettings : public UDataAsset
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="AssignmentSettings")
	TArray<FGoalSelectionQueryInfo> GoalSelectionQueryInfos;

	UPROPERTY(EditAnywhere, Category="AssignmentSettings")
	bool bGoalLocationsAlwaysKnown;

	UPROPERTY(EditAnywhere, Category="AssignmentSettings")
	bool bIsEnemyAssignment;

	UPROPERTY(EditAnywhere, Category="Assignment")
	FGameplayTagContainer RequiredTags;

	UPROPERTY(EditAnywhere, Category="Assignment")
	FGameplayTagContainer ProhibitedTags;

	UPROPERTY(EditAnywhere, Category="AssignmentSettings")
	float MaxAIAllowedForAssignment;

	UPROPERTY(EditAnywhere, Category="AssignmentSettings")
	float MaxAIAllowedPerGoal;

};

