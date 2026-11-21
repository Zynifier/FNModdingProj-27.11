// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "Misc/DateTime.h"
#include "Creative/MyIsland/FortCreativeMyIslandContentPanelInterface.h"
#include "Items/FortCreativeRealEstatePlotItem.h"
#include "FortCreativePublishOptions.generated.h"

class UCommonActivatableWidget;
class UCommonAnimatedSwitcher;
class UCommonButtonBase;
class UCommonTextBlock;
class UPanelWidget;
enum class EBackupSaveState : uint8;
enum class EFortCreativePlotPermission : uint8;

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortCreativePublishOptions : public UCommonActivatableWidget, public IFortCreativeMyIslandContentPanelInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void BackupMyIsland();

	UFUNCTION()
	void CheckpointRestoreStateChanged(EBackupSaveState SaveState);

	UFUNCTION()
	void CheckpointSaveStateChanged(EBackupSaveState SaveState);

	UFUNCTION(BlueprintCallable)
	virtual void InitializeData();

	UFUNCTION(BlueprintImplementableEvent)
	void OnBackupMyIsland(bool bSuccess);

	UFUNCTION(BlueprintImplementableEvent)
	void OnRestoreMyIslandFromBackup(bool bSuccess);

	UFUNCTION(BlueprintImplementableEvent)
	void OnRestoreStateChanged(bool bReady);

	UFUNCTION(BlueprintImplementableEvent)
	void OnSaveStateChanged(bool bSuccess);

	UFUNCTION(BlueprintCallable)
	void OptInForDeviceUpgrades();

	UFUNCTION(BlueprintCallable)
	void OptInForMemorySystemUpgrades();

	UFUNCTION(BlueprintCallable, BlueprintPure=false)
	void ResetMyCurrentCreativePlot() const;

	UFUNCTION(BlueprintCallable)
	void RestoreMyIslandFromBackup();

	UFUNCTION(BlueprintPure, meta=(BlueprintProtected))
	bool ShouldUseLegacyPublishUI() const;

	UFUNCTION(BlueprintCallable, BlueprintPure=false)
	void UpdatePermissions(const EFortCreativePlotPermission Permissions) const;

	UFUNCTION()
	void UpdateTimeSinceLastBackup(FDateTime LastBackup);

	UPROPERTY(BlueprintReadOnly, Category="FortCreativePublishOptions")
	EFortCreativePlotPermission CurrentPermissionsEnum;

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnDataInitialized();

private:
	UPROPERTY(Export, meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UPanelWidget> Panel_IslandBackup;

	UPROPERTY(Export, meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UPanelWidget> Panel_IslandRestore;

	UPROPERTY(Export, meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UPanelWidget> Panel_OptInForDeviceUpgrades;

	UPROPERTY(Export, meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UPanelWidget> Panel_OptInForMemorySystemUpgrades;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortCreativePublishOptions", meta=(AllowPrivateAccess, BindWidgetOptional, EditInline="true"))
	TObjectPtr<UCommonAnimatedSwitcher> Switcher_IslandPublish;

	UPROPERTY(Export, meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UPanelWidget> Panel_IslandPublish;

	UPROPERTY(Export, meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UPanelWidget> Panel_HowToPublish;

	UPROPERTY(Export, meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_RestoreTime;

	UPROPERTY(Export, meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_OnCooldown;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortCreativePublishOptions", meta=(AllowPrivateAccess, BindWidgetOptional, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_Publish;

	UPROPERTY(EditDefaultsOnly, Category="FortCreativePublishOptions")
	TSoftClassPtr<UCommonActivatableWidget> SoftPublishModalClass;

	UPROPERTY(EditDefaultsOnly, Category="FortCreativePublishOptions")
	TSoftClassPtr<UCommonActivatableWidget> SoftCreateBuildModalClass;

};

