// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortResourceCountWidget.h"
#include "FortGlobalCashWidget.generated.h"

UCLASS(Abstract, meta=(DisableNativeTick))
class UFortGlobalCashWidget : public UFortResourceCountWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnQueryCompletedSuccessfully(int32 GlobalCashBalance);

	UFUNCTION(BlueprintImplementableEvent)
	void OnQueryFailed();

	UFUNCTION(BlueprintImplementableEvent)
	void OnQueryStarted();

};

