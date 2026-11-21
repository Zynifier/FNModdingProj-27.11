// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "StateTreeTaskBase.h"
#include "FortInteractInterface.h"
#include "FortAthenaStateTreeInteractTask.generated.h"

class AActor;

USTRUCT(meta=(DisplayName="(Fortnite) Interact Task"))
struct FFortAthenaStateTreeInteractTask : public FStateTreeTaskCommonBase
{
	GENERATED_BODY()

};

USTRUCT()
struct FFortAthenaStateTreeInteractTaskInstanceData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Parameter")
	TEnumAsByte<TInteractionType> InteractType;

	UPROPERTY(EditAnywhere, Category="Context")
	TObjectPtr<AActor> Actor;

	UPROPERTY(EditAnywhere, Category="Parameter")
	TObjectPtr<AActor> InteractTargetActor;

	UPROPERTY()
	float InteractDuration;

	UPROPERTY()
	float Timer;

};

