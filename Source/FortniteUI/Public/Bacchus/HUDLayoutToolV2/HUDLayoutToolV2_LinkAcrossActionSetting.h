// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "Math/Color.h"
#include "HUDLayoutToolV2_LinkAcrossActionSetting.generated.h"

class UCommonTextBlock;
class UHUDLayoutToolV2_Button;
class UHUDLayoutToolV2_LinkAcrossNumericalIndicator;
class UHUDLayoutToolV2_LinkAcrossWarningIndicator;
class UImage;
class UPaperSprite;

UCLASS(meta=(DisableNativeTick))
class UHUDLayoutToolV2_LinkAcrossActionSetting : public UCommonUserWidget
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="Check Box")
	FLinearColor EnabledCheckBoxBorderColor;

	UPROPERTY(EditAnywhere, Category="Check Box")
	FLinearColor DisabledCheckBoxBorderColor;

	UPROPERTY(EditAnywhere, Category="Check Box")
	TObjectPtr<UPaperSprite> CheckMarkSprite;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UImage> Image_ActionIcon;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_ActionName;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UHUDLayoutToolV2_LinkAcrossWarningIndicator> LinkAcrossWarningIndicator_Warning;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UHUDLayoutToolV2_LinkAcrossNumericalIndicator> NumericalIndicator_ActionImpact;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UImage> Image_CheckboxBorder;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UHUDLayoutToolV2_Button> Button_SelectAction;

};

