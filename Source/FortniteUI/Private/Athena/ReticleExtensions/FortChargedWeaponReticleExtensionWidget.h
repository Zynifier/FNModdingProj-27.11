// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/ReticleExtensions/FortWeaponReticleExtensionWidgetBase.h"
#include "FortChargedWeaponReticleExtensionWidget.generated.h"

UCLASS(Abstract, meta=(DisableNativeTick))
class UFortChargedWeaponReticleExtensionWidget : public UFortWeaponReticleExtensionWidgetBase
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnUpdateChargeDisplay(float ChargePercent);

private:
	UPROPERTY(EditDefaultsOnly, Category="FortChargedWeaponReticleExtensionWidget")
	float UpdateFrequencySecs;

};

