// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/Inventory/AthenaQuickBarSlotExtensionWidgetBase.h"
#include "FortWeaponFuelGaugeIndicator.generated.h"

class UFortFuelGaugeIndicator;
class UFortWorldItem;

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortWeaponFuelGaugeIndicator : public UAthenaQuickBarSlotExtensionWidgetBase
{
	GENERATED_BODY()

private:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortFuelGaugeIndicator> FuelGaugeIndicator_Main;

	UPROPERTY(Transient)
	TObjectPtr<UFortWorldItem> RepresentedItem;

};

