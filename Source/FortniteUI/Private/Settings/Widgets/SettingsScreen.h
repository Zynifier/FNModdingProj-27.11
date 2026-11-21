// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UIManager/FortActivatablePanel.h"
#include "SettingsScreen.generated.h"

class UFortSettingRegistry;
class UFortSettingsPanel;

UCLASS(Abstract, meta=(Category="Settings", DisableNativeTick))
class USettingsScreen : public UFortActivatablePanel
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintCallable)
	bool AttemptToPopNavigation();

	UFUNCTION(BlueprintCallable)
	void CloseSettings();

	UFUNCTION(BlueprintPure)
	bool HaveSettingsBeenChanged() const;

	UFUNCTION(BlueprintImplementableEvent)
	void HideSavingProgress();

	UFUNCTION(BlueprintCallable)
	void NavigateToSettings(TArray<FName> SettingsCollectionNames);

	UFUNCTION(BlueprintImplementableEvent)
	void OnSettingsDirtyStateChanged(bool bSettingsDirty);

	UFUNCTION(BlueprintCallable)
	void ResetSettings();

	UFUNCTION(BlueprintCallable)
	void SaveSettings();

	UFUNCTION(BlueprintImplementableEvent)
	void ShowSavingProgress();

private:
	UPROPERTY(BlueprintReadOnly, Export, Category="SettingsScreen", meta=(AllowPrivateAccess="TRUE", BindWidget, BlueprintProtected="TRUE", EditInline="true"))
	TObjectPtr<UFortSettingsPanel> Settings_Panel;

	UPROPERTY(Transient)
	TObjectPtr<UFortSettingRegistry> Registry;

};

