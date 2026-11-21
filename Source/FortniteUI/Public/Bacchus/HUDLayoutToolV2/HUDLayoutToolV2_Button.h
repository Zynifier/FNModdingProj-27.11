// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "Layout/Margin.h"
#include "Math/Color.h"
#include "Styling/SlateBrush.h"
#include "Styling/SlateColor.h"
#include "HUDLayoutToolV2_Button.generated.h"

class UBorder;
class UCommonTextBlock;
class UImage;
class USizeBox;

USTRUCT()
struct FHUDLayoutToolV2_ButtonStateColor
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="HUDLayoutToolV2_ButtonStateColor")
	FSlateColor TextColor;

	UPROPERTY(EditAnywhere, Category="HUDLayoutToolV2_ButtonStateColor")
	FLinearColor IconColor;

	UPROPERTY(EditAnywhere, Category="HUDLayoutToolV2_ButtonStateColor")
	FLinearColor BackgroundColor;

	UPROPERTY(EditAnywhere, Category="HUDLayoutToolV2_ButtonStateColor")
	float IconAngle;

};

UCLASS(Abstract, meta=(DisableNativeTick))
class UHUDLayoutToolV2_Button : public UCommonUserWidget
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="HUDLayoutToolV2_Button")
	bool bIsToggleable;

	UPROPERTY(EditAnywhere, Category="HUDLayoutToolV2_Button", meta=(editcondition="bOverride_WidthOverride"))
	float ButtonWidthOverride;

	UPROPERTY(EditAnywhere, Category="HUDLayoutToolV2_Button", meta=(editcondition="bOverride_HeightOverride"))
	float ButtonHeightOverride;

	UPROPERTY(EditAnywhere, Category="HUDLayoutToolV2_Button")
	FText Text;

	UPROPERTY(EditAnywhere, Category="HUDLayoutToolV2_Button")
	FMargin TextPadding;

	UPROPERTY(EditAnywhere, Category="HUDLayoutToolV2_Button")
	int32 TextFontSize;

	UPROPERTY(EditAnywhere, Category="HUDLayoutToolV2_Button")
	FSlateBrush IconBrush;

	UPROPERTY(EditAnywhere, Category="HUDLayoutToolV2_Button")
	FMargin IconPadding;

	UPROPERTY(EditAnywhere, Category="HUDLayoutToolV2_Button")
	bool bMatchIconSize;

	UPROPERTY(EditAnywhere, Category="HUDLayoutToolV2_Button")
	FSlateBrush BackgroundBrush;

	UPROPERTY(EditAnywhere, Category="HUDLayoutToolV2_Button")
	FMargin InternalPadding;

	UPROPERTY(EditAnywhere, Category="HUDLayoutToolV2_Button", meta=(InlineEditConditionToggle))
	uint8 bOverride_WidthOverride : 1;

	UPROPERTY(EditAnywhere, Category="HUDLayoutToolV2_Button", meta=(InlineEditConditionToggle))
	uint8 bOverride_HeightOverride : 1;

	UPROPERTY(EditAnywhere, Category="HUDLayoutToolV2_Button", meta=(InlineEditConditionToggle))
	bool bExternallyControlledStates;

	UPROPERTY(EditAnywhere, Category="HUDLayoutToolV2_Button", meta=(editcondition="!bExternallyControlledStates"))
	FHUDLayoutToolV2_ButtonStateColor NormalButtonStyle;

	UPROPERTY(EditAnywhere, Category="HUDLayoutToolV2_Button", meta=(editcondition="!bExternallyControlledStates"))
	FHUDLayoutToolV2_ButtonStateColor PressedButtonStyle;

	UPROPERTY(EditAnywhere, Category="HUDLayoutToolV2_Button", meta=(editcondition="!bExternallyControlledStates"))
	FHUDLayoutToolV2_ButtonStateColor SelectedButtonStyle;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<USizeBox> SizeBox_Control;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UBorder> Border_Container;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_ButtonAction;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UImage> Image_Icon;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UImage> Image_Background;

};

