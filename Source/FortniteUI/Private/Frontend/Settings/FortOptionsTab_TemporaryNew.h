// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Frontend/Settings/FortOptionsTab.h"
#include "FortOptionsTab_TemporaryNew.generated.h"

class UFortGameSettingRegistry;
class UFortSettingsPanel;

UCLASS(Abstract, meta=(DisableNativeTick))
class UFortOptionsTab_NewSystemShim : public UFortOptionsTab
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	bool AttemptToPopNavigation();

protected:
	UPROPERTY(Transient)
	TObjectPtr<UFortGameSettingRegistry> Registry;

private:
	UPROPERTY(BlueprintReadOnly, Export, Category="FortOptionsTab_NewSystemShim", meta=(AllowPrivateAccess="TRUE", BindWidget, BlueprintProtected="TRUE", EditInline="true"))
	TObjectPtr<UFortSettingsPanel> Settings_Panel;

};

UCLASS(Abstract, meta=(DisableNativeTick))
class UFortTabAccountOptions_TempNew : public UFortOptionsTab_NewSystemShim
{
	GENERATED_BODY()

private:
	UFUNCTION(BlueprintCallable)
	void ViewPurchaseHistory();

};

UCLASS(Abstract, meta=(DisableNativeTick))
class UFortTabAudioOptions_TempNew : public UFortOptionsTab_NewSystemShim
{
	GENERATED_BODY()

};

UCLASS(Abstract)
class UFortTabControllerBindingsOptions_TempNew : public UFortOptionsTab_NewSystemShim
{
	GENERATED_BODY()

};

UCLASS(Abstract)
class UFortTabGamepadButtonMappingOptions_TempNew : public UFortOptionsTab_NewSystemShim
{
	GENERATED_BODY()

};

UCLASS(Abstract, meta=(DisableNativeTick))
class UFortTabGamepadOptions_TempNew : public UFortOptionsTab_NewSystemShim
{
	GENERATED_BODY()

};

UCLASS(Abstract, meta=(DisableNativeTick))
class UFortTabGameplayOptions_TempNew : public UFortOptionsTab_NewSystemShim
{
	GENERATED_BODY()

};

UCLASS(Abstract, meta=(DisableNativeTick))
class UFortTabHUDOptions_TempNew : public UFortOptionsTab_NewSystemShim
{
	GENERATED_BODY()

};

UCLASS(Abstract)
class UFortTabMouseAndKeyboardBindingsOptions_TempNew : public UFortOptionsTab_NewSystemShim
{
	GENERATED_BODY()

};

UCLASS(Abstract, meta=(DisableNativeTick))
class UFortTabMouseAndKeyboardOptions_TempNew : public UFortOptionsTab_NewSystemShim
{
	GENERATED_BODY()

};

UCLASS(Abstract, meta=(DisableNativeTick))
class UFortTabTouchOptions_TempNew : public UFortOptionsTab_NewSystemShim
{
	GENERATED_BODY()

};

UCLASS(Abstract, meta=(DisableNativeTick))
class UFortTabTouchWeaponOptions_TempNew : public UFortOptionsTab_NewSystemShim
{
	GENERATED_BODY()

};

UCLASS(Abstract, meta=(DisableNativeTick))
class UFortTabVideoOptions_TempNew : public UFortOptionsTab_NewSystemShim
{
	GENERATED_BODY()

};

