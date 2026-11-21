// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatablePanelLegacy.h"
#include "FortItemQuantityPair.h"
#include "Input/FortSwipeDetector.h"
#include "ItemManagement/FortItemManagementMulchPanel.h"
#include "STW/CollectionBook/FortCollectionBookTypes.h"
#include "FortRewardNotificationWidget.generated.h"

class UFortExpeditionItem;
class UFortItem;
class UFortMulchConfirmationModalWidget;
class UFortQuestItem;
class UFortRewardEpicQuestData;
class UFortRewardExpeditionData;
class UFortRewardGiftBoxData;
class UFortRewardNotificationData;
class UOverlay;

UCLASS(BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortRewardNotificationWidget : public UCommonActivatablePanelLegacy, public IFortItemManagementMulchPanel
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Rewards")
	void BeginCloseRewardsScreen();

	UFUNCTION(BlueprintCallable)
	virtual void HideMulchConfirmationModal();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category="Rewards")
	void InspectItem(UFortItem* ItemToInspect, int32 QuantityOverride = -1);

	UFUNCTION(BlueprintPure, Category="Rewards")
	void IsPrimaryActionEnabled(bool& bEnabled);

	UFUNCTION(BlueprintPure, Category="Rewards")
	void IsPrimaryActionHidden(bool& bHidden);

	UFUNCTION(BlueprintImplementableEvent)
	void OnNavigationDown();

	UFUNCTION(BlueprintImplementableEvent)
	void OnNavigationLeft();

	UFUNCTION(BlueprintImplementableEvent)
	void OnNavigationRight();

	UFUNCTION(BlueprintImplementableEvent)
	void OnNavigationUp();

	UFUNCTION(BlueprintCallable, Category="Rewards")
	void SetPrimaryActionEnabled(bool bEnabled);

	UFUNCTION(BlueprintCallable, Category="Rewards")
	void SetPrimaryActionHidden();

	UFUNCTION(BlueprintCallable, Category="Rewards")
	void SetPrimaryActionText(FText Text);

	UFUNCTION(BlueprintCallable)
	virtual void ShowMulchConfirmationModal();

	UPROPERTY(BlueprintReadOnly, Category="FortRewardNotificationWidget")
	TArray<TObjectPtr<UFortRewardNotificationData>> NotificationDataList;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UOverlay> OverlayMain;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Swipe Detection")
	FFortSwipeDetector SwipeDetector;

protected:
	UFUNCTION(BlueprintCallable, Category="Rewards")
	void AddCollectionBookData(const FFortCollectionBookRewards& CollectionBookRewards);

	UFUNCTION(BlueprintCallable, Category="Rewards")
	void AddDifficultyIncreaseRewardData();

	UFUNCTION(BlueprintCallable, Category="Rewards")
	void AddEpicQuestData(UFortQuestItem* Quest);

	UFUNCTION(BlueprintCallable, Category="Rewards")
	void AddExpeditionData(UFortExpeditionItem* ExpeditionItem);

	UFUNCTION(BlueprintCallable, Category="Rewards")
	void AddGiftBoxData();

	UFUNCTION(BlueprintCallable, Category="Rewards")
	void AddItemCacheRewardData(UFortItem* ItemCache);

	UFUNCTION(BlueprintCallable, Category="Rewards")
	void AddMissionAlertData();

	UFUNCTION(BlueprintCallable, Category="Rewards")
	void AddMissionData();

	UFUNCTION(BlueprintCallable, Category="Rewards")
	void AddPhoenixLevelUpRewardData();

	UFUNCTION(BlueprintCallable, Category="Rewards")
	void AddQuestData(UFortQuestItem* Quest);

	UFUNCTION(BlueprintCallable, Category="Rewards")
	void MarkDefaultItemsForMulch(const TArray<FFortItemInstanceQuantityPair> ItemList);

	UFUNCTION(BlueprintCallable)
	virtual void NotifyPanelActivated();

	UFUNCTION(BlueprintCallable)
	virtual void NotifyPanelDeactivated();

	UFUNCTION(BlueprintImplementableEvent)
	void OnMulchCompleted();

	UFUNCTION(BlueprintImplementableEvent)
	void OnPopulateChoiceRewards(const TArray<FFortItemInstanceQuantityPair>& ItemList);

	UFUNCTION(BlueprintImplementableEvent)
	void OnPopulateExpeditionReward(const UFortRewardExpeditionData* ExpeditionReward);

	UFUNCTION(BlueprintImplementableEvent)
	void OnPopulateGiftBoxReward(const UFortRewardGiftBoxData* GiftBoxReward);

	UFUNCTION(BlueprintImplementableEvent)
	void OnPopulateNewQuestReward(const UFortRewardEpicQuestData* QuestReward);

	UFUNCTION(BlueprintImplementableEvent)
	void OnPrimaryActionDisabled();

	UFUNCTION(BlueprintImplementableEvent)
	void OnPrimaryActionEnabled();

	UFUNCTION(BlueprintImplementableEvent)
	void OnPrimaryActionHidden();

	UFUNCTION(BlueprintImplementableEvent)
	void OnPrimaryActionTextChanged(const FText& Text);

	UFUNCTION(BlueprintImplementableEvent)
	void OnRewardsClaimed(const TArray<FFortItemInstanceQuantityPair>& ItemList);

	UFUNCTION(BlueprintImplementableEvent)
	void OnRewardsClaimFailed();

	UFUNCTION(BlueprintImplementableEvent)
	void OnRewardsScreenClosed();

	UFUNCTION(BlueprintCallable, Category="Rewards")
	void PopulateReward(const UFortRewardNotificationData* Reward);

	UFUNCTION(BlueprintCallable, Category="Rewards")
	void ResetAllRewardData();

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Store Summary")
	TSubclassOf<UFortMulchConfirmationModalWidget> MulchConfirmationModalClass;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UFortMulchConfirmationModalWidget> MulchConfirmationModal;

private:
	UFUNCTION()
	void HandleOnCollectionBookRewardClaimed(FFortCollectionBookRewards RewardClaimed, bool bSuccess, const TArray<FFortItemInstanceQuantityPair>& ActualRewards);

	UFUNCTION()
	void HandleOnDifficultyIncreaseRewardsClaimed(const TArray<FFortItemInstanceQuantityPair>& DifficultyRewards);

	UFUNCTION()
	void HandleOnDifficultyIncreaseRewardsClaimFailed();

	UFUNCTION()
	void HandleOnItemCacheRewardsClaimed(const TArray<FFortItemInstanceQuantityPair>& ClaimedRewards);

	UFUNCTION()
	void HandleOnItemCacheRewardsClaimFailed();

	UFUNCTION()
	void HandleOnMissionAlertRewardsOpened(const TArray<FFortItemInstanceQuantityPair>& AlertRewards);

	UFUNCTION()
	void HandleOnMissionRewardsOpened(const TArray<FFortItemInstanceQuantityPair>& MissionRewards);

	UFUNCTION()
	void HandleOnMissionRewardsOpenFailed();

	UFUNCTION()
	void HandleOnNoQuestRewardsToClaim();

	UFUNCTION()
	void HandleOnQuestRewardClaimed(const UFortQuestItem* Quest, const TArray<FFortItemInstanceQuantityPair>& Rewards);

};

