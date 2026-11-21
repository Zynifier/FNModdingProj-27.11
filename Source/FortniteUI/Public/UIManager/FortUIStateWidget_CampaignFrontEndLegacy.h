// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortUITypes.h"
#include "UIManager/FortUIStateWidget_NUI.h"
#include "FortUIStateWidget_CampaignFrontEndLegacy.generated.h"

class UCommonWidgetStackLegacy;
class UEnableMultiFactorModal;
class UFortGiftBoxItem;
class UFortItemReceivedScreen;
enum class EFortStoreState : uint8;

UCLASS(MinimalAPI)
class UFortUIStateWidget_CampaignFrontendLegacy : public UFortUIStateWidget_NUI
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintCallable)
	bool AttemptToOpenBattlePassTabForNewSeason();

	UFUNCTION(BlueprintCallable)
	bool CheckForGifts();

	UFUNCTION(BlueprintCallable)
	bool IsOkToCheckForGifts(bool& bTemporary);

	UFUNCTION(BlueprintImplementableEvent)
	void OnMatchmakingV2Changed(bool matchmakingActive);

	UFUNCTION(BlueprintImplementableEvent, meta=(BlueprintProtected="true", DisplayName="On Store State Changed"))
	void OnStoreStateChangedBP(EFortStoreState NewStoreState);

	UFUNCTION(BlueprintCallable)
	void QueueSurvivorSquadsAutoSlottedNotification();

	UFUNCTION(BlueprintCallable)
	bool ShowInitialCrossplayDialog();

	UFUNCTION(BlueprintCallable)
	void TryMFAModal(TSubclassOf<UEnableMultiFactorModal> BPClass);

	UPROPERTY(BlueprintAssignable)
	FBasicDynamicMulticastDelegate OnCrossplayWidgetClosed;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortUIStateWidget_CampaignFrontendLegacy", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonWidgetStackLegacy> MainContentStack;

private:
	UFUNCTION()
	void HandleGiftBoxRemoved(bool bSuccess);

	UFUNCTION()
	void HandleGiftingComplete();

	UFUNCTION()
	void HandleStoreStateChanged(EFortStoreState NewStoreState);

	UFUNCTION(BlueprintCallable)
	void SocialBanModalCheck();

	UPROPERTY(EditAnywhere, Category="FortUIStateWidget_CampaignFrontendLegacy")
	TSubclassOf<UFortItemReceivedScreen> ItemReceivedScreenClass;

	UPROPERTY(Transient)
	TObjectPtr<UFortGiftBoxItem> NextGiftBox;

};

