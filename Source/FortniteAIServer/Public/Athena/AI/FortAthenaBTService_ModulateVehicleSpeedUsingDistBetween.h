// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTService.h"
#include "BehaviorTree/BehaviorTreeTypes.h"
#include "FortAthenaBTService_ModulateVehicleSpeedUsingDistBetween.generated.h"

UCLASS()
class UFortAthenaBTService_ModulateVehicleSpeedUsingDistBetween : public UBTService
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, Category="Blackboard")
	FBlackboardKeySelector BlackboardKeyA;

	UPROPERTY(EditAnywhere, Category="Blackboard")
	FBlackboardKeySelector BlackboardKeyB;

	UPROPERTY(EditAnywhere, Category="Distance", meta=(ClampMin="0.0"))
	float MinDistance;

	UPROPERTY(EditAnywhere, Category="Distance", meta=(ClampMin="0.0"))
	float MaxDistance;

	UPROPERTY(EditAnywhere, Category="Speed", meta=(ClampMin="0.0"))
	float MinDistanceSpeed;

	UPROPERTY(EditAnywhere, Category="Speed", meta=(ClampMin="0.0"))
	float MaxDistanceSpeed;

	UPROPERTY(EditAnywhere, Category="Blackboard")
	bool bCalculateAs2D;

};

