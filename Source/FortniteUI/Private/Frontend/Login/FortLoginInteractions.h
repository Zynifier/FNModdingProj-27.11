// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "FortLoginInteractions.generated.h"

class UCommonActivatableWidgetSwitcher;
class UCommonButtonLegacy;
class UFortAccountLinkingWindow;
class UFortAccountNotFound;
class UFortAccountPinLinkingWindow;
class UFortCorrectiveActionDateOfBirthScreen;
class UFortCorrectiveActionFlow;
class UFortDisplayNameWidget;
class UFortEulaWidget;
class UFortLoginCredentialSelect;
class UFortMultiFactorAuthWidget;
class UFortPlayedBeforeSelect;
class UFortSignInWidget;
class UFortWebLoginWidget;
class USpacer;
class UWidget;

UCLASS(Abstract, meta=(DisableNativeTick))
class UFortLoginInteractions : public UCommonActivatableWidget
{
	GENERATED_BODY()

private:
	UFUNCTION()
	void HandleDismissWebAccountCreation();

	UFUNCTION()
	void HandleDismissWebLogin();

	UFUNCTION()
	void HandleDisplayWebAccountCreation(UWidget* WebWidget);

	UFUNCTION()
	void HandleDisplayWebLogin(UWidget* WebWidget);

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_Back;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonActivatableWidgetSwitcher> Switcher_Input;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<USpacer> Spacer_Default;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortPlayedBeforeSelect> PlayedBefore_Select;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortLoginCredentialSelect> Credential_Select;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortSignInWidget> SignIn_Credentials;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortAccountNotFound> Account_NotFound;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortDisplayNameWidget> DisplayName_Create;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortMultiFactorAuthWidget> MFA_Auth;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortEulaWidget> EULA_Accept;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortAccountLinkingWindow> Account_Link;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortAccountPinLinkingWindow> Account_PinLink;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortWebLoginWidget> Web_Login;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortCorrectiveActionDateOfBirthScreen> AgeGateScreen;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortCorrectiveActionFlow> CorrectiveActionFlow;

};

