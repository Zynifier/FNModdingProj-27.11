// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "StateTreeTaskBase.h"
#include "Athena/AI/StateTrees/Tasks/FortAthenaStateTreeTaskTypes.h"
#include "FortAthenaAddGameplayTagsStateTreeTask.generated.h"

class AActor;

USTRUCT(meta=(DisplayName="(Fortnite) Add/Remove GameplayTag to Actor"))
struct FFortAthenaAddGameplayTagsStateTreeTask : public FStateTreeTaskCommonBase
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, Category="Parameter")
	bool bReplicateChange;

	UPROPERTY(EditAnywhere, Category="Parameter")
	EFortAthenaStateTreeTaskFeatureExecutionMode AddExecutionMode;

	UPROPERTY(EditAnywhere, Category="Parameter")
	EFortAthenaStateTreeTaskFeatureExecutionMode RemoveExecutionMode;

};

USTRUCT()
struct FFortAthenaAddGameplayTagsStateTreeTaskInstanceData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Context")
	TObjectPtr<AActor> Actor;

	UPROPERTY(EditAnywhere, Category="Parameter")
	FGameplayTagContainer Tags;

};

