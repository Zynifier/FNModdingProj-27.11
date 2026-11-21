// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Settings/Widgets/FortSettingDetailExtension.h"
#include "FortSettingsDeadzoneExtension.generated.h"

UCLASS(Abstract, meta=(Category="Settings", DisableNativeTick))
class UFortSettingsDeadzoneExtension : public UFortSettingDetailExtension
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintPure)
	float GetDeadZoneAnalogValue() const;

	UFUNCTION(BlueprintPure)
	float GetLiveAnalogValue() const;

};

