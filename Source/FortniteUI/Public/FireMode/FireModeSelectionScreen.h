// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "FireModeSelectionScreen.generated.h"

class UCommonButtonBase;
class UCommonButtonGroupBase;
class UPanelWidget;

UCLASS(Abstract, meta=(DisableNativeTick))
class UFireModeSelectionScreen : public UCommonActivatableWidget
{
	GENERATED_BODY()

private:
	UPROPERTY()
	TObjectPtr<UCommonButtonGroupBase> ButtonGroup_FireModeTiles;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UPanelWidget> FireModeTileRow;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_Confirm;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UPanelWidget> MobileCloseButtonContainer;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_TouchClose;

};

