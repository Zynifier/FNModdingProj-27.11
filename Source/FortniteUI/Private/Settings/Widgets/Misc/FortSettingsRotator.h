// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonRotator.h"
#include "FortSettingsRotator.generated.h"

UCLASS(Abstract, meta=(Category="Settings", DisableNativeTick))
class UFortSettingsRotator : public UCommonRotator
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent, Category="Events", meta=(DisplayName="On Default Option Specified"))
	void BP_OnDefaultOptionSpecified(int32 DefaultOptionIndex);

	UPROPERTY(EditDefaultsOnly, Category="Input")
	bool bDisableNavigationControl;

};

