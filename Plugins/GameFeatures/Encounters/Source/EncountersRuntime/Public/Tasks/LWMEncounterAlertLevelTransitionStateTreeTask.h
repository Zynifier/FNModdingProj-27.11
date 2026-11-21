// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "StateTreeTaskBase.h"
#include "StateTreeTypes.h"
#include "Athena/AI/FortPlayerBotUtils.h"
#include "Tasks/LWMEncounterInstance.h"
#include "LWMEncounterAlertLevelTransitionStateTreeTask.generated.h"

class AActor;

USTRUCT(meta=(Category="Encounter", DisplayName="LWM Encounter [Alert Level Transition]"))
struct FLWMEncounterAlertLevelTransitionStateTreeTask : public FStateTreeTaskCommonBase
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="Parameter")
	FStateTreeStateLink TransitionTo;

};

USTRUCT()
struct FLWMEncounterAlertLevelTransitionStateTreeTaskInstanceData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Parameter")
	FGameplayTagQuery EncounterQuery;

	UPROPERTY(EditAnywhere, Category="Parameter")
	TArray<EAlertLevel> AlertLevels;

	UPROPERTY(EditAnywhere, Category="Parameter")
	EAlertLevelComparisonOperator ComparisonOperator;

	UPROPERTY(EditAnywhere, Category="Parameter")
	int32 Value;

	UPROPERTY(EditAnywhere, Category="Context")
	TObjectPtr<AActor> UserActor;

};

