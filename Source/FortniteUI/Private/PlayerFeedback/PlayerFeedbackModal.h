// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CheckDismissableActivatableWidget.h"
#include "PlayerFeedback/PlayerFeedbackTypes.h"
#include "UIManager/FortActivatablePanel.h"
#include "PlayerFeedbackModal.generated.h"

class UCommonButtonBase;
class UCommonButtonGroupBase;
class UCommonTextBlock;
class UDynamicEntryBox;
class UFortPlayerFeedbackModalSubscreenBase;
class UFortPlayerFeedbackModalSubscreen_CategoryDisplay;
class UFortPlayerFeedbackModalSubscreen_EpicQA;
class UFortPlayerFeedbackModalSubscreen_FreeText;
class UFortPlayerFeedbackModalSubscreen_PlayerSelect;
class UFortPlayerFeedbackModalSubscreen_Screenshot;
class UFortPlayerFeedbackModalSubscreen_SubmitScreen;
class UFortPlayerFeedbackModalSubscreen_SubmitVoiceScreen;
class UScrollBox;

UCLASS(Abstract, Config=Game, meta=(DisableNativeTick))
class UFortPlayerFeedbackModal : public UFortActivatablePanel, public ICheckDismissableActivatableWidget
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Category="FortPlayerFeedbackModal")
	TSubclassOf<UFortPlayerFeedbackModalSubscreen_CategoryDisplay> Subscreen_CategoryDisplay;

	UPROPERTY(EditDefaultsOnly, Category="FortPlayerFeedbackModal")
	TSubclassOf<UFortPlayerFeedbackModalSubscreen_PlayerSelect> Subscreen_PlayerSelect;

	UPROPERTY(EditDefaultsOnly, Category="FortPlayerFeedbackModal")
	TSubclassOf<UFortPlayerFeedbackModalSubscreen_SubmitScreen> Subscreen_SubmitDisplay;

	UPROPERTY(EditDefaultsOnly, Category="FortPlayerFeedbackModal")
	TSubclassOf<UFortPlayerFeedbackModalSubscreen_SubmitVoiceScreen> Subscreen_SubmitVoice;

	UPROPERTY(EditDefaultsOnly, Category="FortPlayerFeedbackModal")
	TSubclassOf<UFortPlayerFeedbackModalSubscreen_FreeText> Subscreen_FreeText;

	UPROPERTY(EditDefaultsOnly, Category="FortPlayerFeedbackModal")
	TSubclassOf<UFortPlayerFeedbackModalSubscreen_EpicQA> Subscreen_EpicQA;

	UPROPERTY(EditDefaultsOnly, Category="FortPlayerFeedbackModal")
	TSubclassOf<UFortPlayerFeedbackModalSubscreen_Screenshot> Subscreen_Screenshot;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortPlayerFeedbackModal", meta=(BindWidget, EditInline="true", EntryClass="FortPlayerFeedbackModalTab"))
	TObjectPtr<UDynamicEntryBox> SubscreenTabs;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortPlayerFeedbackModal", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UScrollBox> SubscreenContainer;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortPlayerFeedbackModal", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_ModalTitle;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortPlayerFeedbackModal", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_Close;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortPlayerFeedbackModal", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_BackTouch;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortPlayerFeedbackModal", meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UCommonButtonBase> CloseButton;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortPlayerFeedbackModal", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_NewFeedbackReport;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortPlayerFeedbackModal", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_Back;

private:
	UPROPERTY(Transient)
	TObjectPtr<UCommonButtonGroupBase> CategoryTabs;

	UPROPERTY(Transient, Export)
	TArray<TWeakObjectPtr<UFortPlayerFeedbackModalSubscreenBase>> DisplayedSubScreenStack;

	UPROPERTY(Transient, Export)
	TArray<TWeakObjectPtr<UFortPlayerFeedbackModalSubscreenBase>> SubScreenToDisplayQueue;

	UPROPERTY(Config)
	TArray<FFortFeedbackDropdownCategoryHotfix_Add> PlayerFeedbackCategoriesToAdd;

	UPROPERTY(Config)
	TArray<FFortFeedbackDropdownCategoryHotfix_Modify> PlayerFeedbackCategoriesToModify;

};

