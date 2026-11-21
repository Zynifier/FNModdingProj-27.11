// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "LockerConfirmationModal.generated.h"

class UCommonButtonBase;
class UCommonTextBlock;

UCLASS(Abstract, meta=(DisableNativeTick))
class ULockerConfirmationModal : public UCommonActivatableWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void BP_Init(const FText& Title, const FText& Description, const FText& ConfirmButtonText, const FText& CancelButtonText, const bool bShowMTXWallet = false);

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnSetButtonTexts(const FText& ConfirmText, const FText& CancelText);

	UFUNCTION(BlueprintImplementableEvent)
	void OnShowMTXWallet(const bool bShow);

private:
	UPROPERTY(BlueprintReadOnly, Export, Category="LockerConfirmationModal", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_Cancel;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_CloseTouch;

	UPROPERTY(BlueprintReadOnly, Export, Category="LockerConfirmationModal", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_Confirm;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_Title;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_Description;

};

