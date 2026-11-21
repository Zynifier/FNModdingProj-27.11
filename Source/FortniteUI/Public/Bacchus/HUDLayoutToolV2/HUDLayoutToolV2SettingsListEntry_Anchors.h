// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Settings/Widgets/FortSettingsListEntry.h"
#include "HUDLayoutToolV2SettingsListEntry_Anchors.generated.h"

class UFortSettingValueDiscreteDynamic_Anchors;
class UHUDLayoutToolV2_Button;

UCLASS(Abstract, meta=(Category="Settings", DisableNativeTick))
class UHUDLayoutToolV2SettingsListEntry_Anchors : public UFortSettingsListEntry_Setting
{
	GENERATED_BODY()

protected:
	UPROPERTY()
	TObjectPtr<UFortSettingValueDiscreteDynamic_Anchors> AnchorSetting;

private:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UHUDLayoutToolV2_Button> Button_TopLeft;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UHUDLayoutToolV2_Button> Button_TopMiddle;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UHUDLayoutToolV2_Button> Button_TopRight;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UHUDLayoutToolV2_Button> Button_MiddleLeft;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UHUDLayoutToolV2_Button> Button_MiddleMiddle;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UHUDLayoutToolV2_Button> Button_MiddleRight;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UHUDLayoutToolV2_Button> Button_BottomLeft;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UHUDLayoutToolV2_Button> Button_BottomMiddle;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UHUDLayoutToolV2_Button> Button_BottomRight;

};

