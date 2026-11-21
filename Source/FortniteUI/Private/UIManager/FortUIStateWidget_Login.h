// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UIManager/FortUIStateWidgetBase.h"
#include "FortUIStateWidget_Login.generated.h"

class UCommonActivatableWidgetSwitcher;
class UCommonButtonLegacy;
class UFortLoginInteractions;
class UFortLoginStatus;
class UFortQualityLevelSelectScreen;
class UFortSafeZoneEditor;
class UFortSplashScreenWidget;
class UHealthWarningScreen;
class UUserWidget;

UENUM()
enum class EFortLoginDisplay : uint8
{
	LoginStatus = 0,
	SplashScreen = 1,
	SignIn = 2,
	SafeZoneEditor = 3,
	HealthWarning = 4,
	QualityPresetSelection = 5,
};

UCLASS(Abstract, Config=Game, meta=(DisableNativeTick))
class UFortUIStateWidget_Login : public UFortUIStateWidgetBase
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void SetKeyArtVisibility(int32 NewActiveWidgetIndex);

private:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_Cancel;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UUserWidget> ActionBar_Bottom;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortUIStateWidget_Login", meta=(AllowPrivateAccess="TRUE", BindWidget, EditInline="true"))
	TObjectPtr<UCommonActivatableWidgetSwitcher> Switcher_ScreenContents;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortSafeZoneEditor> Editor_SafeZone;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortLoginStatus> Status_LoginInfo;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortSplashScreenWidget> Splash_Screen;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortLoginInteractions> Login_Interactions;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UHealthWarningScreen> HealthWarningScreen_HealthInfo;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortQualityLevelSelectScreen> QualityLevelSelectScreen_SelectInfo;

	UPROPERTY(Config)
	bool bShowQuitButtonOnXbox;

};

