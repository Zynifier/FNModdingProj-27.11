// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "Math/Color.h"
#include "HUDLayoutToolV2_ContextButton.generated.h"

class UCommonTextBlock;
class UHUDLayoutToolV2_Button;
class UImage;
class UPaperSprite;

UCLASS(Abstract, meta=(DisableNativeTick))
class UHUDLayoutToolV2_ContextButton : public UCommonUserWidget
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="Button States")
	TObjectPtr<UPaperSprite> InEditIcon;

	UPROPERTY(EditAnywhere, Category="Button States")
	FLinearColor InEditIconColorAndOpacity;

	UPROPERTY(EditAnywhere, Category="Button States")
	FLinearColor InEditBackgroundColorAndOpacity;

	UPROPERTY(EditAnywhere, Category="Button States")
	TObjectPtr<UPaperSprite> VisibleIcon;

	UPROPERTY(EditAnywhere, Category="Button States")
	FLinearColor VisibleIconColorAndOpacity;

	UPROPERTY(EditAnywhere, Category="Button States")
	FLinearColor VisibleBackgroundColorAndOpacity;

	UPROPERTY(EditAnywhere, Category="Button States")
	TObjectPtr<UPaperSprite> HiddenIcon;

	UPROPERTY(EditAnywhere, Category="Button States")
	FLinearColor HiddenIconColorAndOpacity;

	UPROPERTY(EditAnywhere, Category="Button States")
	FLinearColor HiddenBackgroundColorAndOpacity;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_LayoutName;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UHUDLayoutToolV2_Button> Button_ContextVisibility;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UHUDLayoutToolV2_Button> Button_ToggleContextEditing;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UImage> Image_SelectionHighlight;

};

