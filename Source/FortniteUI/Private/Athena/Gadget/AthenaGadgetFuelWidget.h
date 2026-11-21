// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "Attributes/Interface/FortAttributeFuelInterface.h"
#include "AthenaGadgetFuelWidget.generated.h"

class UAthenaGadgetItemDefinition;
class UCommonNumericTextBlock;
class UFortFuelGaugeIndicator;
class UFortWorldItem;

UCLASS(BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UAthenaGadgetFuelWidget : public UCommonUserWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintCallable, Category="Item")
	void SetItem(UFortWorldItem* Item);

private:
	UPROPERTY(Transient)
	TWeakObjectPtr<UAthenaGadgetItemDefinition> AthenaGadgetItemDefinition;

	UPROPERTY(Transient)
	EFortFuelGadgetVisualType FortFuelGadgetVisualType;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true", OptionalWidget="TRUE"))
	TObjectPtr<UFortFuelGaugeIndicator> FuelGaugeIndicator_Main;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true", OptionalWidget="TRUE"))
	TObjectPtr<UCommonNumericTextBlock> CurrentChargesText;

};

