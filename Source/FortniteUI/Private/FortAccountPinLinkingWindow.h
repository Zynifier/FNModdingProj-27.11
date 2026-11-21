// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UIManager/FortActivatablePanel.h"
#include "FortAccountPinLinkingWindow.generated.h"

class UBackgroundBlur;
class UCircularThrobber;
class UCommonButtonLegacy;
class UCommonWidgetSwitcherLegacy;
class UFortPinGrantCodeInfoWidget;
class UHorizontalBox;

UCLASS(Abstract, meta=(DisableNativeTick))
class UFortAccountPinLinkingWindow : public UFortActivatablePanel
{
	GENERATED_BODY()

public:
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FFortNewPlatformReceipt);

public:
	UFUNCTION()
	void CreateHeadlessAccount();

	UFUNCTION()
	void PinCodeIssue(const FText& ErrorMessage, const FText& InfoText);

	UFUNCTION()
	void SetInitialSection();

	UFUNCTION()
	void SetPinGrantInfo(const FString& PinCode, const FString& ActivationURL, const FText& InfoText);

	UFUNCTION()
	void ShowCurrentPinInfo();

	UFUNCTION()
	void ShowPinLoading();

	UFUNCTION()
	void UpdateExpiringTime(int32 RemainingTime);

protected:
	UFUNCTION()
	void HandleCancelPinRequestClicked();

	UFUNCTION()
	void HandleCreateAccountClicked();

	UFUNCTION()
	void HandleGenerateCodeClicked();

	UFUNCTION()
	void HandleGoBackToInitialRequest();

	UFUNCTION()
	void HandleLinkAccountClicked();

	UFUNCTION()
	void HandleSkipLinkingClicked();

	UFUNCTION()
	void HandleSkipNoThanksClicked();

private:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonWidgetSwitcherLegacy> Switcher_Main;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UBackgroundBlur> Blur_PinGrantCodeInfo;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UBackgroundBlur> Blur_InitialRequest;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UBackgroundBlur> Blur_SkipSignIn;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonWidgetSwitcherLegacy> Switcher_NoThanks;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCircularThrobber> Throbber_LoginDelay;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_CreateEpicAccount;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortAccountPinLinkingWindow", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_GoLinking;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_SkipLinking;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_CancelPinRequest;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortAccountPinLinkingWindow", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_SkipGoBackLinking;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_SkipSignInNoThanks;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UHorizontalBox> Container_CreateEpicAccount;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortPinGrantCodeInfoWidget> PinGrantCodeInfoWidget;

};

