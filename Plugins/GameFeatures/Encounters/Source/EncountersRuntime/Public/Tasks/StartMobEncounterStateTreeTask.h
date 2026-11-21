// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "StateTreeTaskBase.h"
#include "StartMobEncounterStateTreeTask.generated.h"

class AActor;

USTRUCT(meta=(Category="Encounter", DisplayName="Start Mob Encounter"))
struct FStartMobEncounterStateTreeTask : public FStateTreeTaskCommonBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Parameter")
	bool bStopEncounterOnExit;

};

USTRUCT()
struct FStartMobEncounterStateTreeTaskInstanceData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Parameter")
	FGameplayTag MobIdentifier;

	UPROPERTY(EditAnywhere, Category="Context")
	TObjectPtr<AActor> UserActor;

};

