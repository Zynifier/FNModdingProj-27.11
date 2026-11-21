// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "AthenaItemShopTimerInfoModal.generated.h"

class UCommonButtonLegacy;

UCLASS(Abstract, meta=(DisableNativeTick))
class UAthenaItemShopTimerInfoModal : public UCommonActivatableWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintCallable)
	void ExitModal();

	UFUNCTION(BlueprintImplementableEvent)
	void OnModalBackout();

private:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_Back;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_CloseTouch;

};

