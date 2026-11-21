// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Misc/DateTime.h"
#include "Misc/Timespan.h"
#include "RealTimeClockBlueprintLibrary.generated.h"

UCLASS()
class URealTimeClockBlueprintLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

private:
	UFUNCTION(BlueprintPure, Category="Math.Date Time")
	static FDateTime AddTimeToDate(const FDateTime& DateTime, const FTimespan& Timespan);

};

