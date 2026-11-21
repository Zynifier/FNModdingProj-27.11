// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonInputTypeEnum.h"
#include "CommonActivatablePanelLegacy.h"
#include "FortSplashScreenWidget.generated.h"

UCLASS(Abstract, meta=(DisableNativeTick))
class UFortSplashScreenWidget : public UCommonActivatablePanelLegacy
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnInputMethodChanged(ECommonInputType InputType);

};

