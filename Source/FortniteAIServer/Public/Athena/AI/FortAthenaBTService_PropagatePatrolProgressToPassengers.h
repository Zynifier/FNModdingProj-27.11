// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTService.h"
#include "FortAthenaBTService_PropagatePatrolProgressToPassengers.generated.h"

UCLASS()
class UFortAthenaBTService_PropagatePatrolProgressToPassengers : public UBTService
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	FName PatrollingAppendDestinationKeyName;

};

