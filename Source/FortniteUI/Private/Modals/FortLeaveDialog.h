// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UIManager/FortActivatablePanel.h"
#include "FortLeaveDialog.generated.h"

class UCommonButtonGroupLegacy;
class UCommonButtonLegacy;
class UCommonTextBlock;
class UVerticalBox;

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortLeaveDialog : public UFortActivatablePanel
{
	GENERATED_BODY()

public:
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnDialogResponse);

public:
	UFUNCTION(BlueprintCallable)
	void SetupLeaveDialog(const FText& InTitle, const FText& InDescription, bool bInShowPartyOptions);

	UPROPERTY(BlueprintAssignable)
	FOnDialogResponse OnLeft;

	UPROPERTY(BlueprintAssignable)
	FOnDialogResponse OnCanceled;

protected:
	UFUNCTION(BlueprintCallable)
	void CloseDialog();

private:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UVerticalBox> VBox_PartyOptions;

	UPROPERTY(Transient)
	TObjectPtr<UCommonButtonGroupLegacy> PartyRadioButtonGroup;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_Title;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_Description;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_LeavePartyRadio;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_StayWithPartyRadio;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_Leave;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_Cancel;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_CloseTouch;

};

