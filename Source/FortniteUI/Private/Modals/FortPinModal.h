// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "CommonButtonLegacy.h"
#include "UIManager/FortActivatablePanel.h"
#include "FortPinModal.generated.h"

class UCommonButtonBase;
class UCommonButtonGroupBase;
class UCommonRichTextBlock;
class UCommonTextBlock;
class UDynamicEntryBox;
class UFortCabinEmailManagementWidget;
class UFortGameActivity;
class UFortPinButton;
class UFortPinCharacter;
class UFortSqueegeeWidgetInjectionSlot;
enum class EPinModalValidityState : uint8;

UCLASS(Abstract, BlueprintType, Blueprintable, ClassGroup=("UI"), meta=(DisableNativeTick))
class UFortPinButton : public UCommonButtonLegacy
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortPinButton")
	FString PinValue;

};

UCLASS(Abstract, BlueprintType, Blueprintable, ClassGroup=("UI"), meta=(DisableNativeTick))
class UFortPinCharacter : public UUserWidget
{
	GENERATED_BODY()

public:
	UFortPinCharacter(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

public:
	UFUNCTION(BlueprintImplementableEvent)
	void OnSetFilled(const bool bFilled);

};

UCLASS(Abstract, BlueprintType, Blueprintable, ClassGroup=("UI"), meta=(DisableNativeTick))
class UFortPinModal : public UFortActivatablePanel
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent)
	TArray<UFortPinButton*> CollectPinButtons();

	UFUNCTION(BlueprintImplementableEvent)
	void OnSetPinState(const EPinModalValidityState PinModalState);

	UFUNCTION(BlueprintImplementableEvent)
	void OnShowCabinModeLayout(bool bIsInCabinMode);

	UFUNCTION(BlueprintImplementableEvent)
	void SetupSqueegeeWidgets(UFortGameActivity* GameActivity);

protected:
	UFUNCTION(BlueprintCallable)
	void ClosePinModal();

	UPROPERTY(EditAnywhere, Category="FortPinModal")
	TSubclassOf<UFortPinCharacter> PinCharacterWidgetClass;

private:
	UPROPERTY(BlueprintReadOnly, Export, Category="FortPinModal", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_Close;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortPinModal", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_CloseTouch;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortPinModal", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_Accept;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortPinModal", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_ForgotPin;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortPinModal", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonRichTextBlock> Text_Description;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortPinModal", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_Results;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortPinModal", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UDynamicEntryBox> DynamicEntryBox_Chars;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortPinModal", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UFortCabinEmailManagementWidget> EmailManagementWidget;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortPinModal", meta=(AllowPrivateAccess, BindWidgetOptional, EditInline="true"))
	TObjectPtr<UFortSqueegeeWidgetInjectionSlot> SqueegeeInjectionSlot;

	UPROPERTY()
	TObjectPtr<UCommonButtonGroupBase> ButtonGroup_CodeButtons;

};

