// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTService.h"
#include "FortAthenaBTService_Patrolling.generated.h"

class UNavigationQueryFilter;

UCLASS(Config=Game, HideCategories=("Service"))
class UFortAthenaBTService_Patrolling : public UBTService
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	FName PatrollingAppendDestinationKeyName;

	UPROPERTY(EditAnywhere, Config, Category="Node", meta=(ClampMin="0.0", UIMin="0.0"))
	float AcceptableRadius;

	UPROPERTY(EditAnywhere, Category="Node")
	TSubclassOf<UNavigationQueryFilter> FilterClass;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Node")
	uint8 bAllowPartialPath : 1;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Node")
	uint8 bProjectGoalLocation : 1;

};

