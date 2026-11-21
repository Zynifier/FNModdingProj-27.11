// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "PlayerFeedbackSubscreens.generated.h"

class UComboBoxString;
class UCommonButtonBase;
class UCommonButtonGroupBase;
class UCommonRichTextBlock;
class UCommonTextBlock;
class UDynamicEntryBox;
class UEditableText;
class UImage;
class UMultiLineEditableTextBox;
class UWidget;
enum class EPlayerFeedbackSubmitState : uint8;
enum class EPlayerFeedback_EpicQAState : uint8;

UCLASS(Abstract, NotBlueprintable, meta=(DisableNativeTick))
class UFortPlayerFeedbackModalSubscreenBase : public UCommonActivatableWidget
{
	GENERATED_BODY()

};

UCLASS(Abstract, BlueprintType, Blueprintable)
class UFortPlayerFeedbackModalSubscreen_CategoryDisplay : public UFortPlayerFeedbackModalSubscreenBase
{
	GENERATED_BODY()

protected:
	UPROPERTY(BlueprintReadOnly, Export, Category="FortPlayerFeedbackModalSubscreen_CategoryDisplay", meta=(BindWidget, EditInline="true", EntryClass="FortPlayerFeedbackModalCategoryButton"))
	TObjectPtr<UDynamicEntryBox> Buttons_DropdownCategories;

private:
	UPROPERTY(Transient)
	TObjectPtr<UCommonButtonGroupBase> CategoryButtons;

};

UCLASS(Abstract, BlueprintType, Blueprintable)
class UFortPlayerFeedbackModalSubscreen_EpicQA : public UFortPlayerFeedbackModalSubscreenBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent)
	void OnStateUpdated(EPlayerFeedback_EpicQAState NewState);

protected:
	UPROPERTY(BlueprintReadOnly, Export, Category="FortPlayerFeedbackModalSubscreen_EpicQA", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UComboBoxString> ComboBoxString_BugComponents;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortPlayerFeedbackModalSubscreen_EpicQA", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UEditableText> EditableText_Username;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortPlayerFeedbackModalSubscreen_EpicQA", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UEditableText> EditableText_Password;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortPlayerFeedbackModalSubscreen_EpicQA", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_SignIn;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortPlayerFeedbackModalSubscreen_EpicQA", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_ConfirmComponent;

};

UCLASS(Abstract, BlueprintType, Blueprintable)
class UFortPlayerFeedbackModalSubscreen_FreeText : public UFortPlayerFeedbackModalSubscreenBase
{
	GENERATED_BODY()

protected:
	UPROPERTY(BlueprintReadOnly, Export, Category="FortPlayerFeedbackModalSubscreen_FreeText", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UWidget> TextContainer_CustomerSupport;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortPlayerFeedbackModalSubscreen_FreeText", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_CustomerSupport;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortPlayerFeedbackModalSubscreen_FreeText", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UMultiLineEditableTextBox> Text_Input;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortPlayerFeedbackModalSubscreen_FreeText", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_Next;

};

UCLASS(Abstract, BlueprintType, Blueprintable)
class UFortPlayerFeedbackModalSubscreen_PlayerSelect : public UFortPlayerFeedbackModalSubscreenBase
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnCreatedPlayerList(bool bHasPlayers);

	UPROPERTY(BlueprintReadOnly, Export, Category="FortPlayerFeedbackModalSubscreen_PlayerSelect", meta=(BindWidget, EditInline="true", EntryClass="FortPlayerFeedbackModalPlayerButton"))
	TObjectPtr<UDynamicEntryBox> Buttons_Players;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortPlayerFeedbackModalSubscreen_PlayerSelect", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_NoPlayers;

private:
	UPROPERTY(Transient)
	TObjectPtr<UCommonButtonGroupBase> PlayerButtons;

};

UCLASS(Abstract, BlueprintType, Blueprintable)
class UFortPlayerFeedbackModalSubscreen_Screenshot : public UFortPlayerFeedbackModalSubscreenBase
{
	GENERATED_BODY()

protected:
	UPROPERTY(BlueprintReadOnly, Export, Category="FortPlayerFeedbackModalSubscreen_Screenshot", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_TakeScreenshot;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortPlayerFeedbackModalSubscreen_Screenshot", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_Continue;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortPlayerFeedbackModalSubscreen_Screenshot", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UImage> Image_Preview;

};

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortPlayerFeedbackModalSubscreen_SubmitScreen : public UFortPlayerFeedbackModalSubscreenBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent)
	void OnUpdateSubmitState(EPlayerFeedbackSubmitState NewState);

protected:
	UPROPERTY(BlueprintReadOnly, Export, Category="FortPlayerFeedbackModalSubscreen_SubmitScreen", meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UWidget> Slot_CommunityRulesURL;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortPlayerFeedbackModalSubscreen_SubmitScreen", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonRichTextBlock> Text_Description;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortPlayerFeedbackModalSubscreen_SubmitScreen", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_Summary;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortPlayerFeedbackModalSubscreen_SubmitScreen", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_FailReason;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortPlayerFeedbackModalSubscreen_SubmitScreen", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_ReportNumber;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortPlayerFeedbackModalSubscreen_SubmitScreen", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_BlockUser;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortPlayerFeedbackModalSubscreen_SubmitScreen", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_CommunityRules;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortPlayerFeedbackModalSubscreen_SubmitScreen", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_Submit;

};

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortPlayerFeedbackModalSubscreen_SubmitVoiceScreen : public UFortPlayerFeedbackModalSubscreen_SubmitScreen
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void SetLoadingDisplay(bool bIsDisplayed);

};

