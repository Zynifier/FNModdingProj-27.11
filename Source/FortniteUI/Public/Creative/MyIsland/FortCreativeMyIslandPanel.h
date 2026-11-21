// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "Athena/AthenaMapScreenContainerTabInterface.h"
#include "FortCreativeSettingsFlow.h"
#include "FortCreativeMyIslandPanel.generated.h"

class AFortMinigame;
class AFortMinigameSettingsBuilding;
class UCommonAnimatedSwitcher;
class UFortMinigameVolumeComponent;
class UFortTabListWidgetBase;
class UWidget;
enum class EFortMinigameState : uint8;

UCLASS(Abstract, Config=Game, Blueprintable, meta=(DisableNativeTick, NotBlueprintType="true"))
class UFortCreativeMyIslandPanel : public UFortCreativeSettingsFlow, public IAthenaMapScreenContainerTabInterface
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintPure, meta=(BlueprintProtected))
	AFortMinigameSettingsBuilding* GetMinigameSettingsMachine() const;

	UFUNCTION(BlueprintPure, meta=(BlueprintProtected))
	UFortMinigameVolumeComponent* GetMinigameVolumeComponent() const;

	UFUNCTION(BlueprintPure, meta=(BlueprintProtected))
	bool IsOwnerOfCurrentExperience() const;

	UFUNCTION(BlueprintPure, meta=(BlueprintProtected))
	bool IsUpdatingTabVisibilities() const;

	UFUNCTION(BlueprintImplementableEvent)
	void OnActiveMainContentWidgetChanged(UWidget* ActiveWidget, const int32 ActiveWidgetIndex);

	UFUNCTION(BlueprintImplementableEvent)
	void OnMinigameSettingsChanged(AFortMinigameSettingsBuilding* MinigameSettings);

	UFUNCTION(BlueprintImplementableEvent)
	void OnMinigameStateChanged(const EFortMinigameState MinigameState);

	UFUNCTION(BlueprintImplementableEvent)
	void OnStartEndMinigameInput();

	UFUNCTION(BlueprintImplementableEvent)
	void OnTabVisibilitiesUpdated();

	UFUNCTION(BlueprintImplementableEvent)
	void ShouldShowTab(bool& bOutShouldShowTab, const FName TabID, const EFortMinigameState MinigameState, const bool bIsInReadOnlyExperience, const bool bIsOwnerOfCurrentExperience);

	UFUNCTION(BlueprintCallable, meta=(BlueprintProtected))
	void UpdateStartEndMinigameInput(const AFortMinigame* Minigame);

private:
	UFUNCTION()
	void HandleCreativePermissionsChanged();

	UFUNCTION()
	void HandleMinigameSettingsMachineChanged(UFortMinigameVolumeComponent* MinigameVolumeComponent, AFortMinigameSettingsBuilding* MinigameSettings);

	UFUNCTION()
	void HandleMinigameStateChanged(AFortMinigame* Minigame, EFortMinigameState MinigameState);

	UPROPERTY(BlueprintReadOnly, Export, Category="FortCreativeMyIslandPanel", meta=(AllowPrivateAccess, BindWidgetOptional, EditInline="true"))
	TObjectPtr<UFortTabListWidgetBase> TabList_MainContent;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortCreativeMyIslandPanel", meta=(AllowPrivateAccess, BindWidgetOptional, EditInline="true"))
	TObjectPtr<UCommonAnimatedSwitcher> Switcher_MainContent;

	UPROPERTY(EditDefaultsOnly, Category="Athena Map Screen Container Tab Interface")
	FAthenaMapScreenContainerTabInfo MapScreenContainerTabInfo;

	UPROPERTY(EditDefaultsOnly, Category="FortCreativeMyIslandPanel")
	bool bLinkTabListToSwitcher;

	UPROPERTY(EditDefaultsOnly, Category="FortCreativeMyIslandPanel")
	bool bBindToMinigame;

	UPROPERTY(EditDefaultsOnly, Category="FortCreativeMyIslandPanel")
	bool bIsDefaultMyIslandInfo;

	UPROPERTY(EditDefaultsOnly, Category="FortCreativeMyIslandPanel")
	bool bIsOverriddenMyIslandInfo;

	UPROPERTY(EditDefaultsOnly, Category="FortCreativeMyIslandPanel", meta=(RowType="/Script/CommonUILegacy.CommonInputActionData"))
	FDataTableRowHandle StartEndMinigameInputRowHandle;

	UPROPERTY(EditDefaultsOnly, Category="FortCreativeMyIslandPanel")
	FText StartMinigameText;

	UPROPERTY(EditDefaultsOnly, Category="FortCreativeMyIslandPanel")
	FText EndMinigameText;

	UPROPERTY(Config)
	TArray<FName> BlockedTabNames;

};

