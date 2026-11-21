// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "InstancedStruct.h"
#include "StateTreeTaskBase.h"
#include "StateTreeTypes.h"
#include "EncounterVerbTransitionStateTreeTask.generated.h"

class AActor;

USTRUCT(meta=(Category="Encounter", DisplayName="Verb Transition"))
struct FEncounterVerbTransitionStateTreeTask : public FStateTreeTaskCommonBase
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="Parameter")
	FStateTreeStateLink TransitionTo;

};

USTRUCT()
struct FEncounterVerbTransitionStateTreeTaskInstanceData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Parameter", meta=(BaseStruct="/Script/FortniteGame.ObjectiveFilter", ExcludeBaseStruct))
	TArray<FInstancedStruct> ObjectiveVerbs;

	UPROPERTY(EditAnywhere, Category="Parameter", meta=(DisplayName="Count"))
	int32 ObjectiveValueThreshold;

	UPROPERTY(EditAnywhere, Category="Context")
	TObjectPtr<AActor> UserActor;

};

