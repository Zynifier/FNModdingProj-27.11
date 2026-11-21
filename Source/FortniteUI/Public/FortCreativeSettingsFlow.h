// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "Engine/DataTable.h"
#include "FortTabInterface.h"
#include "FortTabListWidgetBase.h"
#include "FortCreativeSettingsFlow.generated.h"

class UFortCreativeChannelBrowser;
class UFortCreativeDeviceBrowser;
class UWidgetSwitcher;

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortCreativeSettingsFlow : public UCommonActivatableWidget, public IFortTabInterface
{
	GENERATED_BODY()

private:
	UPROPERTY(BlueprintReadOnly, Export, Category="FortCreativeSettingsFlow", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UWidgetSwitcher> Switcher_EditorConnected;

	UPROPERTY(EditDefaultsOnly, Category="Fort Tab Interface")
	FName TabNameId;

	UPROPERTY(EditDefaultsOnly, Category="Fort Tab Interface")
	FFortTabButtonLabelInfo TabButtonLabelInfo;

	UPROPERTY(EditDefaultsOnly, Category="FortCreativeSettingsFlow", meta=(RowType="/Script/CommonUILegacy.CommonInputActionData"))
	FDataTableRowHandle ChannelBrowserInputRowHandle;

	UPROPERTY(EditDefaultsOnly, Category="FortCreativeSettingsFlow")
	TSoftClassPtr<UFortCreativeChannelBrowser> SoftChannelBrowserClass;

	UPROPERTY(EditDefaultsOnly, Category="FortCreativeSettingsFlow", meta=(RowType="/Script/CommonUILegacy.CommonInputActionData"))
	FDataTableRowHandle DeviceBrowserInputRowHandle;

	UPROPERTY(EditDefaultsOnly, Category="FortCreativeSettingsFlow")
	TSoftClassPtr<UFortCreativeDeviceBrowser> SoftDeviceBrowserClass;

};

