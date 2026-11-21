// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BehaviorTree/BehaviorTreeTypes.h"
#include "FortAthenaBTTask_SteerMovement.generated.h"

UCLASS()
class UFortAthenaBTTask_SteerMovement : public UBTTaskNode
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="Blackboard", meta=(DisplayName="Steer Direction Key"))
	FBlackboardKeySelector SteerDirectionKeySelector;

	UPROPERTY(EditAnywhere, Category="Steer Movement")
	uint8 bSetControlRotation : 1;

};

