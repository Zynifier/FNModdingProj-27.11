// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Settings/Widgets/FortSettingsListEntry.h"
#include "HUDLayoutToolV2SettingsListEntry_Bool.generated.h"

class UFortSettingValueDiscrete;
class UHUDLayoutToolV2_Button;
class UPanelWidget;
class UPaperSprite;

UCLASS(Abstract, meta=(Category="Settings", DisableNativeTick))
class UHUDLayoutToolV2SettingsListEntry_Bool : public UFortSettingsListEntry_Setting
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, Category="HUDLayoutToolV2SettingsListEntry_Bool")
	TObjectPtr<UPaperSprite> CheckMarkSprite;

	UPROPERTY()
	TObjectPtr<UFortSettingValueDiscrete> BoolSetting;

private:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UPanelWidget> Panel_Value;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UHUDLayoutToolV2_Button> Button_ToggleBool;

};

