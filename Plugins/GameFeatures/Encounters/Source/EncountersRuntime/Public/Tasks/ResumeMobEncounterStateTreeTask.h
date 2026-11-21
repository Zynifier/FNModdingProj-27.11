// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "StateTreeTaskBase.h"
#include "ResumeMobEncounterStateTreeTask.generated.h"

class AActor;

USTRUCT(meta=(Category="Encounter", DisplayName="Resume Mob Encounter"))
struct FResumeMobEncounterStateTreeTask : public FStateTreeTaskCommonBase
{
	GENERATED_BODY()

};

USTRUCT()
struct FResumeMobEncounterStateTreeTaskInstanceData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Parameter")
	FGameplayTag MobIdentifier;

	UPROPERTY(EditAnywhere, Category="Context")
	TObjectPtr<AActor> UserActor;

};

