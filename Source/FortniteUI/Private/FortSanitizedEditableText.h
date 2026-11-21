// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Framework/Text/CharRangeList.h"
#include "Types/SlateEnums.h"
#include "Widgets/Text/ISlateEditableTextWidget.h"
#include "FortSanitizedEditableText.generated.h"

class UCommonTextBlock;
class UEditableTextBox;

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortEditableFilteredCountedTextBox : public UUserWidget
{
	GENERATED_BODY()

public:
	UFortEditableFilteredCountedTextBox(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

public:
	UFUNCTION(BlueprintCallable)
	void ForceSetText(const FText& Text);

	UFUNCTION(BlueprintPure)
	FString GetAllowedCharactersAsString() const;

	UFUNCTION(BlueprintPure)
	bool GetAllowLineBreaks() const;

	UFUNCTION(BlueprintPure)
	bool GetAllowStyleEditing() const;

	UFUNCTION(BlueprintPure)
	int32 GetEntryCharLimit() const;

	UFUNCTION(BlueprintPure)
	bool GetIgnoreCharLimitValidation() const;

	UFUNCTION(BlueprintImplementableEvent)
	void OnDirtyTextAttempted(bool bIsBadText, bool bAdditionalValidationFailed);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void SetEntryCharLimit(int32 InCharLimit);

	UFUNCTION(BlueprintCallable)
	void SetTextWithForcedSanitization(const FText& Text);

	UFUNCTION(BlueprintCallable)
	void UpdateCharacterCount();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void ValidatePersistentID(const FText& Text);

protected:
	UPROPERTY(EditAnywhere, Category="FortEditableFilteredCountedTextBox")
	int32 EntryCharLimit;

	UPROPERTY(EditAnywhere, Category="FortEditableFilteredCountedTextBox")
	EVirtualKeyboardTrigger VirtualKeyboardTrigger;

	UPROPERTY(Transient)
	int32 EnforcedEntryCharLimit;

	UPROPERTY(EditAnywhere, Category="FortEditableFilteredCountedTextBox")
	FText SuggestionText;

	UPROPERTY(EditAnywhere, Category="FortEditableFilteredCountedTextBox")
	bool bUseChatSanitizer;

	UPROPERTY(BlueprintReadOnly, Category="FortEditableFilteredCountedTextBox")
	bool bShouldValidatePersistentID;

	UPROPERTY(BlueprintReadOnly, Category="FortEditableFilteredCountedTextBox")
	bool bAllowLineBreaks;

	UPROPERTY(BlueprintReadOnly, Category="FortEditableFilteredCountedTextBox")
	bool bAllowStyleEditing;

	UPROPERTY(BlueprintReadOnly, Category="FortEditableFilteredCountedTextBox")
	bool bIgnoreCharLimitValidation;

	UPROPERTY(EditAnywhere, Category="FortEditableFilteredCountedTextBox")
	FCharRangeList AllowedCharacters;

	UPROPERTY(EditAnywhere, Category="FortEditableFilteredCountedTextBox")
	bool bReplaceUserTextWithSanitizedString;

	UPROPERTY(EditAnywhere, Category="FortEditableFilteredCountedTextBox")
	bool bAllowSanitizedStrings;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortEditableFilteredCountedTextBox")
	FText DefaultSanitizationErrorText;

	UPROPERTY(BlueprintReadOnly, Category="FortEditableFilteredCountedTextBox")
	FText AdditionalValidationErrorText;

	UPROPERTY(BlueprintReadOnly, Category="FortEditableFilteredCountedTextBox")
	bool bCurrentlyValid;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortEditableFilteredCountedTextBox", meta=(BindWidget, BlueprintProtected, EditInline="true"))
	TObjectPtr<UEditableTextBox> EditText;

private:
	UFUNCTION()
	void HandleTextChanged(const FText& Text);

	UFUNCTION()
	void HandleTextCommitted(const FText& Text, ETextCommit::Type CommitMethod);

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_CharCount;

};

