// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "CommonInputTypeEnum.h"
#include "AthenaFullScreenMapControlsWidget.generated.h"

class UAthenaConfirmationWindow;
class UCommonButtonBase;
class UFortCTAButton;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnRemoveSelectedQuestButtonClicked);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnSortToggleButtonClicked);

UCLASS(Abstract, meta=(DisableNativeTick))
class UAthenaFullScreenMapControlsWidget : public UCommonActivatableWidget
{
	GENERATED_BODY()

public:
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnExitMapButtonClicked);
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnInspectItemsButtonClicked);
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnPinSelectedCategoryButtonClicked);
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnPinSelectedQuestButtonClicked);
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnViewPlaylistButtonClicked, FString, IslandMnemonic, const FName, PlaylistName);

protected:
	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="Handle Toggle Quest Icons Clicked"))
	void BP_HandleToggleQuestIconsClicked();

	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="On Input Type Changed"))
	void BP_OnInputTypeChanged(const ECommonInputType NewInputType);

	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="On Layout Shuffled"))
	void BP_OnLayoutShuffled();

	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="On Sort Type Text Changed"))
	void BP_OnSortTypeTextChanged(const FText& TypeText);

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaFullScreenMapControlsWidget", meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_SortToggle;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaFullScreenMapControlsWidget", meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_RemoveSelectedQuest;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaFullScreenMapControlsWidget", meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UFortCTAButton> Button_PinSelectedQuest;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaFullScreenMapControlsWidget", meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UFortCTAButton> Button_PinSelectedCategory;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaFullScreenMapControlsWidget", meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UFortCTAButton> Button_ViewPlaylist;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaFullScreenMapControlsWidget", meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UFortCTAButton> Button_QuestNPCIcons;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaFullScreenMapControlsWidget", meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UFortCTAButton> Button_InspectItems;

private:
	UPROPERTY(Export, meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_ToggleQuestIcons;

	UPROPERTY(Export, meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_ResetToPlayer;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaFullScreenMapControlsWidget", meta=(AllowPrivateAccess="TRUE", BindWidgetOptional, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_Exit;

	UPROPERTY(EditAnywhere, Category="Text", meta=(DisplayName="NPC Icons On"))
	FText TextNPCIconsOn;

	UPROPERTY(EditAnywhere, Category="Text", meta=(DisplayName="NPC Icons Off"))
	FText TextNPCIconsOff;

	UPROPERTY(EditAnywhere, Category="Text", meta=(DisplayName="Pin Quest"))
	FText TextPinQuest;

	UPROPERTY(EditAnywhere, Category="Text", meta=(DisplayName="Unpin Quest"))
	FText TextUnpinQuest;

	UPROPERTY(EditAnywhere, Category="Text", meta=(DisplayName="Pin Category"))
	FText TextPinCategory;

	UPROPERTY(EditAnywhere, Category="Text", meta=(DisplayName="Unpin Category"))
	FText TextUnpinCategory;

	UPROPERTY(EditAnywhere, Category="Text", meta=(DisplayName="Remove Quest"))
	FText TextConfirmRemoveQuestTitle;

	UPROPERTY(EditAnywhere, Category="Text", meta=(DisplayName="Remove Quest Desc"))
	FText TextConfirmRemoveQuestDescription;

	UPROPERTY(EditDefaultsOnly, Category="AthenaFullScreenMapControlsWidget")
	TSubclassOf<UAthenaConfirmationWindow> ConfirmationWindowClass;

};

