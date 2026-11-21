// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "FortBladeWidget.generated.h"

UCLASS(MinimalAPI, meta=(DisableNativeTick))
class UFortBladeWidget : public UCommonUserWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnViewportResized();

};

