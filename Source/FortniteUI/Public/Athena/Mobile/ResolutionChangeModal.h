// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "ResolutionChangeModal.generated.h"

class UBacchusCloseButton;
class UCommonButtonBase;

UCLASS(Abstract, meta=(DisableNativeTick))
class UResolutionChangeModal : public UCommonActivatableWidget
{
	GENERATED_BODY()

private:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_Confirm;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UBacchusCloseButton> Button_TouchClose;

};

