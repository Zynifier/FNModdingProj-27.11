// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UIManager/FortActivatablePanel.h"
#include "EnableMultiFactorModal.generated.h"

class UCommonButtonLegacy;
class UCommonTextBlock;

UCLASS(Abstract, MinimalAPI, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UEnableMultiFactorModal : public UFortActivatablePanel
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	bool QueueModal(bool bAllowPermanentOptOut = false, bool bTournamentQueue = false);

protected:
	UFUNCTION(BlueprintCallable)
	void AnimationsComplete();

	UFUNCTION(BlueprintImplementableEvent)
	void OnConsoleDisplayURLProvided(const FText& UniquePlayerURLText);

	UFUNCTION(BlueprintImplementableEvent)
	void OnSetExitButtonText(const FText& NewButtonText);

	UFUNCTION(BlueprintImplementableEvent)
	void OnSetScreenConfiguration(bool bIsConsole);

	UPROPERTY(BlueprintReadOnly, Category="EnableMultiFactorModal")
	bool bHasEnableMFABeenClicked;

	UPROPERTY(BlueprintReadOnly, Category="EnableMultiFactorModal")
	bool bShouldShowConsoleVersion;

private:
	UPROPERTY(BlueprintReadOnly, Export, Category="EnableMultiFactorModal", meta=(AllowPrivateAccess="TRUE", BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_EnableMFA;

	UPROPERTY(BlueprintReadOnly, Export, Category="EnableMultiFactorModal", meta=(AllowPrivateAccess="TRUE", BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_RemindLater;

	UPROPERTY(BlueprintReadOnly, Export, Category="EnableMultiFactorModal", meta=(AllowPrivateAccess="TRUE", BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_OptOut;

	UPROPERTY(BlueprintReadOnly, Export, Category="EnableMultiFactorModal", meta=(AllowPrivateAccess="TRUE", BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_ConsoleMFAEnabled;

	UPROPERTY(BlueprintReadOnly, Export, Category="EnableMultiFactorModal", meta=(AllowPrivateAccess="TRUE", BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> CT_MFA_Description;

};

