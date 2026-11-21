// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "FortFuelGaugeIndicator.generated.h"

class UImage;

UCLASS(meta=(DisableNativeTick))
class UFortFuelGaugeIndicator : public UUserWidget
{
	GENERATED_BODY()

public:
	UFortFuelGaugeIndicator(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

private:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UImage> Image_FuelGauge;

	UPROPERTY(EditDefaultsOnly, Category="Cosmetic")
	FName FuelGaugeProgressMaterialParamName;

};

