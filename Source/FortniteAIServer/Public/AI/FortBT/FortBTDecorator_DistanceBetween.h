// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTDecorator.h"
#include "BehaviorTree/BehaviorTreeTypes.h"
#include "BehaviorTree/Blackboard/BlackboardKeyEnums.h"
#include "FortBTDecorator_DistanceBetween.generated.h"

UCLASS(HideCategories=("Condition"))
class UFortBTDecorator_DistanceBetween : public UBTDecorator
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Blackboard")
	TEnumAsByte<EArithmeticKeyOperation::Type> Operator;

	UPROPERTY(EditAnywhere, Category="Blackboard")
	float SpecifiedDistance;

	UPROPERTY()
	uint8 bUseSelf : 1;

	UPROPERTY(EditAnywhere, Category="Blackboard")
	uint8 bCalculateAs2D : 1;

	UPROPERTY(EditAnywhere, Category="FortBTDecorator_DistanceBetween")
	float DistanceCalculationUpdateRate;

protected:
	UPROPERTY(EditAnywhere, Category="Blackboard")
	FBlackboardKeySelector BlackboardKeyA;

	UPROPERTY(EditAnywhere, Category="Blackboard")
	FBlackboardKeySelector BlackboardKeyB;

};

