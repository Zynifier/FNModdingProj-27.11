// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "Settings/FortSettingsFilterState.h"
#include "FortSettingsPanel.generated.h"

class UFortSetting;
class UFortSettingDetailView;
class UFortSettingRegistry;
class UFortSettingsListView;

UCLASS(Abstract, meta=(DisableNativeTick))
class UFortSettingsPanel : public UCommonUserWidget
{
	GENERATED_BODY()

public:
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnExecuteNamedActionBP, UFortSetting*, Setting, FName, Action);

private:
	UPROPERTY(Transient)
	TObjectPtr<UFortSettingRegistry> Registry;

	UPROPERTY(Transient)
	TArray<TObjectPtr<UFortSetting>> VisibleSettings;

	UPROPERTY(Transient)
	TObjectPtr<UFortSetting> LastHoveredOrSelectedSetting;

	UPROPERTY(Transient)
	FFortSettingsFilterState FilterState;

	UPROPERTY(Transient)
	TArray<FFortSettingsFilterState> FilterNavigationStack;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortSettingsPanel", meta=(AllowPrivateAccess="TRUE", BindWidget, BlueprintProtected="TRUE", EditInline="true"))
	TObjectPtr<UFortSettingsListView> ListView_Settings;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortSettingsPanel", meta=(AllowPrivateAccess="TRUE", BindWidgetOptional, BlueprintProtected="TRUE", EditInline="true"))
	TObjectPtr<UFortSettingDetailView> Details_Settings;

	UPROPERTY(BlueprintAssignable, Category="Events", meta=(DisplayName="On Execute Named Action", AllowPrivateAccess="true"))
	FOnExecuteNamedActionBP BP_OnExecuteNamedAction;

};

