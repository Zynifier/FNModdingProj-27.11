// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "FortPinGrantCodeInfoWidget.generated.h"

class UCircularThrobber;
class UCommonButtonBase;
class UCommonTextBlock;
class UVerticalBox;

UENUM(BlueprintType)
enum class EPinGrantState : uint8
{
	Initial = 0,
	Error = 1,
	Downloading = 2,
	Granted = 3,
};

UCLASS()
class UFortPinGrantCodeInfoWidget : public UCommonUserWidget
{
	GENERATED_BODY()

private:
	UPROPERTY(BlueprintReadOnly, Export, Category="FortPinGrantCodeInfoWidget", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_GenerateCode;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_PinCode;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_ErrorMsg;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_ActivationURL;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_CodeExpiringTime;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_Info;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_PinPromptTypeTitle;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UVerticalBox> Container_ActivationURL;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCircularThrobber> Throbber_GettingPinCode;

};

