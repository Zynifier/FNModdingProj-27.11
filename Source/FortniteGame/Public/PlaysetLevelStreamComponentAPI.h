// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "PlaysetLevelStreamComponentAPI.generated.h"

USTRUCT(BlueprintType)
struct FApproachingActorContext
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, Category="ApproachingActorContext")
	TArray<FVector> ApproachingActorLocations;

};

