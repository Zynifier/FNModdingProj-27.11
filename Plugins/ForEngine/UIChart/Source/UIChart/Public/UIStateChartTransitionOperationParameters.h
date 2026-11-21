// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "UIStateTransitionUrgency.h"
#include "UIStateChartTransitionOperationParameters.generated.h"

USTRUCT()
struct UICHART_API FUIStateChartTransitionOperationParameters
{
	GENERATED_BODY()

protected:
	UPROPERTY()
	FGameplayTagContainer AnimationHints;

	UPROPERTY()
	EUIStateTransitionUrgency Urgency;

};

