// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "FireModeSelectionReminderModal.generated.h"

class UCommonButtonBase;

UCLASS(Abstract, meta=(DisableNativeTick))
class UFireModeSelectionReminderModal : public UCommonActivatableWidget
{
	GENERATED_BODY()

private:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	UCommonButtonBase* Button_Confirm;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	UCommonButtonBase* Button_Cancel;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	UCommonButtonBase* Button_TouchClose;

};

