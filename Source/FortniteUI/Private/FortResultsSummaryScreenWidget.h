// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "FortResultsSummaryScreenWidget.generated.h"

class UFortUIScoreReport;

UCLASS(BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortResultsSummaryScreenWidget : public UCommonUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="FortResultsSummaryScreenWidget")
	void GetTotalScoreSortedScoreIndices(const UFortUIScoreReport* ScoreReport, TArray<int32>& OutSortedScoreIndices) const;

};

