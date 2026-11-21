// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/Color.h"
#include "Settings/Widgets/FortSettingsListEntry.h"
#include "HUDLayoutToolV2SettingsListEntry_QuickbarLocks.generated.h"

class UFortDynamicEntryBox;
class UFortSettingValueDiscreteDynamic_QuickbarLocks;

UCLASS(Abstract, meta=(Category="Settings", DisableNativeTick))
class UHUDLayoutToolV2SettingsListEntry_QuickbarLocks : public UFortSettingsListEntry_Setting
{
	GENERATED_BODY()

protected:
	UPROPERTY()
	TObjectPtr<UFortSettingValueDiscreteDynamic_QuickbarLocks> QuickbarLocksSetting;

private:
	UPROPERTY(EditAnywhere, Category="HUDLayoutToolV2SettingsListEntry_QuickbarLocks")
	FLinearColor LockEnabledColor;

	UPROPERTY(EditAnywhere, Category="HUDLayoutToolV2SettingsListEntry_QuickbarLocks")
	FLinearColor LockDisabledColor;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortDynamicEntryBox> EntryBox_SlotLocks;

};

