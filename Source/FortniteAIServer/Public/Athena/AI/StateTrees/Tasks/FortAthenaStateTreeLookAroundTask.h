// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "StateTreeTaskBase.h"
#include "FortAthenaStateTreeLookAroundTask.generated.h"

class AActor;

USTRUCT(meta=(DisplayName="(Fortnite) Look Around Task"))
struct FFortAthenaStateTreeLookAroundTask : public FStateTreeTaskCommonBase
{
	GENERATED_BODY()

};

USTRUCT()
struct FFortAthenaStateTreeLookAroundTaskInstanceData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Context")
	TObjectPtr<AActor> Actor;

	UPROPERTY(EditAnywhere, Category="Parameter")
	float LookAtDurationMin;

	UPROPERTY(EditAnywhere, Category="Parameter")
	float LookAtDurationMax;

	UPROPERTY()
	float LookAtDuration;

	UPROPERTY()
	float Timer;

};

