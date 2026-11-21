// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "StateTreeTaskBase.h"
#include "DestroyActorsStateTreeTask.generated.h"

class AActor;

USTRUCT(meta=(Category="Encounter", DisplayName="Destroy Actors"))
struct FDestroyActorsStateTreeTask : public FStateTreeTaskCommonBase
{
	GENERATED_BODY()

};

USTRUCT()
struct FDestroyActorsStateTreeTaskInstanceData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Encounter")
	FGameplayTagQuery ActorQuery;

	UPROPERTY(EditAnywhere, Category="Context")
	TObjectPtr<AActor> UserActor;

};

