// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ScalableFloat.h"
#include "AI/FortAITypes.h"
#include "AI/Goals/AIGoalComponent.h"
#include "FortAIGoalComponent.generated.h"

UCLASS(MinimalAPI, HideCategories=("Trigger", "PhysicsVolume"))
class UFortAIGoalComponent : public UAIGoalComponent
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, EditFixedSize, Category="FortAIGoalComponent")
	TMap<EFortAILODLevel, FScalableFloat> AssignmentUpdatePeriods;

};

