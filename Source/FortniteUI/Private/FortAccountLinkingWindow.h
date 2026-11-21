// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UIManager/FortActivatablePanel.h"
#include "FortAccountLinkingWindow.generated.h"

class UBackgroundBlur;
class UCircularThrobber;
class UCommonButtonLegacy;
class UCommonWidgetSwitcherLegacy;

UCLASS(Abstract, meta=(DisableNativeTick))
class UFortAccountLinkingWindow : public UFortActivatablePanel
{
	GENERATED_BODY()

public:
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FFortNewPlatformReceipt);

protected:
	UFUNCTION()
	void HandleLoginClicked();

	UFUNCTION()
	void HandleNoThanksClicked();

	UFUNCTION()
	void HandleSignupClicked();

	UFUNCTION()
	void HandleSkipLoginClicked();

	UFUNCTION()
	void HandleSkipNoThanksClicked();

	UFUNCTION()
	void HandleSkipSignUpClicked();

private:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonWidgetSwitcherLegacy> Switcher_Main;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UBackgroundBlur> HaveEpicAccountBlur;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UBackgroundBlur> SkipSignInBlur;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonWidgetSwitcherLegacy> Switcher_NoThanks;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCircularThrobber> Throbber_LoginDelay;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_Signup;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_Login;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_NoThanks;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_SkipSignInSignup;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_SkipSignInLogin;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_SkipSignInNoThanks;

};

