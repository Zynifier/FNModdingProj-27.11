// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "Engine/DataTable.h"
#include "FortClientSettingsRecord.h"
#include "FortQuestMapScreen.generated.h"

class UFortCampaignNewsPanel;
class UFortQuestItem;
class UFortQuestItemDefinition;
class UFortQuestMapDataAsset;
class UFortQuestMapDetailsPanelBase;
class UFortQuestMapEventCallout;
class UFortQuestMapViewer;
class UFortQuestScreen;
enum class EFrontEndCamera : uint8;
enum class EQuestMapScreenMode : uint8;
enum class EViewerNavigationDirection : uint8;

UCLASS(BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortQuestMapScreen : public UCommonActivatableWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Map Screen")
	void CheckForNewMainQuest();

	UFUNCTION(BlueprintPure, Category="Map Screen")
	bool GetBeyondCutoffQuest() const;

	UFUNCTION(BlueprintPure, Category="MapScreen")
	EFrontEndCamera GetCurrentPageCameraMode() const;

	UFUNCTION(BlueprintImplementableEvent, Category="MapScreen", meta=(DisplayName="Handle Event Callout Data Changed"))
	void HandleEventCalloutDataChangedBP();

	UFUNCTION(BlueprintCallable)
	void HandleEventQuestMapActivate();

	UFUNCTION(BlueprintImplementableEvent, Category="MapScreen")
	void HandleMapModeSwitch();

	UFUNCTION(BlueprintCallable, Category="Map Screen")
	void HandleMapViewerNavigationRequest(EViewerNavigationDirection Direction);

	UFUNCTION(BlueprintImplementableEvent, Category="MapScreen")
	void HandleQuestDetailsUpdated(UFortQuestItem* QuestDefinition);

	UFUNCTION(BlueprintImplementableEvent, Category="MapScreen")
	void HandleQuestPageChanged();

	UFUNCTION(BlueprintCallable, Category="Map Screen")
	void InitializeQuestData();

	UFUNCTION(BlueprintPure, Category="Map Screen")
	bool IsBeyondQuest(UFortQuestItemDefinition* QuestDef) const;

	UFUNCTION(BlueprintCallable, Category="Map Screen")
	bool IsEventFlagActive(const FString& EventFlag);

	UFUNCTION(BlueprintImplementableEvent, Category="MapScreen")
	void OnEventCalloutButtonClicked();

	UFUNCTION(BlueprintImplementableEvent, Category="MapScreen")
	void OnEventCalloutExpandChanged();

	UFUNCTION(BlueprintImplementableEvent, Category="MapScreen")
	void OnShowCurrentQuestInputActionValueChanged();

	UFUNCTION(BlueprintCallable, Category="Map Screen")
	void SetBeyondCutoffQuest(bool bBeyondCutoff);

	UFUNCTION(BlueprintCallable, Category="MapScreen")
	void SetIgnorePageNavigation(bool bIgnoreNavigation);

	UFUNCTION(BlueprintCallable, Category="Map Screen")
	void SetQuestMapViewer(UFortQuestMapViewer* Value);

	UFUNCTION(BlueprintCallable, Category="Map Screen")
	void ToggleQuestMapState();

	UFUNCTION(BlueprintImplementableEvent, Category="MapScreen")
	void UpdateQuestMapMode(EQuestMapScreenMode QuestMapMode);

	UPROPERTY(BlueprintReadOnly, Export, Category="FortQuestMapScreen", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortQuestMapDetailsPanelBase> CampaignDetailsPanel;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortQuestMapScreen", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortQuestMapDetailsPanelBase> EventDetailsPanel;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortQuestMapScreen", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortQuestMapEventCallout> EventCalloutPanel;

	UPROPERTY(BlueprintReadWrite, Export, Category="FortQuestMapScreen", meta=(EditInline="true"))
	TObjectPtr<UFortQuestMapViewer> QuestMapViewer;

	UPROPERTY(BlueprintReadOnly, Category="FortQuestMapScreen")
	EQuestMapScreenMode CurrentMode;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortQuestMapScreen")
	bool bEventsActive;

	UPROPERTY(BlueprintReadOnly, Category="FortQuestMapScreen")
	TObjectPtr<UFortQuestMapDataAsset> CampaignQuestMapDataTable;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortQuestMapScreen")
	TObjectPtr<UFortQuestItemDefinition> CutoffQuest;

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void ClaimQuestRewards(const UFortQuestItem* QuestItem);

	UFUNCTION(BlueprintImplementableEvent)
	void HandleBackInputAction();

	UFUNCTION(BlueprintCallable)
	void ShowQuestLog(UFortQuestItem* QuestItem = nullptr);

	UFUNCTION(BlueprintCallable)
	void UpdateInputActionStates(bool bShowingCallout);

private:
	UFUNCTION()
	void HandleQuestIndexSelectionModelChanged(bool bUpdateButtonSelection);

	UPROPERTY()
	TObjectPtr<UFortQuestMapDataAsset> CurrentQuestMapDataTable;

	UPROPERTY(EditAnywhere, Category="FortQuestMapScreen")
	TSubclassOf<UFortCampaignNewsPanel> CampaignNewsModalClass;

	UPROPERTY(EditAnywhere, Category="FortQuestMapScreen")
	TSubclassOf<UFortQuestScreen> QuestLogScreenClass;

	UPROPERTY(EditDefaultsOnly, Category="FortQuestMapScreen")
	FDataTableRowHandle CurrentQuestAction;

	UPROPERTY(EditDefaultsOnly, Category="FortQuestMapScreen")
	FDataTableRowHandle STWNewsAction;

	UPROPERTY(EditDefaultsOnly, Category="FortQuestMapScreen")
	FDataTableRowHandle BackAction;

};

