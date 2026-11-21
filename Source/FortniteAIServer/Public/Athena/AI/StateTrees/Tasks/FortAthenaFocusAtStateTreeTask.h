// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "StateTreeTaskBase.h"
#include "FortAthenaFocusAtStateTreeTask.generated.h"

class AActor;

USTRUCT(meta=(DisplayName="(Fortnite) Focus a specific Actor and/or point/location"))
struct FFortAthenaFocusAtStateTreeTask : public FStateTreeTaskCommonBase
{
	GENERATED_BODY()

};

USTRUCT()
struct FFortAthenaFocusAtStateTreeTaskInstanceData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Context")
	TObjectPtr<AActor> Actor;

	UPROPERTY(EditAnywhere, Category="Parameter")
	TObjectPtr<AActor> FocusActor;

	UPROPERTY(EditAnywhere, Category="Parameter")
	FVector FocusActorOffset;

	UPROPERTY(EditAnywhere, Category="Parameter")
	FVector FocusWorldPoint;

	UPROPERTY(EditAnywhere, Category="Parameter")
	bool bSetBackOnExit;

};

