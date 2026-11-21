// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Variants/FortVariantEditorWidgetBase.h"
#include "FortVariantNumericalPicker.generated.h"

class UCommonButtonLegacy;
class UCommonTextBlock;
class UFortCosmeticNumericalVariant;

UCLASS(meta=(Category="Fortnite UI"))
class UFortVariantNumericalPicker : public UFortVariantEditorWidgetBase
{
	GENERATED_BODY()

private:
	UPROPERTY()
	int32 MinNum;

	UPROPERTY()
	int32 MaxNum;

	UPROPERTY()
	int32 NumericDelta;

	UPROPERTY()
	int32 CurrentNumber;

	UPROPERTY()
	TObjectPtr<UFortCosmeticNumericalVariant> NumericalVariant;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_ZeroDigitUp;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_ZeroDigitDown;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_TenDigitUp;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_TenDigitDown;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_NumericalValue;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_VariantName;

};

