// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "FortEventLevelTypes.generated.h"

USTRUCT(BlueprintType)
struct FNavWidgetSettings
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="NavWidgetSettings")
	bool bDrawNavWidget;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="NavWidgetSettings")
	float Distance;

	UPROPERTY(BlueprintReadOnly, Category="NavWidgetSettings")
	float Angle;

	UPROPERTY(EditAnywhere, Category="NavWidgetSettings")
	float MinRandomNavAngle;

	UPROPERTY(EditAnywhere, Category="NavWidgetSettings")
	float MaxRandomNavAngle;

	UPROPERTY(EditAnywhere, Category="NavWidgetSettings")
	FGameplayTag WordSetToUse;

	UPROPERTY(BlueprintReadOnly, Category="NavWidgetSettings")
	FText IndicatorTextToUse;

};

