// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "AthenaServerShutdownWidget.generated.h"

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UAthenaShutdownWidget : public UCommonUserWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnStartShowing(float RemainingTime);

	UFUNCTION(BlueprintImplementableEvent)
	void OnStopShowing(float RemainingTime);

	UFUNCTION(BlueprintImplementableEvent)
	void OnUpdateCountdown(float RemainingTime);

};

