// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "FortBladeMenu.generated.h"

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortBladeMenu : public UCommonActivatableWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent)
	void OnRefreshOptions();

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnClosed();

	UFUNCTION(BlueprintImplementableEvent)
	void OnOpened();

};

