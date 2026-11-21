// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortDialogTypes.h"
#include "UIManager/FortActivatablePanel.h"
#include "FortConfirmationWindow.generated.h"

class UCommonButtonBase;
class UCommonLoadGuard;
class UCommonTextBlock;
class UDynamicEntryBox;
class UImage;
class UPanelWidget;
class UScrollBox;
class UWidget;

USTRUCT()
struct FFortConfirmationButtonInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button;

};

UCLASS(meta=(DisableNativeTick))
class UFortConfirmationWindow : public UFortActivatablePanel
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintCallable, meta=(BlueprintProtected="TRUE"))
	void BotClickButton();

	UFUNCTION(BlueprintImplementableEvent)
	void ConfigureConfirmationButton(UCommonButtonBase* Button, const FConfirmationDialogAction& Action, bool bSimpleConfirm);

	UFUNCTION(BlueprintImplementableEvent)
	void ConfigureDeclineButton(UCommonButtonBase* Button);

	UFUNCTION(BlueprintPure, meta=(BlueprintProtected="TRUE"))
	const FFortDialogDescription_NUI& GetConfirmationDescription() const;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortConfirmationWindow", meta=(BindWidget, EditInline="true", EntryClass="CommonButton"))
	TObjectPtr<UDynamicEntryBox> EntryBox_SimpleButtons;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortConfirmationWindow", meta=(BindWidget, EditInline="true", EntryClass="CommonButton"))
	TObjectPtr<UDynamicEntryBox> EntryBox_ComplexChoiceButtons;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UPanelWidget> Panel_LeftOptionalWidget;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UPanelWidget> Panel_OptionalWidget;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UScrollBox> ScrollBox_Description;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> CommonTextBlock_Title;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> CommonTextBlock_Description;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UImage> Image_MainIcon;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonLoadGuard> CommonLoadGuard_LatentSpinner;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UWidget> Button_CloseTouch;

private:
	UFUNCTION(BlueprintCallable, Category="Event Responses", meta=(BlueprintProtected="TRUE"))
	void HandleCancelButtonClicked(UCommonButtonBase* Buttton);

	UFUNCTION(BlueprintCallable, Category="Event Responses", meta=(BlueprintProtected="TRUE"))
	void HandleDeclineActionClicked(UCommonButtonBase* ButtonClicked);

	UFUNCTION()
	void HandleInputSuspensionChanged(bool bIsInputSuspended);

	UPROPERTY(Transient)
	TArray<FFortConfirmationButtonInfo> ConfirmationButtons;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UCommonButtonBase> DeclineButton;

	UPROPERTY()
	FFortDialogDescription_NUI ConfirmationDescription;

};

