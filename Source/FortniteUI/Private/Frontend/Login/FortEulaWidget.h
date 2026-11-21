// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatablePanelLegacy.h"
#include "FortEulaWidget.generated.h"

class UCommonButtonLegacy;
class UCommonButtonStyle;
class UCommonTextBlock;
class UFortRichTextBlockLegacy;
class UScrollBox;

UCLASS(Abstract, meta=(DisableNativeTick))
class UFortEulaWidget : public UCommonActivatablePanelLegacy
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Category="FortEulaWidget")
	TSubclassOf<UCommonButtonStyle> ConfirmButtonControllerStyle;

	UPROPERTY(EditDefaultsOnly, Category="FortEulaWidget")
	TSubclassOf<UCommonButtonStyle> ConfirmButtonMouseStyle;

	UPROPERTY(EditDefaultsOnly, Category="FortEulaWidget")
	TSubclassOf<UCommonButtonStyle> DeclineButtonControllerStyle;

	UPROPERTY(EditDefaultsOnly, Category="FortEulaWidget")
	TSubclassOf<UCommonButtonStyle> DeclineButtonMouseStyle;

private:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_Title;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortRichTextBlockLegacy> Text_Description;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UScrollBox> ScrollBox_License;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_Confirm;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_Decline;

};

