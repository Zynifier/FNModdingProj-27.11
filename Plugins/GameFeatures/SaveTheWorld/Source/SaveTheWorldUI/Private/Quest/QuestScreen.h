// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "Engine/DataTable.h"
#include "QuestScreen.generated.h"

class UCommonTreeView;
class UFortQuestItem;
class UFortQuestManagerComponent;
class UScrollBox;

UCLASS(BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortQuestScreen : public UCommonActivatableWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent)
	void BP_SetInitialQuestToSelect(UFortQuestItem* QuestItem);

protected:
	UFUNCTION(BlueprintCallable)
	void AttemptToPlayQuest(UFortQuestItem* QuestItem);

	UFUNCTION(BlueprintImplementableEvent)
	void BP_HandleAbandonQuestAction();

	UFUNCTION(BlueprintImplementableEvent)
	void BP_HandleBackAction();

	UFUNCTION(BlueprintImplementableEvent)
	void BP_HandleClaimRewardAction();

	UFUNCTION(BlueprintImplementableEvent)
	void BP_HandlePinQuestAction();

	UFUNCTION(BlueprintImplementableEvent)
	void BP_HandlePlayQuestAction();

	UFUNCTION(BlueprintImplementableEvent)
	void BP_HandleReplayIntroAction();

	UFUNCTION(BlueprintImplementableEvent)
	void BP_HandleReplayOutroAction();

	UFUNCTION(BlueprintImplementableEvent)
	void BP_HandleStopConversationAction();

	UFUNCTION(BlueprintImplementableEvent)
	void BP_HandleUnpinQuestAction();

	UFUNCTION(BlueprintImplementableEvent)
	void OnContentMissing();

	UFUNCTION(BlueprintCallable)
	void SetDisableClaimRewardButton(bool bToDisable);

	UFUNCTION(BlueprintCallable)
	void SetInputActionStates(const UFortQuestItem* QuestItem, const bool bIsQuestAudioPlaying, const bool bShouldShowPlayQuest, const bool bAreQuestItemsDifferent);

	UFUNCTION(BlueprintCallable)
	void TriggerClaimRewardEvent(const UFortQuestItem* QuestItem);

	UPROPERTY(BlueprintReadOnly, Export, Category="FortQuestScreen", meta=(BindWidget, EditInline="true"))
	UCommonTreeView* TreeView_Quests;

private:
	UFUNCTION(BlueprintCallable, Category="Quest")
	void ProcessPendingSeenQuestItems();

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UScrollBox> ScrollBox_QuestDetails;

	UPROPERTY(EditDefaultsOnly, Category="FortQuestScreen")
	TSubclassOf<UFortQuestManagerComponent> QuestManagerComponentClass;

	UPROPERTY(EditDefaultsOnly, Category="FortQuestScreen")
	FDataTableRowHandle BackAction;

	UPROPERTY(EditDefaultsOnly, Category="FortQuestScreen")
	FDataTableRowHandle LeaveInventoryAction;

	UPROPERTY(EditDefaultsOnly, Category="FortQuestScreen")
	FDataTableRowHandle PlayQuestAction;

	UPROPERTY(EditDefaultsOnly, Category="FortQuestScreen")
	FDataTableRowHandle AbandonQuestAction;

	UPROPERTY(EditDefaultsOnly, Category="FortQuestScreen")
	FDataTableRowHandle ClaimRewardAction;

	UPROPERTY(EditDefaultsOnly, Category="FortQuestScreen")
	FDataTableRowHandle ReplayIntroAction;

	UPROPERTY(EditDefaultsOnly, Category="FortQuestScreen")
	FDataTableRowHandle ReplayOutroAction;

	UPROPERTY(EditDefaultsOnly, Category="FortQuestScreen")
	FDataTableRowHandle PinQuestAction;

	UPROPERTY(EditDefaultsOnly, Category="FortQuestScreen")
	FDataTableRowHandle UnpinQuestAction;

	UPROPERTY(EditDefaultsOnly, Category="FortQuestScreen")
	FDataTableRowHandle StopConversationAction;

};

