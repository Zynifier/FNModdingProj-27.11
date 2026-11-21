// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "FortVariantListPreviewWidget.generated.h"

class UCommonBorder;
class UCommonTextBlock;
class UFortVariantPicker;

UCLASS(Abstract, meta=(DisableNativeTick))
class UFortVariantListPreviewWidget : public UCommonActivatableWidget
{
	GENERATED_BODY()

private:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortVariantPicker> Picker_VariantSelector;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonBorder> Container_StyleDisclaimer;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_StyleDisclaimer;

};

