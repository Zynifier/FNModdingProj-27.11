// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonButtonBase.h"
#include "FortActivityPrivacyButton.generated.h"

UCLASS(Abstract, MinimalAPI, meta=(DisableNativeTick))
class UFortActivityPrivacyButton : public UCommonButtonBase
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnDesiredPrivacySelectionChanged(const bool bIsSelected);

	UFUNCTION(BlueprintImplementableEvent)
	void OnPrivacyAvailabilityChanged(const bool bIsAvailable);

};

