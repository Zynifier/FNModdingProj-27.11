// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "SocialInteractionMenu.generated.h"

class UCommonButtonLegacy;
class UCommonWidgetSwitcherLegacy;
class UDynamicEntryBox;
class USpacer;
class UTextBlock;
class UWidget;

UCLASS(Abstract, meta=(DisableNativeTick))
class SOCIALUMG_API USocialActionMenu : public UCommonActivatableWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION()
	void HandleMenuAnchorOpenChanged(bool bIsOpen);

	UFUNCTION(BlueprintImplementableEvent)
	void OnOpened();

};

UCLASS(Abstract, meta=(DisableNativeTick))
class SOCIALUMG_API USocialInteractionMenu : public USocialActionMenu
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintPure)
	UWidget* GetFirstEntryToCenter() const;

	UFUNCTION(BlueprintImplementableEvent)
	void OnToggleConfirmation(bool bIsVisible);

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UDynamicEntryBox> EntryBox_PositiveInteractions;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UDynamicEntryBox> EntryBox_NegativeInteractions;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<USpacer> Spacer_InteractionSeparator;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonWidgetSwitcherLegacy> Switcher_Confirmation;

	UPROPERTY(BlueprintReadOnly, Export, Category="SocialInteractionMenu", meta=(AllowPrivateAccess="TRUE", BindWidget, EditInline="true"))
	TObjectPtr<UTextBlock> Text_ConfirmationLabel;

	UPROPERTY(BlueprintReadOnly, Export, Category="SocialInteractionMenu", meta=(AllowPrivateAccess="TRUE", BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_Confirm;

	UPROPERTY(BlueprintReadOnly, Export, Category="SocialInteractionMenu", meta=(AllowPrivateAccess="TRUE", BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_Decline;

};

