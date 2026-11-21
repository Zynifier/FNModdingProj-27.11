// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "Math/Color.h"
#include "HUDLayoutToolV2_LayoutButton.generated.h"

class UBorder;
class UHUDLayoutToolV2_Button;

UCLASS(Abstract, meta=(DisableNativeTick))
class UHUDLayoutToolV2_LayoutButton : public UCommonUserWidget
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="HUDLayoutToolV2_LayoutButton")
	FLinearColor InEditColor;

	UPROPERTY(EditAnywhere, Category="HUDLayoutToolV2_LayoutButton")
	FLinearColor SelectedColor;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UHUDLayoutToolV2_Button> Button_Internal;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UBorder> Border_ActiveIndicator;

};

