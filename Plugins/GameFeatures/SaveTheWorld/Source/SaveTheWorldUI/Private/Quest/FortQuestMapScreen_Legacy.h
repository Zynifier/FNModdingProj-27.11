// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUITypes.h"
#include "CommonActivatablePanelLegacy.h"
#include "FortClientSettingsRecord.h"
#include "FortQuestMapScreen_Legacy.generated.h"

class UFortQuestItem;
class UFortQuestItemDefinition;
class UFortQuestMapDataAsset;
class UFortQuestMapDetailsPanelBase;
class UFortQuestMapEventCallout_Legacy;
class UFortQuestMapViewer_Legacy;
enum class EFrontEndCamera : uint8;
enum class EQuestMapScreenMode : uint8;
enum class EViewerNavigationDirection : uint8;

UCLASS(BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortQuestMapScreen_Legacy : public UCommonActivatablePanelLegacy
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

	UFUNCTION(BlueprintCallable)
	void HandleRequestCurrentQuestNavigation();

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

	UFUNCTION(BlueprintCallable, Category="Map Screen")
	void SetBeyondCutoffQuest(bool bBeyondCutoff);

	UFUNCTION(BlueprintImplementableEvent, Category="MapScreen")
	void SetFindCurrentActionVisibility(EInputActionState ActionVisibility);

	UFUNCTION(BlueprintCallable, Category="MapScreen")
	void SetIgnorePageNavigation(bool bIgnoreNavigation);

	UFUNCTION(BlueprintCallable, Category="Map Screen")
	void SetQuestMapViewer(UFortQuestMapViewer_Legacy* Value);

	UFUNCTION(BlueprintCallable, Category="Map Screen")
	void ToggleQuestMapState();

	UFUNCTION(BlueprintImplementableEvent, Category="MapScreen")
	void UpdateQuestMapMode(EQuestMapScreenMode QuestMapMode);

	UPROPERTY(BlueprintReadOnly, Export, Category="FortQuestMapScreen_Legacy", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortQuestMapDetailsPanelBase> CampaignDetailsPanel;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortQuestMapScreen_Legacy", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortQuestMapDetailsPanelBase> EventDetailsPanel;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortQuestMapScreen_Legacy", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortQuestMapEventCallout_Legacy> EventCalloutPanel;

	UPROPERTY(BlueprintReadWrite, Export, Category="FortQuestMapScreen_Legacy", meta=(EditInline="true"))
	TObjectPtr<UFortQuestMapViewer_Legacy> QuestMapViewer;

	UPROPERTY(BlueprintReadOnly, Category="FortQuestMapScreen_Legacy")
	EQuestMapScreenMode CurrentMode;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortQuestMapScreen_Legacy")
	bool bEventsActive;

	UPROPERTY(BlueprintReadOnly, Category="FortQuestMapScreen_Legacy")
	TObjectPtr<UFortQuestMapDataAsset> CampaignQuestMapDataTable;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortQuestMapScreen_Legacy")
	TObjectPtr<UFortQuestItemDefinition> CutoffQuest;

private:
	UFUNCTION()
	void HandleQuestIndexSelectionModelChanged(bool bUpdateButtonSelection);

	UPROPERTY()
	TObjectPtr<UFortQuestMapDataAsset> CurrentQuestMapDataTable;

};

