// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatablePanelLegacy.h"
#include "FortDisplayNameWidget.generated.h"

class UCommonButtonLegacy;
class UCommonTextBlock;
class UEditableText;

UCLASS(Abstract, meta=(DisableNativeTick))
class UFortDisplayNameWidget : public UCommonActivatablePanelLegacy
{
	GENERATED_BODY()

protected:
	UFUNCTION()
	void HandleTextChanged(const FText& Text);

	UPROPERTY(EditAnywhere, Category="FortDisplayNameWidget")
	FText ButtonDisableReason;

	UPROPERTY(EditAnywhere, Category="FortDisplayNameWidget")
	FText NameTakenText;

	UPROPERTY(EditAnywhere, Category="FortDisplayNameWidget")
	FText NameInvalidFormatText;

	UPROPERTY(EditAnywhere, Category="FortDisplayNameWidget")
	FText NameTooShortText;

private:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_Enter;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_Error;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UEditableText> EditText_DisplayName;

};

