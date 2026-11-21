// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/Vehicles/OstrichAlertWidgetBase.h"
#include "OstrichAlertWidgetDriver.generated.h"

UCLASS(Abstract, meta=(DisableNativeTick))
class UOstrichAlertWidgetDriver : public UOstrichAlertWidgetBase
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnDriverDashAbilityBlocked();

	UFUNCTION(BlueprintImplementableEvent)
	void OnDriverJumpAbilityBlocked();

	UFUNCTION(BlueprintImplementableEvent)
	void OnDriverStompAbilityBlocked();

};

