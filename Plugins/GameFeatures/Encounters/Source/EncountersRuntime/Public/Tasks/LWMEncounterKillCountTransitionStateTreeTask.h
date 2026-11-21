// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "StateTreeTaskBase.h"
#include "StateTreeTypes.h"
#include "LWMEncounterKillCountTransitionStateTreeTask.generated.h"

class AActor;

USTRUCT(meta=(Category="Encounter", DisplayName="LWM Encounter [Kill Count Transition]"))
struct FLWMEncounterKillCountTransitionStateTreeTask : public FStateTreeTaskCommonBase
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="Parameter")
	FStateTreeStateLink TransitionTo;

};

USTRUCT()
struct FLWMEncounterKillCountTransitionStateTreeTaskInstanceData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Parameter")
	FGameplayTagQuery EncounterQuery;

	UPROPERTY(EditAnywhere, Category="Parameter")
	uint32 Value;

	UPROPERTY(EditAnywhere, Category="Context")
	TObjectPtr<AActor> UserActor;

};

