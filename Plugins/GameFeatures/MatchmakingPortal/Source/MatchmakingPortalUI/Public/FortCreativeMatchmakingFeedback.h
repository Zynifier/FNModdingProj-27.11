// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "UIManager/AthenaHUDPrimaryContentInterface.h"
#include "FortCreativeMatchmakingFeedback.generated.h"

class UFortActivityScalingTextBlock;
class UFortCTAButton;
class UFortGameActivity;
class UFortKeybindWidget;
class UInputComponent;
enum class EInGameReadyCheckStatus : uint8;

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortCreativeMatchmakingFeedback : public UCommonActivatableWidget, public IAthenaHUDPrimaryContentInterface
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void BP_OnCreativeReadyCheckStatusChanged(EInGameReadyCheckStatus InGameReadyCheckStatus);

	UFUNCTION(BlueprintPure)
	bool CanCancelMatchmaking() const;

	UFUNCTION(BlueprintPure)
	float GetTimeToDisplayMessageBeforeFadeOut() const;

	UFUNCTION()
	void HandleCancelMatchmaking();

	UFUNCTION()
	void HoldAction();

	UFUNCTION()
	void HoldPressed();

	UFUNCTION()
	void HoldReleased();

	UFUNCTION(BlueprintPure)
	bool IsLocalPlayerReady() const;

	UFUNCTION(BlueprintPure)
	bool IsPartyLeader() const;

	UFUNCTION(BlueprintImplementableEvent)
	void OnCancelNotification();

	UFUNCTION()
	void OnCreativeReadyCheckStatusChanged(EInGameReadyCheckStatus InGameReadyCheckStatus);

	UFUNCTION(BlueprintImplementableEvent)
	void OnLockStateChanged(bool bLockState);

	UFUNCTION(BlueprintImplementableEvent)
	void OnMatchmakingStatusTextUpdated();

	UFUNCTION(BlueprintCallable)
	void OnOutroFinished();

	UFUNCTION(BlueprintImplementableEvent)
	void OnTakeActionNotification();

	UFUNCTION(BlueprintImplementableEvent)
	void OnUserStartedHoldActionNotification();

	UFUNCTION(BlueprintImplementableEvent)
	void PlayIntro();

	UFUNCTION(BlueprintImplementableEvent)
	void PlayOutro();

	UFUNCTION(BlueprintCallable)
	void PopInputComponent();

	UFUNCTION(BlueprintCallable)
	void PushInputComponent();

	UPROPERTY(BlueprintReadOnly, Category="FortCreativeMatchmakingFeedback")
	TObjectPtr<UFortGameActivity> CachedGameActivity;

	UPROPERTY(BlueprintReadOnly, Category="FortCreativeMatchmakingFeedback")
	bool bHasError;

	UPROPERTY(BlueprintReadOnly, Category="FortCreativeMatchmakingFeedback")
	FText MatchmakingStatusText;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortKeybindWidget> Action_HoldKeybindWidget;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortCreativeMatchmakingFeedback", meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UFortCTAButton> Action_MobileButton;

private:
	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UInputComponent> ReadyAndCancelInputComponent;

	UPROPERTY(Export, meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UFortActivityScalingTextBlock> Text_IslandName;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortCreativeMatchmakingFeedback", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UFortActivityScalingTextBlock> Text_MatchmakingStatus;

	UPROPERTY(Transient)
	bool bIsCancelingMatchmaking;

	UPROPERTY(Transient)
	bool bIsLocalPartyMemberReady;

	UPROPERTY(Transient)
	bool bHasPushedInputComponent;

};

