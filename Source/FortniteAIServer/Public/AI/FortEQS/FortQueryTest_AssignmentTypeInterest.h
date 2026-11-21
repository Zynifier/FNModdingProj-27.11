// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "DataProviders/AIDataProvider.h"
#include "AI/FortEQS/FortQueryTest_GoalBase.h"
#include "FortQueryTest_AssignmentTypeInterest.generated.h"

UCLASS(meta=(DisplayName="Goal: Assignment Switching Interest"))
class UFortQueryTest_AssignmentTypeInterest : public UFortQueryTest_GoalBase
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, Category="CurrentGoal", meta=(ClampMax="1.0", ClampMin="0", UIMax="1.0", UIMin="0"))
	FAIDataProviderFloatValue InvalidTypeStartInterest;

	UPROPERTY(EditAnywhere, Category="CurrentGoal", meta=(ClampMax="1.0", ClampMin="0", UIMax="1.0", UIMin="0"))
	FAIDataProviderFloatValue InvalidTypeEndInterest;

	UPROPERTY(EditAnywhere, Category="CurrentGoal", meta=(ClampMin="0", UIMin="0"))
	FAIDataProviderFloatValue InvalidTypeTimeBeforeLerp;

	UPROPERTY(EditAnywhere, Category="CurrentGoal", meta=(ClampMin="0", UIMin="0"))
	FAIDataProviderFloatValue InvalidTypeLerpDuration;

	UPROPERTY(EditAnywhere, Category="CurrentGoal", meta=(ClampMax="1.0", ClampMin="0", UIMax="1.0", UIMin="0"))
	FAIDataProviderFloatValue ValidTypeStartInterest;

	UPROPERTY(EditAnywhere, Category="CurrentGoal", meta=(ClampMax="1.0", ClampMin="0", UIMax="1.0", UIMin="0"))
	FAIDataProviderFloatValue ValidTypeEndInterest;

	UPROPERTY(EditAnywhere, Category="CurrentGoal", meta=(ClampMin="0", UIMin="0"))
	FAIDataProviderFloatValue ValidTypeTimeBeforeLerp;

	UPROPERTY(EditAnywhere, Category="CurrentGoal", meta=(ClampMin="0", UIMin="0"))
	FAIDataProviderFloatValue ValidTypeLerpDuration;

};

