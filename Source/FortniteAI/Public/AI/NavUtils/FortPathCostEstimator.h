// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "FortPathCostEstimator.generated.h"

class AActor;
class AFortNavigationGraph;

UCLASS()
class UFortPathCostEstimator : public UObject
{
	GENERATED_BODY()

private:
	UPROPERTY(Transient)
	TWeakObjectPtr<AActor> GoalActorWeak;

	UPROPERTY(Transient)
	TObjectPtr<AFortNavigationGraph> NavGraph;

};

