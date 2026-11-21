// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "FortAIGoal.generated.h"

class AActor;

USTRUCT(BlueprintType)
struct FFortAIGoalInfo
{
	GENERATED_BODY()

protected:
	UPROPERTY(Transient)
	TWeakObjectPtr<AActor> Actor;

	UPROPERTY(Transient)
	FVector Location;

	UPROPERTY(Transient)
	bool bActorAlwaysPerceived;

};

USTRUCT(BlueprintType)
struct FFortAIGoal : public FFortAIGoalInfo
{
	GENERATED_BODY()

};

