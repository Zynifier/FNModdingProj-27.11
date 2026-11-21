// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "Misc/Timespan.h"
#include "AthenaKeepPlayingTogetherScreenOverlay.generated.h"

class UAthenaIGMSquadDisplayWidget;
class UCommonButtonBase;
class UCommonTextBlock;
class UCommonWidgetSwitcherLegacy;
class UPanelWidget;

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UAthenaKeepPlayingTogetherScreenOverlay : public UCommonUserWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnExitToLobbyCountdownProgressed(float CountdownValue);

	UFUNCTION(BlueprintImplementableEvent)
	void OnKeepPlayingTogetherScreenOverlayActivated();

	UFUNCTION(BlueprintImplementableEvent)
	void OnKeepPlayingTogetherScreenOverlayDeactivated();

	UFUNCTION(BlueprintImplementableEvent)
	void OnMatchmakingCanceled();

	UFUNCTION(BlueprintImplementableEvent)
	void OnMatchmakingErrorMessage(const FText& Message);

	UFUNCTION(BlueprintImplementableEvent)
	void OnMatchmakingFinished(bool bSuccess);

	UFUNCTION(BlueprintImplementableEvent)
	void OnMatchmakingStarted();

	UFUNCTION(BlueprintImplementableEvent)
	void OnMatchmakingUpdate(FTimespan ElapsedTime);

	UFUNCTION(BlueprintImplementableEvent)
	void OnPreMatchmakingCountdownProgressed();

	UFUNCTION(BlueprintImplementableEvent)
	void OnPreMatchmakingCountdownStarted();

	UFUNCTION(BlueprintImplementableEvent)
	void OnWaitingForSquadMemberVotesCountdownProgressed();

	UFUNCTION(BlueprintImplementableEvent)
	void OnWaitingForSquadMemberVotesCountdownStarted();

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="AthenaKeepPlayingTogetherScreenOverlay")
	float ToLobbyDelayOnError;

private:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_Cancel;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonWidgetSwitcherLegacy> Switcher_MatchmakingStatus;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UPanelWidget> Container_CountdownStatus;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UPanelWidget> Container_FindingMatchStatus;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UPanelWidget> Container_Error;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UPanelWidget> Container_Waiting;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_MatchmakingElapsed;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_CountdownCurrent;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_CountdownNext;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_WaitingForSquadCountdown;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UAthenaIGMSquadDisplayWidget> LocalPlayerSquadDisplayWidget;

};

