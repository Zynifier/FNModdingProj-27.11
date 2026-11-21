// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Settings/Widgets/FortSettingsListEntry.h"
#include "HUDLayoutToolV2SettingsListEntry_Discrete.generated.h"

class UCommonTextBlock;
class UFortSettingValueDiscrete;
class UFortSettingsRotator;
class UHUDLayoutToolV2_Button;
class UPanelWidget;

UCLASS(Abstract, meta=(Category="Settings", DisableNativeTick))
class UHUDLayoutToolV2SettingsListEntry_Discrete : public UFortSettingsListEntry_Setting
{
	GENERATED_BODY()

protected:
	UPROPERTY()
	TObjectPtr<UFortSettingValueDiscrete> DiscreteSetting;

private:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UPanelWidget> Panel_Value;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_PropertyValue;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UHUDLayoutToolV2_Button> Button_DecreaseValue;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UHUDLayoutToolV2_Button> Button_IncreaseValue;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortSettingsRotator> Rotator_SettingValue;

};

