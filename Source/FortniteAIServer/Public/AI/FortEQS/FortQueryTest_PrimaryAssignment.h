// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "DataProviders/AIDataProvider.h"
#include "AI/FortEQS/FortQueryTest_GoalBase.h"
#include "FortQueryTest_PrimaryAssignment.generated.h"

UCLASS(HideCategories=("Condition"))
class UFortQueryTest_PrimaryAssignment : public UFortQueryTest_GoalBase
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="PrimaryAssignment", meta=(ClampMin="0", UIMin="0"))
	bool bUseItemActorLocation;

	UPROPERTY(EditAnywhere, Category="PrimaryAssignment", meta=(ClampMin="0", UIMin="0"))
	FAIDataProviderFloatValue DistanceClose;

	UPROPERTY(EditAnywhere, Category="PrimaryAssignment", meta=(ClampMin="0", UIMin="0"))
	FAIDataProviderFloatValue DistanceFar;

	UPROPERTY(EditAnywhere, Category="PrimaryAssignment", meta=(ClampMin="0", UIMin="0"))
	FAIDataProviderFloatValue PercentValueClose;

	UPROPERTY(EditAnywhere, Category="PrimaryAssignment", meta=(ClampMin="0", UIMin="0"))
	FAIDataProviderFloatValue PercentValueRegular;

	UPROPERTY(EditAnywhere, Category="PrimaryAssignment", meta=(ClampMin="0", UIMin="0"))
	FAIDataProviderFloatValue PercentValueFar;

};

