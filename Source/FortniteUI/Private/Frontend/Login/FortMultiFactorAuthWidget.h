// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Types/SlateEnums.h"
#include "CommonActivatablePanelLegacy.h"
#include "FortMultiFactorAuthWidget.generated.h"

class UCommonButtonLegacy;
class UCommonTextBlock;
class UEditableText;

UCLASS(Abstract, meta=(DisableNativeTick))
class UFortMultiFactorAuthWidget : public UCommonActivatablePanelLegacy
{
	GENERATED_BODY()

protected:
	UFUNCTION()
	void HandleTextCommitted(const FText& Text, ETextCommit::Type CommitMethod);

private:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_Continue;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_Cancel;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_Error;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UEditableText> EditText_MultiFactorCode;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_Prompt;

};

