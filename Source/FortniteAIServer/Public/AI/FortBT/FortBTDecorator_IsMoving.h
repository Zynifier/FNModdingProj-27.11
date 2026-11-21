// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AI/FortAITypes.h"
#include "AI/FortBT/FortBTDecorator_QueryGameplayAbility.h"
#include "FortBTDecorator_IsMoving.generated.h"

UCLASS()
class UFortBTDecorator_IsMoving : public UFortBTDecorator_QueryGameplayAbility
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Decorator")
	float UpdateInterval;

	UPROPERTY(EditAnywhere, Category="Decorator")
	float MinTime;

	UPROPERTY(EditAnywhere, Category="Decorator", meta=(DisplayName="UseMinDistToTarget"))
	bool bUseMinDist;

	UPROPERTY(EditAnywhere, Category="Decorator", meta=(DisplayName="UseMinDistToTargetTime", EditCondition="bUseMinDist"))
	float MinDistMinTime;

	UPROPERTY(EditAnywhere, Category="Decorator", meta=(EditCondition="bUseMinDist"))
	FDistanceToTargetComparison MinDistanceComparison;

};

