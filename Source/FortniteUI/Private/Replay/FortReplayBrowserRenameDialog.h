// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "Types/SlateEnums.h"
#include "FortReplayBrowserRenameDialog.generated.h"

class UCommonButtonLegacy;
class UEditableText;

UCLASS(Abstract, meta=(DisableNativeTick))
class UFortReplayBrowserRenameDialog : public UCommonActivatableWidget
{
	GENERATED_BODY()

private:
	UFUNCTION()
	void HandleTextChanged(const FText& Text);

	UFUNCTION()
	void HandleTextCommitted(const FText& Text, ETextCommit::Type CommitMethod);

	UPROPERTY(EditDefaultsOnly, Category="FortReplayBrowserRenameDialog")
	int32 MaxReplayNameLength;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UEditableText> TextBox_Name;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_Confirm;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_Decline;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_TapToClose;

};

