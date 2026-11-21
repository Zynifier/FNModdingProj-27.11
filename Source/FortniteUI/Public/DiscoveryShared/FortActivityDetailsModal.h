// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "DiscoveryShared/FortActivityView.h"
#include "FortActivityDetailsModal.generated.h"

class UCommonActivatableWidget;
class UCommonButtonBase;
class UCommonTextBlock;
class UFortActivityDetailsDisplay;
class UFortActivityModeSetSelection;
class UFortActivityPrivacyButton;
class UFortActivitySquadFillButton;
class UFortActivityVideoCycle;
class UFortGameActivity;
class UTexture;
enum class EFortInvalidActivityReason : uint8;

UENUM()
enum class EFortActivityDetailsModalExitPath : uint8
{
	Undefined = 0,
	Discover = 1,
	Lobby = 2,
	Creator = 3,
	Attributions = 4,
	MAX_NUM = 5,
};

UCLASS(Abstract, Config=Game, MinimalAPI, meta=(DisableNativeTick))
class UFortActivityDetailsModal : public UFortActivityView
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	EFortInvalidActivityReason GetInvalidActivityReason() const;

protected:
	UFUNCTION(BlueprintPure)
	const UFortGameActivity* GetSelectedGameActivity() const;

	UFUNCTION(BlueprintPure)
	bool IsCreativeModeSetActivity() const;

	UFUNCTION(BlueprintPure)
	const bool IsLocalPlayerPartyLeader() const;

	UFUNCTION(BlueprintPure)
	bool IsModeSetActivity() const;

	UFUNCTION(BlueprintImplementableEvent)
	void OnIsFavoriteChanged(const bool bIsFavorite);

	UFUNCTION(BlueprintImplementableEvent)
	void OnPreviewImageChanged(const bool bIsLoading, const UTexture* Texture);

	UFUNCTION(BlueprintImplementableEvent)
	void OnSelectedSubModeTextChanged(const FText& ActivityText, const FText& SettingText);

	UFUNCTION(BlueprintImplementableEvent)
	void OnShowSubModeFirstTimeNotification(const FText& ActivityAndSettingText);

	UFUNCTION(BlueprintImplementableEvent)
	void OnSubModeSelectionChanged();

private:
	UPROPERTY(EditAnywhere, Config, Category="UI", meta=(DisplayName="Enable access to Creator Page through Activity Details screen"))
	bool bIsCreatorPageAccessEnabled;

	UPROPERTY(EditAnywhere, Config, Category="UI", meta=(DisplayName="Force Creator Page first time tooltip on Activity Details screen"))
	bool bShouldForceCreatorPageFirstTimeTooltip;

	UPROPERTY(EditAnywhere, Config, Category="UI", meta=(DisplayName="Enable access to UEFN Attributions modal through Activity Details screen"))
	bool bIsUEFNAttributionsAccessEnabled;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_LinkCode;

	UPROPERTY(Export, meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_LinkCodeVersion;

	UPROPERTY(Export, meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_VersionSubmode;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortActivityDetailsModal", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UFortActivityDetailsDisplay> DetailsDisplay_SelectedActivity;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_CloseTouch;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_Back;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_BackBoard;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortActivityVideoCycle> ActivityVideoCycle;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortActivityDetailsModal", meta=(AllowPrivateAccess, BindWidgetOptional, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_Favorite;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortActivityDetailsModal", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UFortActivityModeSetSelection> List_SubModeList;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortActivityDetailsModal", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UFortActivitySquadFillButton> Button_SquadFillButton;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortActivityDetailsModal", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UFortActivityPrivacyButton> Button_PrivacyButton;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortActivityDetailsModal", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_CreatorPage;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortActivityDetailsModal", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_Attributions;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortActivityDetailsModal", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonActivatableWidget> ActivityDetailsModal_CreatorPageTooltip;

};

