// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "StateTreeTaskBase.h"
#include "Athena/AI/StateTrees/Tasks/FortAthenaStateTreeTaskTypes.h"
#include "FortAthenaToggleAllowInteractStateTreeTask.generated.h"

class AActor;

USTRUCT()
struct FFortAthenaToggleAllowInteractStateTreeTaskInstanceData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Context")
	TObjectPtr<AActor> Actor;

	UPROPERTY(EditAnywhere, Category="Context")
	TObjectPtr<AActor> TargetActor;

};

USTRUCT(meta=(DisplayName="(Fortnite) Add/Remove Allowed Actor for Interaction"))
struct FFortAthenaToggleAllowInteractStateTreeTaskTreeTask : public FStateTreeTaskCommonBase
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, Category="Parameter")
	EFortAthenaStateTreeTaskFeatureExecutionMode AddExecutionMode;

	UPROPERTY(EditAnywhere, Category="Parameter")
	EFortAthenaStateTreeTaskFeatureExecutionMode RemoveExecutionMode;

};

