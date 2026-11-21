// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "DataProviders/AIDataProvider.h"
#include "AI/FortEQS/FortQueryTest_GoalBase.h"
#include "FortQueryTest_PickupDropper.generated.h"

UCLASS(MinimalAPI)
class UFortQueryTest_PickupDropper : public UFortQueryTest_GoalBase
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, Category="CurrentGoal", meta=(ClampMin="0", UIMin="0"))
	FAIDataProviderFloatValue ValueConverterDroppedPickup;

	UPROPERTY(EditAnywhere, Category="CurrentGoal", meta=(ClampMin="0", UIMin="0"))
	FAIDataProviderFloatValue ValueOtherDroppedPickupInitial;

	UPROPERTY(EditAnywhere, Category="CurrentGoal", meta=(ClampMin="0", UIMin="0"))
	FAIDataProviderFloatValue ValueOtherDroppedPickupFinal;

	UPROPERTY(EditAnywhere, Category="CurrentGoal", meta=(ClampMin="0", UIMin="0"))
	FAIDataProviderFloatValue TimeOtherDroppedPickupFinal;

	UPROPERTY(EditAnywhere, Category="CurrentGoal")
	FAIDataProviderBoolValue LerpFromInitialToFinal;

};

