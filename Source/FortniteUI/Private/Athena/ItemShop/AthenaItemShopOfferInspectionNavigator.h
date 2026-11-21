// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "AthenaItemShopOfferInspectionNavigator.generated.h"

class UCommonActivatableWidget;
class UCommonButtonLegacy;

UCLASS(Abstract, meta=(DisableNativeTick))
class UAthenaItemShopOfferInspectionNavigator : public UCommonActivatableWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Navigation Arrows")
	void RequestNextOffer();

	UFUNCTION(BlueprintCallable, Category="Navigation Arrows")
	void RequestPreviousOffer();

	UFUNCTION(BlueprintCallable, Category="Navigation Arrows")
	void SetArrowsEnabled(bool bEnabled);

private:
	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UCommonActivatableWidget> OwningOfferInspectionWidget;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_Next;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_Previous;

};

