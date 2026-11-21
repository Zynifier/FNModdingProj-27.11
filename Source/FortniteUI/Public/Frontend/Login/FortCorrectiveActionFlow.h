// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "Types/SlateEnums.h"
#include "FortCorrectiveActionFlow.generated.h"

class UCommonActivatableWidgetSwitcher;
class UCommonButtonBase;
class UCommonTextBlock;
class UFortComboBox;
class UFortCorrectiveActionDateOfBirthScreen;
class UFortCorrectiveActionDisplayNameScreen;
class UFortCorrectiveActionGuardianEmailScreen;
class UFortCorrectiveActionUnsupportedActionScreen;
class UFortInputField;
class UFortPinGrantCodeInfoWidget;
class UFortRichTextBlockLegacy;

UCLASS()
class FORTNITEUI_API UFortCorrectiveActionScreen : public UCommonActivatableWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnShowCorrectiveActionProcessing(bool bShowProcessing);

	UFUNCTION(BlueprintImplementableEvent)
	void OnShowFailureReason(const FText& FailureReason);

private:
	UPROPERTY(Export, meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_Continue;

	UPROPERTY(Export, meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_PrivacyPolicy;

};

UCLASS()
class FORTNITEUI_API UFortCorrectiveActionDateOfBirthScreen : public UFortCorrectiveActionScreen
{
	GENERATED_BODY()

protected:
	UPROPERTY(BlueprintReadWrite, Export, Category="FortCorrectiveActionDateOfBirthScreen", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortInputField> InputField_Year;

private:
	UFUNCTION()
	void HandleMonthChanged(const FString& SelectedItem, ESelectInfo::Type SelectionType);

	UFUNCTION()
	void HandleYearChanged(const FText& Text, ETextCommit::Type CommitMethod);

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortComboBox> ComboBox_Month;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortComboBox> ComboBox_Day;

};

UCLASS()
class FORTNITEUI_API UFortCorrectiveActionDisplayNameScreen : public UFortCorrectiveActionScreen
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnShowDisplayNameDownloading(bool bShowDownloading);

private:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_DisplayName;

};

UCLASS()
class FORTNITEUI_API UFortCorrectiveActionFlow : public UCommonActivatableWidget
{
	GENERATED_BODY()

protected:
	UPROPERTY(BlueprintReadWrite, Export, Category="FortCorrectiveActionFlow", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortRichTextBlockLegacy> LinkText;

private:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonActivatableWidgetSwitcher> CorrectiveActionScreenSwitcher;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortCorrectiveActionGuardianEmailScreen> GuardianEmailScreen;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortCorrectiveActionDisplayNameScreen> DisplayNameScreen;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortCorrectiveActionDateOfBirthScreen> DateOfBirthScreen;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortCorrectiveActionUnsupportedActionScreen> UnsupportedActionScreen;

};

UCLASS()
class FORTNITEUI_API UFortCorrectiveActionGuardianEmailScreen : public UFortCorrectiveActionScreen
{
	GENERATED_BODY()

protected:
	UPROPERTY(BlueprintReadWrite, Export, Category="FortCorrectiveActionGuardianEmailScreen", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortInputField> InputField_GuardianEmailEntry;

};

UCLASS()
class FORTNITEUI_API UFortCorrectiveActionUnsupportedActionScreen : public UFortCorrectiveActionScreen
{
	GENERATED_BODY()

private:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortPinGrantCodeInfoWidget> PinGrantCodeInfoWidget;

};

