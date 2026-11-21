// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/GameFrameworkComponent.h"
#include "AIGoalComponent.generated.h"

USTRUCT(BlueprintType)
struct FGoalUpdateSuppressionHandle
{
	GENERATED_BODY()

};

UCLASS(MinimalAPI, HideCategories=("Trigger", "PhysicsVolume"))
class UAIGoalComponent : public UGameFrameworkComponent
{
	GENERATED_BODY()

public:
	UAIGoalComponent(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

};

