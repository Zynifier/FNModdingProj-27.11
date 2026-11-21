// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Settings/FortSettingValue.h"
#include "FortSettingValueDiscrete.generated.h"

UCLASS(Abstract)
class UFortSettingValueDiscrete : public UFortSettingValue
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	virtual TArray<FText> GetDisabledOptions() const;

	UFUNCTION(BlueprintPure)
	virtual const TArray<FText> GetDisabledOptionsReasons() const;

	UFUNCTION(BlueprintPure)
	virtual int32 GetDiscreteOptionDefaultIndex() const;

	UFUNCTION(BlueprintPure)
	virtual int32 GetDiscreteOptionIndex() const;

	UFUNCTION(BlueprintPure)
	virtual int32 GetDiscreteOptionInitialIndex() const;

	UFUNCTION(BlueprintPure)
	virtual TArray<FText> GetDiscreteOptions() const;

};

