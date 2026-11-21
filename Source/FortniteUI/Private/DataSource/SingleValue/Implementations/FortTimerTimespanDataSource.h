// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Misc/Timespan.h"
#include "UObject/NoExportTypes.h"
#include "DataSource/SingleValue/FortTimespanDataSource.h"
#include "FortTimerTimespanDataSource.generated.h"

class UObject;

UCLASS(BlueprintType)
class UFortTimerTimespanDataSource : public UObject, public IFortTimespanDataSource
{
	GENERATED_BODY()

public:
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FFortTimespanDataSourceOnChangeInternalDelegate, UObject*, Source);
UDELEGATE()
DECLARE_DYNAMIC_DELEGATE_OneParam(FTimespanSourceDelegate, FTimespan&, Result);

public:
	UFUNCTION(BlueprintCallable, Category="Timespan")
	void SetTimespanSource(const FTimespanSourceDelegate& Value);

	UFUNCTION(BlueprintCallable, Category="Timespan")
	void StartTimer(float Delay = 1.000000f, bool bTickImmediately = true);

	UFUNCTION(BlueprintCallable, Category="Timespan")
	void StopTimer();

	UFUNCTION(BlueprintCallable, Category="Timespan")
	void TickManually();

};

