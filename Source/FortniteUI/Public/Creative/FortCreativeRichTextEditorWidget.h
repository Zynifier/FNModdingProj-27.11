// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "FortCreativeRichTextEditorWidget.generated.h"

class UCommonButtonBase;
class UCommonButtonGroupBase;
class UCommonTextBlock;
class UDataTable;
class UDynamicEntryBox;
class UFortConfirmationWindow;
class UFortCreativeRichTextWordButton;
class UMultiLineEditableText;
class UWidget;
class UWidgetSwitcher;
class UWrapBox;
enum class EButtonContext : uint8;
enum class EConfirmDialogType : uint8;

UENUM(BlueprintType)
enum class EButtonContext : uint8
{
	NoButtonSelected = 0,
	ButtonSelected = 1,
	StylingButtons = 2,
};

UENUM(BlueprintType)
enum class EConfirmDialogType : uint8
{
	CancelChanges = 0,
	CharLimitExceeded = 1,
	MarkupWarning = 2,
};

USTRUCT()
struct FStyleButtonReference
{
	GENERATED_BODY()

public:
	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button;

};

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortCreativeRichTextEditorWidget : public UCommonActivatableWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	bool CanShowStyleEditor() const;

	UFUNCTION(BlueprintPure)
	static bool IsStyleEditorEnabled();

	UFUNCTION(BlueprintCallable)
	void SetAllowLineBreaks(bool InAllowLineBreaks);

	UFUNCTION(BlueprintCallable)
	void SetAllowStyleEditing(bool InAllowStyleEditing);

	UFUNCTION(BlueprintCallable)
	void SetEntryCharLimit(int32 InCharLimit);

	UFUNCTION(BlueprintCallable)
	void SetRichStyleSetOverride(UDataTable* RichStyleSetOverride);

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void BP_DialogConfirmed(EConfirmDialogType DialogType);

	UFUNCTION(BlueprintImplementableEvent)
	void BP_WordButtonHovered(UFortCreativeRichTextWordButton* Button);

	UFUNCTION(BlueprintCallable, meta=(BlueprintProtected="true"))
	void ClearSelectedWordButtons();

	UFUNCTION(BlueprintCallable, meta=(BlueprintProtected="true"))
	EButtonContext GetButtonContext();

	UFUNCTION(BlueprintCallable, meta=(BlueprintProtected="true"))
	FString GetTextInRange();

	UFUNCTION(BlueprintImplementableEvent, meta=(BlueprintProtected="true"))
	void OnCharLimitReached(const bool bIsReached);

	UFUNCTION(BlueprintImplementableEvent, meta=(BlueprintProtected="true"))
	void OnFormatError(const FText& Description);

	UFUNCTION(BlueprintImplementableEvent, meta=(BlueprintProtected="true"))
	void OnInitializedFinished();

	UFUNCTION(BlueprintImplementableEvent, meta=(BlueprintProtected="true"))
	void OnStyleButtonCreated(UCommonButtonBase* Button, const FString& Label, const FString& FormattedText, UDataTable* TextStyleSet, bool bIsDefaultButton);

	UFUNCTION(BlueprintImplementableEvent, meta=(BlueprintProtected="true"))
	void OnStyleButtonSelectedChanged(UCommonButtonBase* Button, bool Selected);

	UFUNCTION(BlueprintImplementableEvent, meta=(BlueprintProtected="true"))
	void OnUpdateButtonsVisibility();

	UFUNCTION(BlueprintImplementableEvent, meta=(BlueprintProtected="true"))
	void OnUpdateCommitCancelState(const bool Enabled);

	UFUNCTION(BlueprintImplementableEvent)
	void OnUpdateWordButtonLabel(const FText& ButtonText);

	UFUNCTION(BlueprintImplementableEvent, meta=(BlueprintProtected="true"))
	void OnWordButtonCreated(UFortCreativeRichTextWordButton* WordButton);

	UFUNCTION(BlueprintCallable, meta=(BlueprintProtected="true"))
	void ShowConfirmationDialog(EConfirmDialogType DialogType);

	UPROPERTY(BlueprintReadOnly, Export, Category="FortCreativeRichTextEditorWidget", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UMultiLineEditableText> EditableText;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortCreativeRichTextEditorWidget", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UWrapBox> WordButtons_WBox;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortCreativeRichTextEditorWidget", meta=(BindWidget, EditInline="true", EntryClass="CommonButtonBase"))
	TObjectPtr<UDynamicEntryBox> EntryBox_StyleButtons;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortCreativeRichTextEditorWidget", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Style_Tab_Button;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortCreativeRichTextEditorWidget", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Text_Tab_Button;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortCreativeRichTextEditorWidget", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UWidgetSwitcher> PanelSwitcher;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortCreativeRichTextEditorWidget", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UWidget> Text_Overlay;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortCreativeRichTextEditorWidget", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UWidget> Style_Overlay;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortCreativeRichTextEditorWidget", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> RemoveStyles_Button;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_CharCount;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortCreativeRichTextEditorWidget", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortConfirmationWindow> ConfirmationWindow;

	UPROPERTY(BlueprintReadOnly, Category="FortCreativeRichTextEditorWidget")
	TObjectPtr<UCommonButtonGroupBase> TabsButtonGroup;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Style")
	bool bIsLineBreakAllowed;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Input")
	int32 EntryCharLimit;

	UPROPERTY(BlueprintReadWrite, Category="FortCreativeRichTextEditorWidget")
	bool bStylingInProgress;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortCreativeRichTextEditorWidget", meta=(EditInline="true"))
	TObjectPtr<UFortCreativeRichTextWordButton> LastSelectedWordButton;

private:
	UFUNCTION()
	void HandleStyleButtonClicked(UCommonButtonBase* Button, int32 Index);

	UFUNCTION()
	void HandleTabButtonSelected(UCommonButtonBase* AssociatedButton, const int32 ButtonIndex);

	UFUNCTION()
	void HandleTextChanged(const FText& Text);

	UFUNCTION()
	void HandleWordButtonClicked(UFortCreativeRichTextWordButton* Button);

	UFUNCTION()
	void HandleWordButtonHovered(UFortCreativeRichTextWordButton* Button);

	UPROPERTY()
	TArray<FStyleButtonReference> StyleButtonReferences;

	UPROPERTY(Export, meta=(EditInline="true"))
	TSet<TObjectPtr<UFortCreativeRichTextWordButton>> Set_SelectedWordButtons;

	UPROPERTY(EditDefaultsOnly, Category="Dynamically Created Object Classes")
	TSubclassOf<UFortCreativeRichTextWordButton> WordButtonClass;

	UPROPERTY(EditDefaultsOnly, Category="Dynamically Created Object Classes")
	TSubclassOf<UCommonButtonBase> StyleButtonClass;

	UPROPERTY(EditDefaultsOnly, Category="Input")
	TObjectPtr<UDataTable> RichTextStylesTable;

	UPROPERTY(EditDefaultsOnly, Category="Input")
	FText SampleText;

};

