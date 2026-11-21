// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Fonts/SlateFontInfo.h"
#include "Styling/SlateColor.h"
#include "CommonButtonLegacy.h"
#include "FortTextButton.generated.h"

class UCommonTextBlock;

UCLASS(Abstract, MinimalAPI, meta=(DisableNativeTick))
class UFortTextButton : public UCommonButtonLegacy
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="Button Options", meta=(DisplayName="Button Text"))
	FText DefaultText;

	UPROPERTY(EditAnywhere, Category="Button Options")
	bool bUseAllCaps;

	UPROPERTY(EditAnywhere, Category="Button Options", meta=(InlineEditConditionToggle="OverrideFont"))
	bool bOverrideFont;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Button Options", meta=(AllowPrivateAccess, EditCondition="bOverrideFont"))
	FSlateFontInfo Font;

	UPROPERTY(EditAnywhere, Category="Button Options", meta=(EditCondition="bOverrideFont"))
	FSlateColor FontColor;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortTextButton", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_Content;

};

