// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Bacchus/HUDLayoutToolV2/HUDLayoutToolV2_Popup.h"
#include "HUDLayoutToolV2_TextInputPopup.generated.h"

class UFortEditableFilteredCountedTextBox;
class UHUDLayoutToolV2_Button;

UENUM()
enum class EHUDLayoutToolTextInputPopupType : uint8
{
	Rename = 0,
	ImportLayoutID = 1,
};

USTRUCT(BlueprintType)
struct FHUDLayoutToolV2_TextInputPopupContent
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="HUDLayoutToolV2_TextInputPopupContent")
	EHUDLayoutToolTextInputPopupType PopupType;

	UPROPERTY(EditAnywhere, Category="HUDLayoutToolV2_TextInputPopupContent")
	FText TitleText;

	UPROPERTY(EditAnywhere, Category="HUDLayoutToolV2_TextInputPopupContent")
	FText DescriptionText;

	UPROPERTY(EditAnywhere, Category="HUDLayoutToolV2_TextInputPopupContent")
	FText ButtonConfirmText;

	UPROPERTY(EditAnywhere, Category="HUDLayoutToolV2_TextInputPopupContent")
	FText ButtonCancelText;

};

UCLASS(Abstract)
class UHUDLayoutToolV2_TextInputPopup : public UHUDLayoutToolV2_Popup
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="HUDLayoutToolV2_TextInputPopup")
	FText InvalidCharacterText;

	UPROPERTY(Export, meta=(Bindwidget, EditInline="true"))
	TObjectPtr<UFortEditableFilteredCountedTextBox> EditableFilteredTextBox_UserInput;

	UPROPERTY(Export, meta=(Bindwidget, EditInline="true"))
	TObjectPtr<UHUDLayoutToolV2_Button> Button_Paste;

};

