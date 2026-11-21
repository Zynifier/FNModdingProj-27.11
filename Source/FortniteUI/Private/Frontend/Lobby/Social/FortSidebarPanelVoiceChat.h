// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Types/SlateEnums.h"
#include "Frontend/Lobby/Social/FortSidebarPanelWithTree.h"
#include "FortSidebarPanelVoiceChat.generated.h"

class UCommonVisibilitySwitcher;
class UDataAsset;
class UFortSidebarOnboardTooltipWidget;
class UFortSocialUserTreeView;
class UFortVoiceSettingsDisplay;
class UMaterialInstance;
class UNamedSlot;
class UPanelWidget;
class USocialListEntryEmptyPanelBase;
class UTexture2D;
class UWidget;

UCLASS(Abstract, Config=Game, meta=(DisableNativeTick))
class UFortSidebarPanelVoiceChat : public UFortSidebarPanelWithTree
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent)
	void OpenParentalControls();

private:
	UFUNCTION()
	UWidget* HandleNavigateFromUserTree(const EUINavigation InNavigation);

	UFUNCTION()
	UWidget* HandleNavigateUpFromSettings(const EUINavigation InNavigation);

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortSocialUserTreeView> UserTree_VoiceChat;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonVisibilitySwitcher> VoiceChannelPanelSwitcher;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<USocialListEntryEmptyPanelBase> VoiceChatDisabledPanel;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UPanelWidget> VerticalBoxPanelUI;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UWidget> VoiceChatEnabledPanel;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortVoiceSettingsDisplay> SidebarVoiceChannelSettingsPanel;

	UPROPERTY(EditAnywhere, Category="FortSidebarPanelVoiceChat")
	TObjectPtr<UTexture2D> VoiceChatDisabledIcon;

	UPROPERTY(EditAnywhere, Category="FortSidebarPanelVoiceChat")
	TObjectPtr<UMaterialInstance> VoiceChatDisabledMaterial;

	UPROPERTY(Export, meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UFortSidebarOnboardTooltipWidget> SidebarVoiceChatPanelSupervisedSettingsTooltip;

	UPROPERTY(EditDefaultsOnly, Category="AudioModeration")
	TSoftObjectPtr<UDataAsset> LoadingVoiceRecordingPluginAssetObject;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<USocialListEntryEmptyPanelBase> SidebarVRRVoiceChatDeactivated;

	UPROPERTY(Export, meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UNamedSlot> VoiceTooltipSlot;

	UPROPERTY(Transient, Export, meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UFortSidebarOnboardTooltipWidget> VoiceTooltipWidget;

	UPROPERTY(EditAnywhere, Category="Widgets")
	TSubclassOf<UWidget> VRROnboardingWidgetClass;

};

