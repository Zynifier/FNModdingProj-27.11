// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/Color.h"
#include "Types/SlateEnums.h"
#include "CommonButtonLegacy.h"
#include "SocialInteractionMenu.h"
#include "FortSocialInteractionMenu.generated.h"

class UCommonButtonLegacy;
class UCommonRichTextBlock;
class UCommonTextBlock;
class UEditableText;
class UFortEditNicknameButton;
class UFortSocialNameTextBlock;

UCLASS(Abstract, meta=(DisableNativeTick))
class UFortEditNicknameButton : public UCommonButtonLegacy
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintCallable)
	void SetKeyboardFocusOnEditableText();

	UPROPERTY(EditAnywhere, Category="FortEditNicknameButton")
	FColor CharacterLimitWarningColor;

private:
	UFUNCTION()
	void HandleNicknameTextChanged(const FText& Text);

	UFUNCTION()
	void HandleNicknameTextCommited(const FText& Text, ETextCommit::Type CommitMethod);

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UEditableText> EditableText_EditNickname;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonRichTextBlock> RichText_CharacterCounter;

};

UCLASS(Abstract)
class UFortSocialInteractionMenu : public USocialInteractionMenu
{
	GENERATED_BODY()

private:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortSocialNameTextBlock> Text_SocialName;

	UPROPERTY(Export, meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UCommonRichTextBlock> RichText_PlatformNames;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonRichTextBlock> Text_Presence;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortEditNicknameButton> Button_EditNickname;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_ErrorMessage;

	UPROPERTY(Export, meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_CancelEdit;

	UPROPERTY(Export, meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_DoneEdit;

};

