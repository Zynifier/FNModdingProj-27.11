// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/Vehicles/OstrichAlertWidgetBase.h"
#include "OstrichAlertWidgetGunner.generated.h"

UCLASS(Abstract, meta=(DisableNativeTick))
class UOstrichAlertWidgetGunner : public UOstrichAlertWidgetBase
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnGunnerMissilesBlocked();

	UFUNCTION(BlueprintImplementableEvent)
	void OnGunnerShotgunBlocked();

};

