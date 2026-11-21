// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "FortPlayedBeforeSelect.generated.h"

class UBackgroundBlur;
class UCommonButtonLegacy;

UCLASS(Abstract, meta=(DisableNativeTick))
class UFortPlayedBeforeSelect : public UCommonActivatableWidget
{
	GENERATED_BODY()

private:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_Yes;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_No;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UBackgroundBlur> BackgroundBlur_PendingSpinner;

};

