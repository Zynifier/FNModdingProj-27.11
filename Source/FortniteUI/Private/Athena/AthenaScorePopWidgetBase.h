// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortHUDElementWidget.h"
#include "AthenaScorePopWidgetBase.generated.h"

enum class EAthenaScoringEvent : uint8;

UCLASS(BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UAthenaScorePopWidgetBase : public UFortHUDElementWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION()
	void HandleNewScoreEarned(int32 NewPoints, EAthenaScoringEvent ScoreType);

	UFUNCTION(BlueprintImplementableEvent)
	void OnNewScoreEarned(int32 NewScoreValue, const FText& NewScoreTypeText, int32 BigScoreThreshold);

};

