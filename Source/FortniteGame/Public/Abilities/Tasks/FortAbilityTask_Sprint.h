// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/Tasks/AbilityTask.h"
#include "Abilities/Tasks/AbilityTask_MoveToLocation.h"
#include "FortAbilityTask_Sprint.generated.h"

UCLASS()
class UFortAbilityTask_Sprint : public UAbilityTask
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintAssignable)
	FMoveToLocationDelegate OnTargetLocationReached;

};

