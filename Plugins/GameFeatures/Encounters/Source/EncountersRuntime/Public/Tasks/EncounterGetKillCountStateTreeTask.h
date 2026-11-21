// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "StateTreeTaskBase.h"
#include "EncounterGetKillCountStateTreeTask.generated.h"

class AActor;

USTRUCT(meta=(Category="Encounter", DisplayName="LWM Encounter [Get Kill Count]"))
struct FEncounterGetKillCountStateTreeTask : public FStateTreeTaskCommonBase
{
	GENERATED_BODY()

};

USTRUCT()
struct FEncounterGetKillCountStateTreeTaskInstanceData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Parameter")
	FGameplayTagQuery EncounterQuery;

	UPROPERTY(EditAnywhere, Category="Output")
	int32 Value;

	UPROPERTY(EditAnywhere, Category="Context")
	TObjectPtr<AActor> UserActor;

};

