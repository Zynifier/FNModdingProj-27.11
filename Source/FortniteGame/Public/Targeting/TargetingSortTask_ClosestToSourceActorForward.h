// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Tasks/TargetingSortTask_Base.h"
#include "TargetingSortTask_ClosestToSourceActorForward.generated.h"

UCLASS()
class UTargetingSortTask_ClosestToSourceActorForward : public UTargetingSortTask_Base
{
	GENERATED_BODY()

public:
	UTargetingSortTask_ClosestToSourceActorForward(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

};

