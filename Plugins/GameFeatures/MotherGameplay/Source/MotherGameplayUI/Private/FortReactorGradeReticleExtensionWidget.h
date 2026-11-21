// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/ReticleExtensions/FortWeaponReticleExtensionWidgetBase.h"
#include "FortReactorGradeReticleExtensionWidget.generated.h"

UCLASS(Abstract, meta=(DisableNativeTick))
class UFortReactorGradeReticleExtensionWidget : public UFortWeaponReticleExtensionWidgetBase
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnMinimumChargeReached();

	UFUNCTION(BlueprintImplementableEvent)
	void OnUpdateChargeToAutoDischarge(const float ChargePercent);

	UFUNCTION(BlueprintImplementableEvent)
	void OnUpdateChargeToMin(const float ChargePercent);

};

