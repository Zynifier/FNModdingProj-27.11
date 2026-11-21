// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Layout/Margin.h"
#include "Styling/SlateBrush.h"
#include "CommonButtonLegacy.h"
#include "FortMainMenuButton.generated.h"

class UBorder;
class UCommonButtonStyle;
class UCommonTextBlock;
class UImage;

UCLASS(Abstract, MinimalAPI, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortMainMenuButton : public UCommonButtonLegacy
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	FORTNITEUI_API void SetText(const FText& InText);

protected:
	UPROPERTY(EditAnywhere, Category="FortMainMenuButton")
	FText DefaultText;

	UPROPERTY(EditAnywhere, Category="FortMainMenuButton")
	FSlateBrush DefaultBrush;

	UPROPERTY(EditAnywhere, Category="FortMainMenuButton")
	int32 NormalButtonHeight;

	UPROPERTY(EditAnywhere, Category="FortMainMenuButton")
	int32 MobileButtonHeight;

	UPROPERTY(EditAnywhere, Category="FortMainMenuButton")
	FMargin TextPadding;

	UPROPERTY(EditAnywhere, Category="FortMainMenuButton")
	FMargin ContentPadding;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Style", meta=(ExposeOnSpawn="TRUE"))
	TSubclassOf<UCommonButtonStyle> MobileStyle;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_Content;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UImage> Image_Icon;

	UPROPERTY(Export, meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UBorder> ContentBorder;

};

