// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Types/SlateEnums.h"
#include "CommonActivatablePanelLegacy.h"
#include "FortSignInWidget.generated.h"

class UCommonBorder;
class UCommonBorderStyle;
class UCommonButtonLegacy;
class UEditableText;

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(Category="Fortnite UI", DisableNativeTick))
class UFortSignInWidget : public UCommonActivatablePanelLegacy
{
	GENERATED_BODY()

protected:
	UFUNCTION()
	void HandleTextCommitted(const FText& Text, ETextCommit::Type CommitMethod);

	UFUNCTION()
	void UpdateSignInButton(const FText& Text);

	UPROPERTY(EditAnywhere, Category="FortSignInWidget")
	TSubclassOf<UCommonBorderStyle> NormalBorderStyle;

	UPROPERTY(EditAnywhere, Category="FortSignInWidget")
	TSubclassOf<UCommonBorderStyle> HighlightBorderStyle;

private:
	UPROPERTY(EditAnywhere, Category="FortSignInWidget")
	FString ForgotPasswordURL;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UEditableText> EditText_Email;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UEditableText> EditText_Password;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonBorder> Border_Email;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonBorder> Border_Password;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_SignIn;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_ForgotPassword;

};

