// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Types/SlateEnums.h"
#include "FortCabinEmailManagementWidget.generated.h"

class UCommonButtonBase;
class UCommonTextBlock;
class UFortCTAButton;
class UFortInputField;
class UOverlay;
enum class ECabinEmailViewState : uint8;

UENUM(BlueprintType)
enum class ECabinEmailViewState : uint8
{
	Initial = 0,
	Sending = 1,
	Sent = 2,
	SendFailed = 3,
};

UCLASS(Abstract, BlueprintType, Blueprintable)
class UFortCabinEmailManagementWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	UFortCabinEmailManagementWidget(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

public:
	UFUNCTION(BlueprintImplementableEvent)
	void OnChangeEmailEditMode(bool bIsInEditMode);

	UFUNCTION(BlueprintImplementableEvent)
	void OnScreenStateChange(ECabinEmailViewState NewState);

	UFUNCTION(BlueprintImplementableEvent)
	void OnShowFailureReason(const FText& ErrorText);

protected:
	UFUNCTION()
	void HandleConfirmEmail(const FText& NewText, ETextCommit::Type CommitInfo);

	UPROPERTY(BlueprintReadWrite, Export, Category="FortCabinEmailManagementWidget", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UOverlay> Overlay_EmailEntry;

	UPROPERTY(BlueprintReadWrite, Export, Category="FortCabinEmailManagementWidget", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_Warning;

	UPROPERTY(BlueprintReadWrite, Export, Category="FortCabinEmailManagementWidget", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_MainDescription;

	UPROPERTY(BlueprintReadWrite, Export, Category="FortCabinEmailManagementWidget", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_Done;

	UPROPERTY(BlueprintReadWrite, Export, Category="FortCabinEmailManagementWidget", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_Cancel;

	UPROPERTY(BlueprintReadWrite, Export, Category="FortCabinEmailManagementWidget", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortCTAButton> Button_ResendEmail;

	UPROPERTY(BlueprintReadWrite, Export, Category="FortCabinEmailManagementWidget", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortCTAButton> Button_EditEmail;

	UPROPERTY(BlueprintReadWrite, Export, Category="FortCabinEmailManagementWidget", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortInputField> InputField_Email;

	UPROPERTY(BlueprintReadWrite, Export, Category="FortCabinEmailManagementWidget", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_Email;

};

