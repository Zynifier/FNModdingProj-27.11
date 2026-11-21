// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "Engine/DataTable.h"
#include "FortCreativeCreateBuildModal.generated.h"

class UButton;
class UCommonAnimatedSwitcher;
class UCommonButtonBase;
class UCommonTextBlock;
class UFortLazyImage;
class UPanelWidget;
class UWidget;

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortCreativeCreateBuildModal : public UCommonActivatableWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="Reset"))
	void BP_Reset();

	UFUNCTION(BlueprintImplementableEvent)
	void OnClearPersistentDataSet();

	UFUNCTION(BlueprintImplementableEvent)
	void OnContentSwitcherActiveWidgetChanged(UWidget* ActiveWidget);

	UFUNCTION(BlueprintImplementableEvent)
	void OnContentSwitcherTransitioningChanged(const bool bIsTransitioning);

	UFUNCTION(BlueprintImplementableEvent)
	void OnCreateBuildFailed(const FString& ErrorCode);

	UFUNCTION(BlueprintImplementableEvent)
	void OnCreateBuildStarted();

	UFUNCTION(BlueprintImplementableEvent)
	void OnCreateBuildSucceeded();

	UFUNCTION(BlueprintImplementableEvent)
	void OnMnemonicCopied();

	UFUNCTION(BlueprintImplementableEvent)
	void OnQrCodeImageUpdated();

	UFUNCTION(BlueprintImplementableEvent)
	void OnReceivedDoesIslandContainFabricDevices(const bool bIslandContainsFabricDevices);

	UFUNCTION(BlueprintCallable, meta=(BlueprintProtected))
	void SetClearPersistentData(const bool bInClearPersistentData);

	UFUNCTION(BlueprintCallable, meta=(BlueprintProtected))
	void SetClearPersistentDataInputEnabled(const bool bEnabled);

private:
	UFUNCTION()
	void HandleCreatorPortalUrlButtonClicked();

	UPROPERTY(BlueprintReadOnly, Export, Category="FortCreativeCreateBuildModal", meta=(AllowPrivateAccess, BindWidgetOptional, EditInline="true"))
	TObjectPtr<UCommonAnimatedSwitcher> Switcher_Content;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortCreativeCreateBuildModal", meta=(AllowPrivateAccess, BindWidgetOptional, EditInline="true"))
	TObjectPtr<UPanelWidget> Panel_CreateBuild;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortCreativeCreateBuildModal", meta=(AllowPrivateAccess, BindWidgetOptional, EditInline="true"))
	TObjectPtr<UPanelWidget> Panel_CreateBuildInProgress;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortCreativeCreateBuildModal", meta=(AllowPrivateAccess, BindWidgetOptional, EditInline="true"))
	TObjectPtr<UPanelWidget> Panel_CreateBuildSucceeded;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortCreativeCreateBuildModal", meta=(AllowPrivateAccess, BindWidgetOptional, EditInline="true"))
	TObjectPtr<UPanelWidget> Panel_CreateBuildFailed;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortCreativeCreateBuildModal", meta=(AllowPrivateAccess, BindWidgetOptional, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_PrimaryFunction;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortCreativeCreateBuildModal", meta=(AllowPrivateAccess, BindWidgetOptional, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_CloseTouch;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortCreativeCreateBuildModal", meta=(AllowPrivateAccess, BindWidgetOptional, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_CopyMnemonic;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortCreativeCreateBuildModal", meta=(AllowPrivateAccess, BindWidgetOptional, EditInline="true"))
	TObjectPtr<UButton> Button_CreatorPortalUrl;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortCreativeCreateBuildModal", meta=(AllowPrivateAccess, BindWidgetOptional, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_CreatorPortalUrl;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortCreativeCreateBuildModal", meta=(AllowPrivateAccess, BindWidgetOptional, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_Mnemonic;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortCreativeCreateBuildModal", meta=(AllowPrivateAccess, BindWidgetOptional, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_CreateBuildError;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortCreativeCreateBuildModal", meta=(AllowPrivateAccess, BindWidgetOptional, EditInline="true"))
	TObjectPtr<UFortLazyImage> LazyImage_CreatorPortalQrCode;

	UPROPERTY(BlueprintReadOnly, Category="FortCreativeCreateBuildModal", meta=(AllowPrivateAccess))
	bool bCreateBuildInProgress;

	UPROPERTY(BlueprintReadOnly, Category="FortCreativeCreateBuildModal", meta=(AllowPrivateAccess))
	bool bClearPersistentData;

	UPROPERTY(BlueprintReadOnly, Category="FortCreativeCreateBuildModal", meta=(AllowPrivateAccess))
	FString CreatedMnemonic;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortCreativeCreateBuildModal", meta=(AllowPrivateAccess, RowType="/Script/CommonUILegacy.CommonInputActionData"))
	FDataTableRowHandle ClearPersistentDataInputRowHandle;

};

