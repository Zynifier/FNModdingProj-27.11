// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "FortAthenaTutorialTextPrompt.generated.h"

class UCommonActionWidget;
class UFortKeybindWidget;
class UOverlay;
class URichTextBlock;
class UUserWidget;

UCLASS(meta=(DisableNativeTick))
class UFortAthenaTutorialTextPrompt : public UUserWidget
{
	GENERATED_BODY()

public:
	UFortAthenaTutorialTextPrompt(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

protected:
	UFUNCTION(BlueprintNativeEvent)
	void ActivateTextPrompt();

	UFUNCTION(BlueprintNativeEvent)
	void DisplayNextButton();

	UFUNCTION(BlueprintNativeEvent)
	void DisplayTarget();

	UFUNCTION(BlueprintCallable)
	void NextButtonPressed();

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Tutorial Text Config")
	FText TextToDisplay;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Tutorial Text Config")
	FText GamepadTextToDisplay;

private:
	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TArray<TObjectPtr<UFortKeybindWidget>> Array_FortKeybindWidget;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<URichTextBlock> RichText_TopPrompt;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<URichTextBlock> RichText_BottomPrompt;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<URichTextBlock> RichText_ExtraInputPrompt;

	UPROPERTY(BlueprintReadWrite, Export, Category="FortAthenaTutorialTextPrompt", meta=(AllowPrivateAccess="TRUE", BindWidget, EditInline="true"))
	TObjectPtr<UCommonActionWidget> ActionWidget_InputFeedback;

	UPROPERTY(BlueprintReadWrite, Export, Category="FortAthenaTutorialTextPrompt", meta=(AllowPrivateAccess="TRUE", BindWidget, EditInline="true"))
	TObjectPtr<UFortKeybindWidget> Action_KeybindWidget;

	UPROPERTY(BlueprintReadWrite, Export, Category="FortAthenaTutorialTextPrompt", meta=(AllowPrivateAccess="TRUE", BindWidget, EditInline="true"))
	TObjectPtr<UFortKeybindWidget> Action_KeybindWidget_1;

	UPROPERTY(BlueprintReadWrite, Export, Category="FortAthenaTutorialTextPrompt", meta=(AllowPrivateAccess="TRUE", BindWidget, EditInline="true"))
	TObjectPtr<UFortKeybindWidget> Action_KeybindWidget_2;

	UPROPERTY(BlueprintReadWrite, Export, Category="FortAthenaTutorialTextPrompt", meta=(AllowPrivateAccess="TRUE", BindWidget, EditInline="true"))
	TObjectPtr<UFortKeybindWidget> Action_KeybindWidget_3;

	UPROPERTY(BlueprintReadWrite, Export, Category="FortAthenaTutorialTextPrompt", meta=(AllowPrivateAccess="TRUE", BindWidget, EditInline="true"))
	TObjectPtr<UFortKeybindWidget> Action_KeybindWidget_4;

	UPROPERTY(BlueprintReadWrite, Export, Category="FortAthenaTutorialTextPrompt", meta=(AllowPrivateAccess="TRUE", BindWidget, EditInline="true"))
	TObjectPtr<UUserWidget> Tutorial_NextButton_Input;

	UPROPERTY(BlueprintReadWrite, Export, Category="FortAthenaTutorialTextPrompt", meta=(AllowPrivateAccess="TRUE", BindWidget, EditInline="true"))
	TObjectPtr<UOverlay> Overlay_AllWidgets;

	UPROPERTY(BlueprintReadWrite, Export, Category="FortAthenaTutorialTextPrompt", meta=(AllowPrivateAccess="TRUE", BindWidget, EditInline="true"))
	TObjectPtr<UOverlay> Overlay_ActionWidgets;

	UPROPERTY(BlueprintReadWrite, Export, Category="FortAthenaTutorialTextPrompt", meta=(AllowPrivateAccess="TRUE", BindWidget, EditInline="true"))
	TObjectPtr<UOverlay> Overlay_KeybindWidgets;

	UPROPERTY(BlueprintReadWrite, Export, Category="FortAthenaTutorialTextPrompt", meta=(AllowPrivateAccess="TRUE", BindWidget, EditInline="true"))
	TObjectPtr<UOverlay> Overlay_ExtraText;

};

