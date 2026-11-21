// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "FortActivityBrowserAttributionsModal.generated.h"

class UCommonButtonBase;
class UCommonRichTextBlock;
class UCommonTextBlock;
class UScrollBox;

UCLASS(Abstract, Config=Game, MinimalAPI, meta=(DisableNativeTick))
class UFortActivityBrowserAttributionsModal : public UCommonActivatableWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintNativeEvent)
	FText GetAttributionsTextFormat(const FText& Title, const FText& Author, const FText& License);

	UFUNCTION(BlueprintNativeEvent)
	FText GetCreatorTextFormat(const FText& CreatorName);

	UFUNCTION(BlueprintNativeEvent)
	FText GetLinkCodeTextFormat(const FText& LinkCode);

	UFUNCTION(BlueprintImplementableEvent)
	void OnAttributionsModalInitialized();

	UFUNCTION(BlueprintImplementableEvent)
	void OnCreditsModalInitialized();

private:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_Back;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_CloseTouch;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_OpenLink;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonRichTextBlock> RichText_Description;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UScrollBox> ScrollBox_Details;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_ActivityName;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonRichTextBlock> Text_ActivityOrigin;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonRichTextBlock> Text_LinkCode;

	UPROPERTY(EditDefaultsOnly, Category="FortActivityBrowserAttributionsModal")
	float ScrollAmount;

};

