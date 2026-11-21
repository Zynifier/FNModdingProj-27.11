// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Items/FortPersistentTypes.h"
#include "FortEndOfDayRecap.generated.h"

USTRUCT(BlueprintType)
struct FEndOfDayRecap
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="EndOfDayRecap")
	int32 DayNumber;

	UPROPERTY(BlueprintReadOnly, Category="EndOfDayRecap")
	int32 TeamScoreAtStartOfDay;

	UPROPERTY(BlueprintReadOnly, Category="EndOfDayRecap")
	int32 TeamScoreAtEndOfDay;

	UPROPERTY(BlueprintReadOnly, Category="EndOfDayRecap")
	TArray<FFortPlayerScoreReport> ScoreReports;

};

