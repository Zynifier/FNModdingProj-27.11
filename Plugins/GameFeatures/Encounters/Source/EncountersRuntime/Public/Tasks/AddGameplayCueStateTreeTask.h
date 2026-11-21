// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayCueInterface.h"
#include "StateTreeTaskBase.h"
#include "AddGameplayCueStateTreeTask.generated.h"

class AActor;

USTRUCT(meta=(Category="Encounter", DisplayName="Add Gameplay Cue"))
struct FAddGameplayCueStateTreeTask : public FStateTreeTaskCommonBase
{
	GENERATED_BODY()

};

USTRUCT()
struct FAddGameplayCueStateTreeTaskInstanceData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Parameter")
	FGameplayCueTag GameplayCue;

	UPROPERTY(EditAnywhere, Category="Parameter")
	bool bIsLooping;

	UPROPERTY(EditAnywhere, Category="Context")
	TObjectPtr<AActor> UserActor;

};

