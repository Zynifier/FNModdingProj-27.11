// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Misc/Timespan.h"
#include "FortTimespanDataSource.generated.h"

class UObject;

UDELEGATE()
DECLARE_DYNAMIC_DELEGATE_OneParam(FFortTimespanDataSourceOnChangeDelegate, UObject*, Source);

UINTERFACE(BlueprintType)
class UFortTimespanDataSource : public UInterface
{
	GENERATED_BODY()
};

class IFortTimespanDataSource
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="Timespan")
	void AddOnChangeDelegate(const FFortTimespanDataSourceOnChangeDelegate& InDelegate);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="Timespan")
	FTimespan GetValue() const;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="Timespan")
	void RemoveOnChangeDelegate(const FFortTimespanDataSourceOnChangeDelegate& InDelegate);

};

