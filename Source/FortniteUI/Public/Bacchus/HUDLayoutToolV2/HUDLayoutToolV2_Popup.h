// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "HUDLayoutToolV2_Popup.generated.h"

class UBacchusCloseButton;
class UCommonActivatableWidgetSwitcher;
class UCommonTextBlock;
class UHUDLayoutToolV2_Button;
class URichTextBlock;
class UWidgetAnimation;

UENUM()
enum class EHUDLayoutToolPopupType : uint8
{
	Warning = 0,
	Generic = 1,
};

USTRUCT(BlueprintType)
struct FHUDLayoutToolV2_PopupContent
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="HUDLayoutToolV2_PopupContent")
	EHUDLayoutToolPopupType PopupType;

	UPROPERTY(EditAnywhere, Category="HUDLayoutToolV2_PopupContent")
	FText TitleText;

	UPROPERTY(EditAnywhere, Category="HUDLayoutToolV2_PopupContent", meta=(MultiLine="TRUE"))
	FText DescriptionText;

	UPROPERTY(EditAnywhere, Category="HUDLayoutToolV2_PopupContent")
	FText ButtonConfirmText;

	UPROPERTY(EditAnywhere, Category="HUDLayoutToolV2_PopupContent")
	FText ButtonCancelText;

};

UCLASS(Abstract, meta=(DisableNativeTick))
class UHUDLayoutToolV2_Popup : public UCommonActivatableWidget
{
	GENERATED_BODY()

protected:
	UPROPERTY(Export, meta=(Bindwidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> CommonText_Title;

	UPROPERTY(Export, meta=(Bindwidget, EditInline="true"))
	TObjectPtr<URichTextBlock> RichText_Description;

	UPROPERTY(Export, meta=(Bindwidget, EditInline="true"))
	TObjectPtr<UHUDLayoutToolV2_Button> Button_Confirm;

	UPROPERTY(Export, meta=(Bindwidget, EditInline="true"))
	TObjectPtr<UHUDLayoutToolV2_Button> Button_Cancel;

	UPROPERTY(Export, meta=(Bindwidget, EditInline="true"))
	TObjectPtr<UBacchusCloseButton> Button_Close;

	UPROPERTY(Transient, meta=(BindWidgetAnim))
	TObjectPtr<UWidgetAnimation> Anim_In;

	UPROPERTY(Transient, meta=(BindWidgetAnim))
	TObjectPtr<UWidgetAnimation> Anim_Out;

private:
	UPROPERTY(Export, meta=(BindwidgetOptional, EditInline="true"))
	TObjectPtr<UCommonActivatableWidgetSwitcher> Switcher_CornerIcon;

};

