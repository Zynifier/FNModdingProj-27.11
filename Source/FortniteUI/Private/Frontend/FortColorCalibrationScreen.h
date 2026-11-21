// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatablePanelLegacy.h"
#include "FortColorCalibrationScreen.generated.h"

UCLASS(Abstract, meta=(DisableNativeTick))
class UFortColorCalibrationScreen : public UCommonActivatablePanelLegacy
{
	GENERATED_BODY()

private:
	UFUNCTION(BlueprintCallable, meta=(BlueprintProtected))
	void SetupForColorConfiguration();

	UFUNCTION(BlueprintCallable, meta=(BlueprintProtected))
	void SetupForFullRangeTest();

};

